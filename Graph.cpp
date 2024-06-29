#include "Graph.h"
#include <unordered_map>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iostream>

template<typename T>
void Graph<T>::addNode(Node<T>* node) {
    // Ensure the node is in the adjacency list even if it has no edges yet
    if (adjLists.find(node) == adjLists.end()) {
        adjLists[node] = std::list<Node<T>*>();
    }
}

template<typename T>
void Graph<T>::addEdge(Node<T>* src, Node<T>* dest) {
    // Automatically adds nodes to the graph if they're not already present
    addNode(src);
    addNode(dest);
    adjLists[src].push_back(dest);
    if (!directed) {
        adjLists[dest].push_back(src);
    }
}

template<typename T>
void Graph<T>::deleteEdges(Node<T>* src, std::unordered_map<Node<T>*, bool> visited) {
    std::vector<Node<T>*> edgesArray; //*[4]
    for (auto it = adjLists[src].begin(); it != adjLists[src].end(); ++it) {
        if (!visited[*it]) 
            edgesArray.push_back(*it);
    }
    // printf("\nCurrent Node, %i", src->getData());
    if (!edgesArray.empty())
    {
        int arrayLimit = edgesArray.size();
        Node<T>* node = edgesArray[0];
        //printf("\nNode, %i", node->getData());
        for (int i = 0; i < arrayLimit; i++) {
            // printf("\nEdgesArray[%i], %i", i, edgesArray[i]->getData());
            if (edgesArray[i] != node) {
                adjLists[src].remove(edgesArray[i]);
                adjLists[edgesArray[i]].remove(src);
            }
        }
    }
}

template<typename T>
string Graph<T>::getAlgorithm(){
    return algorithm;
}

template<typename T>
void Graph<T>::DFS(Node<T>* startVertex) {
    std::unordered_map<Node<T>*, bool> visited;
    std::stack<Node<T>*> stack;
    stack.push(startVertex);
    string output;
    while (!stack.empty()) {
        Node<T>* vertex = stack.top();
        stack.pop();

        if (!visited[vertex]) {
            deleteEdges(vertex, visited);
            // for (auto it = adjLists[vertex].rbegin(); it != adjLists[vertex].rend(); ++it) {
            //     Node<T>* node = *it;
            //     printf("\nVertex: %i, Adyacent Node: %i\n", (*vertex).getData(),(*node).getData());
            // }
            std::cout << vertex->getData() << " ";
            visited[vertex] = true;
        }
        for (auto it = adjLists[vertex].rbegin(); it != adjLists[vertex].rend(); ++it) {
            if (!visited[*it]) {
                // Node<T>* node = *it;
                // printf("\nIn Stack Vertex: %i, Adyacent Node: %i\n", (*vertex).getData(),(*node).getData());
                stack.push(*it);
            }
            // Node<T>* node = *it;
            // printf("\nVertex: %i, Adyacent Node: %i\n", (*vertex).getData(),(*node).getData());
        }
        // if (!visited[vertex]) {
        //     Node<T>* nextVertex = stack.top();
        //     deleteEdges(vertex, nextVertex, visited);
        //     for (auto it = adjLists[vertex].rbegin(); it != adjLists[vertex].rend(); ++it) {
        //         Node<T>* node = *it;
        //         printf("\nVertex: %i, Adyacent Node: %i\n", (*vertex).getData(),(*node).getData());
        //     }
        // }
    }
}

template<typename T>
void Graph<T>::BFS(Node<T>* startVertex) {
    std::unordered_map<Node<T>*, bool> visited;
    std::queue<Node<T>*> queue;
    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        Node<T>* vertex = queue.front();
        queue.pop();
        std::cout << vertex->getData() << " ";

        for (Node<T>* neighbor : adjLists[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
        // if (!visited[vertex]) {
        //     Node<T>* nextVertex = queue.front();
        //     deleteEdges(vertex, nextVertex, visited);
        // }
    }
}

template<typename T>
std::unordered_map<Node<T>*, std::list<Node<T>*>> Graph<T>::getAdjList()
{
    return adjLists;
}

template class Graph<int>;  // Explicit template instantiation for int
template class Graph<std::string>;  // Explicit template instantiation for string
