//
// Created by mrbab on 12.03.2023.
//

#ifndef LAB1_NEW_LIFE_BIGMATRIX_H
#define LAB1_NEW_LIFE_BIGMATRIX_H

#include <cmath>
#include<iostream>

template<typename T>
class BigMatrix {

private:
    T **a = nullptr;
    int sizeMatrix = 0;


    double findMinor(double **matrix, bool *supportMatrix, int row, int column, int currentMatrixSize) {

        int i = 0, j = 0;
        double det = 0;
        if (currentMatrixSize == 0) {
            std::cerr << "currentMatrixSize == 0: return 0!" << std::endl;
            return 0;
        }
        supportMatrix[column] = false;
        if (currentMatrixSize > 2) {

            for (i = 0; i < sizeMatrix; i++) {
                if (i == column) {
                    continue;
                }
                det += matrix[row + 1][i] * findMinor(matrix, supportMatrix, row + 1, i, currentMatrixSize - 1);
                for (i = 0; i < sizeMatrix; i++) {
                    supportMatrix[column] = true;
                }
            }
        } else {
            double numMatrix[2][2] = {0};
            int iIndex = 0, jIndex = 0, j2Index = 0;
            for (i = sizeMatrix - 2; i < sizeMatrix; i++) {
                for (j = 0; j < sizeMatrix; j++) {
                    if (supportMatrix[j] == true) {
                        numMatrix[iIndex][jIndex] = matrix[iIndex][j2Index];
                        jIndex++;
                        j2Index++;
                    }
                }
                j2Index = 0;
                jIndex = 0;
                iIndex++;
            }
            std::cout << "numMatrix" << std::endl;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    std::cout << std::fixed;
                    std::cout.setf(std::ios::right);
                    std::cout.width(3);
                    std::cout.precision(1);
                    std::cout << numMatrix[i][j] << " ";
                }
                std::cout << std::endl;
            }
            print1DArray<bool>(
                    "findMinor(double **matrix, bool *supportMatrix, int row, int column, int currentMatrixSize): supportMatrix",
                    supportMatrix, sizeMatrix);
            supportMatrix[column] = true;
//            print2DArray<double>("findMinor(double **matrix, bool *supportMatrix, int row, int column, int currentMatrixSize): numMatrix", (double **)numMatrix, sizeMatrix);
//            for (i = 0; i < sizeMatrix; i++) {
//                supportMatrix[column] = false;
//            }
            double res = numMatrix[0][0] * numMatrix[1][1] - numMatrix[1][0] * numMatrix[0][1];
            std::cout << "res: " << res << std::endl;
            return res;
//            return numMatrix[0][0] * numMatrix[1][1] - numMatrix[1][0] * numMatrix[0][1];
        }

    }

    double **getAdjSupport(T **adj, int *row, int *column) {
        int iIndex = 0, jIndex = 0, i = 0;
        static double **adjSupport = new double *[sizeMatrix - 1];
        for (i = 0; i < sizeMatrix - 1; i++) {
            adjSupport[i] = new double[sizeMatrix - 1];
        }
        print2DArray<T>("getAdjSupport(double **adj, int *row, int *column): adj", adj, sizeMatrix);
//        static double adjSupport[sizeMatrix - 1][sizeMatrix - 1];
        for (i = 0; i < sizeMatrix; i++) {
            if (i == *row) {
                continue;
            }
            for (int j = 0; j < sizeMatrix; j++) {
                if (j == *column) {
                    continue;
                }
                adjSupport[iIndex][jIndex] = adj[i][j];
                jIndex++;
            }
            jIndex = 0;
            iIndex++;
        }

        print2DArray<double>("getAdjSupport(double **adj, int *row, int *column): adjSupport: ", adjSupport,
                             sizeMatrix - 1);
        return adjSupport;
    }

public:

    void inverse() {
        int i = 0, j = 0, factor = 0;
        double det = 0;
        double** result = new double*[sizeMatrix];
        bool *supportMatrix = new bool[sizeMatrix];
        double **adj = new double *[sizeMatrix];
        double **adjSupport;

        for (i = 0; i < sizeMatrix; i++) {
            result[i] = new double[sizeMatrix];
            supportMatrix[i] = true;
            adj[i] = new double[sizeMatrix];
//            supportMatrix[i] = true;
            for (j = 0; j < sizeMatrix; j++) {
                adj[i][j] = this->a[i][j];
            }
        }
        i = 0;
        for (j = 0; j < sizeMatrix; j++) {
            adjSupport = getAdjSupport(a, &i, &j);
            factor = (0 + j) % 2 == 0 ? 1 : -1;
            det += this->a[0][j] * factor * findMinor(adjSupport, supportMatrix, 0 + 1, j, sizeMatrix - 1);
        }
        std::cout << "det: " << det << std::endl;
        if (det == 0) {
            std::cerr << "det == 0. Operation prohibited" << std::endl;
        }

        for (i = 0; i < sizeMatrix; i++) {
            for (j = 0; j < sizeMatrix; j++) {
                adjSupport = getAdjSupport(a, &i, &j);
                factor = (i + j) % 2 == 0 ? 1 : -1;
                adj[i][j] = factor * findMinor(adjSupport, supportMatrix, i + 1, j, sizeMatrix - 1);
                adj[i][j] /= det;
                result[j][i] = adj[i][j];
            }
        }
        print2DArray<double>("inverse(): result: ", result, sizeMatrix);


        for (i = 0; i < sizeMatrix; i++) {
            delete[] adj[i];
        }
        delete[] adj;
        delete[] supportMatrix;
    }

    BigMatrix(T **matrix, int size) {
        int i = 0, j = 0;
        sizeMatrix = size;
        std::cout << "Matrix size: " << sizeMatrix << std::endl;
        this->a = (T **) new T *[sizeMatrix];


        for (i = 0; i < sizeMatrix; i++) {
            this->a[i] = (T *) new T[sizeMatrix];
            for (j = 0; j < sizeMatrix; j++) {
                this->a[i][j] = matrix[i][j];
            }
        }
    }

    virtual ~BigMatrix() {

        for (int i = 0; i < sizeMatrix; i++) {
            delete[] this->a[i];
        }
        delete[] this->a;
    }

    friend std::ostream &operator<<(std::ostream &stream, BigMatrix<T> &matrix) {
        for (int i = 0; i < matrix.sizeMatrix; i++) {
            for (int j = 0; j < matrix.sizeMatrix; j++) {
                stream << std::setw(3) << matrix.a[i][j];
            }
            stream << std::endl;
        }
        return stream;
    }

    template<typename K>
    void print2DArray(const std::string &messege, K **array2D, int arrSize) {
        std::cout << messege << std::endl;
        for (int i = 0; i < arrSize; i++) {
            for (int j = 0; j < arrSize; j++) {
                std::cout << std::fixed;
                std::cout.setf(std::ios::right);
                std::cout.width(5);
                std::cout.precision(3);
                std::cout << array2D[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    template<typename K>
    void print1DArray(const std::string &messege, K *array1D, int arrSize) {
        std::cout << messege << std::endl;
        for (int i = 0; i < arrSize; i++) {

            std::cout << std::fixed;
            std::cout.setf(std::ios::right);
            std::cout.width(5);
//            std::cout.precision(1);
            std::cout << array1D[i] << " ";

        }
        std::cout << std::endl;
    }
};

#endif //LAB1_NEW_LIFE_BIGMATRIX_H
