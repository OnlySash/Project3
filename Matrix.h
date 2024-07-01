#ifndef MATRIX_H
#define MATRIX_H
#include "Graph.h"
#include <string> 
class Matrix{
private:
    Graph<int> intGraph;
    Node<int>** boardMatrix = new Node<int>*[10];
    void matrixInitializer();
    void fillMatrix();
public:
    Matrix();
    void printMatrix();
    void connectNodes();
};

#include "Matrix.cpp"

#endif 