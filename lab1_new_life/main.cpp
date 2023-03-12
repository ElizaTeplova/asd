#include <iostream>
#include "Matrix/Matrix.h"

int main() {
    int i, j, k;
    int arrayInt[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 2, 9}
    };
//    int*[] ptrIntArray = arrayInt;
    int **pArrayInt = new int *[3];
    double **pArrayDouble = new double *[3];
    float **pArrayFloat = new float *[3];

    for (k = 0; k < 3; k++) {
        pArrayInt[k] = new int[3];
        pArrayDouble[k] = new double[3];
        pArrayFloat[k] = new float[3];
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            pArrayInt[i][j] = arrayInt[i][j];
            pArrayDouble[i][j] = arrayInt[i][j];
            pArrayFloat[i][j] = arrayInt[i][j];
//            std::cout<<pArrayInt[i][j];
        }
    }

    Matrix<int> intMatrix(pArrayInt);
    Matrix<double> doubleMatrix(pArrayDouble);
    Matrix<float> floatMatrix(pArrayFloat);
//    std::cout << intMatrix;
//    std::cout << doubleMatrix;
//    std::cout << floatMatrix;

//    std::cout<<"detIntMatrix: " << intMatrix.det3By3(pArrayInt);
    intMatrix.inverse();
    doubleMatrix.inverse();
    floatMatrix.inverse();

    for (i = 0; i < 3; i++) {
        delete[] pArrayInt[i];
        delete[] pArrayDouble[i];
        delete[] pArrayFloat[i];
    }
    delete[] pArrayInt;
    delete[] pArrayDouble;
    delete[] pArrayFloat;
}
