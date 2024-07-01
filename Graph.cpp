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
void Graph<T>::deleteEdges(Node<T>* src, std::unordered_map<Node<T>*, bool>& visited) {
    std::vector<Node<T>*> edgesToRemove;
    for (auto it = adjLists[src].begin(); it != adjLists[src].end(); ++it) {
        if (!visited[*it]) {
            edgesToRemove.push_back(*it);
        }
    }
    for (Node<T>* neighbor : edgesToRemove) {
        if(neighbor != edgesToRemove[0]){
            adjLists[src].remove(neighbor);
            adjLists[neighbor].remove(src);
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

    std::random_device rd;
    std::mt19937 g(rd());

    while (!stack.empty()) {
        Node<T>* vertex = stack.top();
        stack.pop();

        if (!visited[vertex]) {
            visited[vertex] = true;
            deleteEdges(vertex, visited);
            std::cout << vertex->getData() << " ";

            // Obtener vecinos en un orden aleatorio
            std::vector<Node<T>*> neighbors(adjLists[vertex].begin(), adjLists[vertex].end());
            std::shuffle(neighbors.begin(), neighbors.end(), g);

            // Agregar vecinos no visitados a la pila
            for (Node<T>* neighbor : neighbors) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                }
            }
        }
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
