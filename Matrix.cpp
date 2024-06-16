#include "Matrix.h"
const int matSize = 3;

Matrix::Matrix(){
    matrixInitializer();
    fillMatrix();
}

void Matrix::matrixInitializer(){
    for (int i = 0; i < matSize; i++)
    {
        boardMatrix[i] = new Node<int>[matSize];
    }
}

void Matrix::fillMatrix(){
    int counter = 1;
    for (int i = 0; i < matSize; i++)
    {
        for (int j = 0; j < matSize; j++)
        {
            boardMatrix[i][j] = Node<int>(counter++);
        }
    }
}

void Matrix::printMatrix(){
    for (int i = 0; i < matSize; i++)
    {
        for (int j = 0; j < matSize; j++)
        {
            printf("%i ", boardMatrix[i][j].getData());
        }
        printf("\n");
    }
}

//Generate fully connected graph
void Matrix::connectNodes(){
    for (int i = 0; i<matSize; i++)
        for (int j = 0; j<matSize; j++)
        {
            //Direction up
            if (i-1 >= 0){
                intGraph.addEdge(&boardMatrix[i][j], &boardMatrix[i-1][j]);
            }
            //Direction right
            if (j+1 < matSize){
                intGraph.addEdge(&boardMatrix[i][j], &boardMatrix[i][j+1]);
            }
            //Direction down
            if (i+1 < matSize){
                intGraph.addEdge(&boardMatrix[i][j], &boardMatrix[i+1][j]);
            }
            //Direction left
            if (j-1 >= 0){
                intGraph.addEdge(&boardMatrix[i][j], &boardMatrix[i][j-1]);
            }
        }
    std::cout << "DFS for int graph: ";
    intGraph.DFS(&boardMatrix[0][0]);
    std::cout << "\nBFS for int graph: ";
    intGraph.BFS(&boardMatrix[0][0]);
    std::cout << std::endl;        
}