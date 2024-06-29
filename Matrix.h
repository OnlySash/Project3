#ifndef MATRIX_H
#define MATRIX_H
#include "Graph.h"
#include <string>
#include <unordered_map>
#include <iostream>
class Matrix{
private:
    int rows = 0;
    int cols = 0;
    Node<int>* currentNode;
    list<Node<int>*> currentAdjList;
    Graph<int> intGraph;
    void matrixInitializer();
    void fillMatrix();
public:
    Matrix();
    Matrix(int laberynthHeight, int laberynthWidth);
    Node<int>** boardMatrix;
    void printMatrix();
    void connectNodes();
    void applySearchAlgorithm();
    void updateCurrentNode(int row, int col);
    int getCurrentNode(int row, int col);
    int getNodePath(int row, int col);
};

#include "Matrix.cpp"

#endif 
