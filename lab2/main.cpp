#include <iostream>
#include <ctime>
#include "Matrix/Matrix.h"
#include "Matrix/BigMatrix.h"

int main() {
    int i, j, k;
    int arrayInt[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 2, 9}
    };
    int **pArrayInt = new int *[3];
    for (k = 0; k < 3; k++) {
        pArrayInt[k] = new int[3];
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            pArrayInt[i][j] = arrayInt[i][j];
        }
    }
    BigMatrix<int> bigMatrix(pArrayInt, 3);
    bigMatrix.inverse();
//    int testSize;
//    int** intRandMatrix = nullptr;
//    std::srand(std::time(nullptr)); // use current time as seed for random generator
//    std::cout << "Enter matrix size: ";
//    std::cin >> testSize;
//    std::cout<< "the next matrix size will be: " << testSize << std::endl;
//
//
//    intRandMatrix = new int*[testSize];
//    for (i = 0; i < testSize; i++) {
//        intRandMatrix[i] = new int[testSize];
//
//        for (j = 0; j < testSize; j++) {
//            intRandMatrix[i][j] = std::rand() % 10;
//            std::cout << intRandMatrix[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }

//    BigMatrix<int> bigMatrixInt(intRandMatrix, testSize);
//    std::cout << bigMatrixInt;

//    for (i = 0; i < testSize; i++) {
//        delete[] intRandMatrix[i];
//    }
//    delete[] intRandMatrix;

}
