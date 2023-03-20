#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
#include "Matrix/Matrix.h"
#include "Matrix/BigMatrix.h"

int main() {
    int i, j, k;
//    int arrayInt[3][3] = {
//            {1, 2, 1},
//            {0, 1, 0},
//            {0, 2, 2}
//    };
//    int **pArrayInt = new int *[3];
//    for (k = 0; k < 3; k++) {
//        pArrayInt[k] = new int[3];
//    }
//    for (i = 0; i < 3; i++) {
//        for (j = 0; j < 3; j++) {
//            pArrayInt[i][j] = arrayInt[i][j];
//        }
//    }
//    BigMatrix<int> bigMatrix(pArrayInt, 3);
//    auto start = std::chrono::system_clock::now();
//    bigMatrix.secondMethodInverse();
//    auto  end = std::chrono::system_clock::now();
//    std::chrono::duration<double> elapsed_seconds = end-start;
//    std::cout << "duration method: " << elapsed_seconds.count() << "s" << std::endl;
//
//    for (j = 0; j < 3; j++) {
//        delete[] pArrayInt[i];
//    }
//    delete[] pArrayInt;

    int testSize;
    double **int1000RandMatrix = nullptr;

    std::srand(std::time(nullptr)); // use current time as seed for random generator
//    std::cout << "Enter matrix size: ";
    testSize = 1000;
//    std::cin >> testSize;
//    std::cout<< "the next matrix size will be: " << testSize << std::endl;

    std::ofstream file;
    file.open(R"(C:\textbooks\labs\asd\practice\lab2\resultPoints.txt)", std::ios::out | std::ios::app);

    if (!file.is_open()) {
        std::cerr << "File wasn't opened. Exit!" << std::endl;
        return 0;
    }

    int1000RandMatrix = new double *[testSize];

    for (i = 0; i < testSize; i++) {
        int1000RandMatrix[i] = new double [testSize];

        for (j = 0; j < testSize; j++) {
            int1000RandMatrix[i][j] = std::rand() % 1000;
//            std::cout << int1000RandMatrix[i][j] << " ";
        }
//        std::cout << std::endl;
    }

    std::cout << "Matrix initialization :" << std::endl;
    BigMatrix<double> bigMatrixInt1000(int1000RandMatrix, testSize);



//    std::cout << bigMatrixInt1000;
    auto start = std::chrono::system_clock::now();
    bigMatrixInt1000.secondMethodInverse();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout.setf(std::ios_base::left);
    std::cout.precision(5);
    std::cout << std::setw(7) << testSize << "   " << std::setw(10) << elapsed_seconds.count() << std::endl;
    file << std::setw(7) << testSize << "   " << std::setw(10) << elapsed_seconds.count() << std::endl;


    for (i = 0; i < testSize; i++) {
        delete[] int1000RandMatrix[i];
    }
    delete[] int1000RandMatrix;

}
