#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <stack>
#include <ctime>
#include <chrono>
#include <thread>
#include <string>
#include <algorithm>
#include <random>
using namespace std;

template<typename T>
class Graph {
private:
    std::unordered_map<Node<T>*, std::list<Node<T>*>> adjLists;
    bool directed;
    const string algorithm = "DFS";
public:
    Graph(bool isDirected = true) : directed(isDirected) {}
    void addNode(Node<T>* node);  // To add nodes explicitly if needed
    void addEdge(Node<T>* src, Node<T>* dest);
    void deleteEdges(Node<T>* src, std::unordered_map<Node<T>*, bool>& visited);
    string getAlgorithm();
    std::unordered_map<Node<T>*, std::list<Node<T>*>> getAdjList();
    void DFS(Node<T>* startVertex);
    void BFS(Node<T>* startVertex);
};

#include "Graph.cpp"

#endif // GRAPH_H
