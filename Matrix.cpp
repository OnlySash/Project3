#include "Matrix.h"

Matrix::Matrix(int laberynthHeight, int laberynthWidth){
    rows = laberynthHeight;
    cols = laberynthWidth;
    matrixInitializer();
    fillMatrix();
}

void Matrix::matrixInitializer(){
    boardMatrix = new Node<int>*[rows];
    for (int i = 0; i < rows; i++)
    {
        boardMatrix[i] = new Node<int>[cols];
    }
}

void Matrix::fillMatrix(){
    int counter = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            boardMatrix[i][j] = Node<int>(counter++);
        }
    }
}

void Matrix::printMatrix(){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%i ", boardMatrix[i][j].getData());
        }
        printf("\n");
    }
}

//Generate fully connected graph
void Matrix::connectNodes(){
    for (int i = 0; i<rows; i++)
        for (int j = 0; j<cols; j++)
        {
            //Direction up
            if (i-1 >= 0){
                intGraph.addEdge(&boardMatrix[i][j], &boardMatrix[i-1][j]);
            }
            //Direction right
            if (j+1 < cols){
                intGraph.addEdge(&boardMatrix[i][j], &boardMatrix[i][j+1]);
            }
            //Direction down
            if (i+1 < rows){
                intGraph.addEdge(&boardMatrix[i][j], &boardMatrix[i+1][j]);
            }
            //Direction left
            if (j-1 >= 0){
                intGraph.addEdge(&boardMatrix[i][j], &boardMatrix[i][j-1]);
            }
        }
}

void Matrix::applySearchAlgorithm()
{
    if (intGraph.getAlgorithm() == "DFS")
    {
        std::cout << "DFS for int graph: ";
        intGraph.DFS(&boardMatrix[0][0]);
    }
    else if (intGraph.getAlgorithm() == "BFS")
    {
        std::cout << "\nBFS for int graph: ";
        intGraph.BFS(&boardMatrix[0][0]);
    }
    std::cout << std::endl;
}

void Matrix::updateCurrentNode(int row, int col)
{
    currentNode = &boardMatrix[row][col];
    currentAdjList = intGraph.getAdjList()[currentNode];
}

int Matrix::getCurrentNode(int row, int col)
{
    return boardMatrix[row][col].getData();
}

//Evaluate node connections
int Matrix::getNodePath(int row, int col)
{
    //printf("Current Node: %i\n", boardMatrix[row][col]);
    if (!currentAdjList.empty())
    {
        Node<int>* adjacentNode = currentAdjList.front();
        //printf("Adyacent Node: %i\n", adjacentNode->getData());
        currentAdjList.remove(adjacentNode);
        if (row-1 >= 0)
        {
            Node <int>* aboveNode = &boardMatrix[row-1][col];
            if (aboveNode == adjacentNode)
                return 0; //Above
        }
        if (col+1 < cols)
        {
            Node <int>* rightNode = &boardMatrix[row][col+1];
            if (rightNode == adjacentNode)
                return 1; //Right
        }
        if (row+1 < rows)
        {
            Node <int>* belowNode = &boardMatrix[row+1][col];
            if (belowNode == adjacentNode)
                return 2; //Below
        }
        if (col-1 >= 0)
        {
            Node <int>* leftNode = &boardMatrix[row][col-1];
            if (leftNode == adjacentNode)
                return 3; //Left
        }
    }
    return -1;
}
