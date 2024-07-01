#include "Matrix.h"
#include <iostream>

int main() {
    for (int i = 0; i<4; i++)
    {
        // Integer graph
        Matrix m;
        m.printMatrix();
        printf("\n");
        m.connectNodes();
    }

    return 0;
}