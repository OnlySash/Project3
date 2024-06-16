#include "Graph.h"
#include <cstdlib>

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
void Graph<T>::deleteEdge(Node<T>* src, std::unordered_map<Node<T>*, bool> visited) {
    srand(time(0));
    int edgesCounter = 0;
    Node<T>** edgesArray = new Node<T>*[4];
    for (auto it = adjLists[src].rbegin(); it != adjLists[src].rend(); ++it) {
        if (!visited[*it])
        {
            Node<T>* node = *it;
            edgesArray[edgesCounter] = node;
            edgesCounter++;
        }
    }
    if (edgesCounter >= 2) //edgesArray.size()
    {
        int randomNumber = rand() % edgesCounter;
        for (int i = 0; i<edgesCounter; i++)
        {
            if (i != randomNumber)
            {
                adjLists[src].remove((edgesArray)[i]);
                adjLists[(edgesArray)[i]].remove(src);
            }
        }
    }  
    delete [] edgesArray;
    this_thread::sleep_for(chrono::seconds(1));
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
            std::cout << vertex->getData() << " ";
            visited[vertex] = true;
        }
        deleteEdge(vertex, visited);
        for (auto it = adjLists[vertex].rbegin(); it != adjLists[vertex].rend(); ++it) {
            if (!visited[*it]) {
                stack.push(*it);
            }
            // Node<T>* node = *it;
            // printf("\nVertex: %i, Adyacent Node: %i\n", (*vertex).getData(),(*node).getData());
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
    }
}

template class Graph<int>;  // Explicit template instantiation for int
template class Graph<std::string>;  // Explicit template instantiation for string