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
        supportMatrix[column] = currentMatrixSize == sizeMatrix - 1;
        if (currentMatrixSize > 2) {

            for (i = 0; i < sizeMatrix - 1; i++) {
                if (i == column && currentMatrixSize != sizeMatrix - 1) {
                    continue;
                }
                supportMatrix[i] = false;
                std::cout << "---------------------------------------------------------------" << std::endl;
                std::cout << "---------------------------------------------------------------" << std::endl;
                std::cout << "matrix[" << row << "][" << i << "]: " << matrix[row + 1][i] << std::endl;
                det += matrix[row][i] * findMinor(matrix, supportMatrix, row + 1, i, currentMatrixSize - 1);
            }
            supportMatrix[column] = true;
        } else {
//            supportMatrix[column] = true;
            double numMatrix[2][2] = {0};
            int iIndex = 0, jIndex = 0, j2Index = 0;
            for (i = sizeMatrix - 2 - 1; i < sizeMatrix - 1; i++) {
                for (j = 0; j < sizeMatrix - 1; j++) {
                    if (supportMatrix[j] == true) {
//                        numMatrix[iIndex][jIndex] = matrix[iIndex][j2Index];
                        numMatrix[iIndex][jIndex] = matrix[i][j];
                        jIndex++;
//                        j2Index++;
                    }
                }
//                j2Index = 0;
                jIndex = 0;
                iIndex++;
            }
            print1DArray<bool>(
                    "findMinor(double **matrix, bool *supportMatrix, int row, int column, int currentMatrixSize): supportMatrix",
                    supportMatrix, sizeMatrix - 1);
            std::cout << "numMatrix: " << std::endl;
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
//        print2DArray<T>("getAdjSupport(double **adj, int *row, int *column): adj", adj, sizeMatrix);
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
        std::cout << "---------------------------------------------------------------" << std::endl;
        print2DArray<double>("getAdjSupport(double **adj, int *row, int *column): adjSupport: ", adjSupport,
                             sizeMatrix - 1);
        return adjSupport;
    }

    void multipleMatrix(double **matrix, int row, double k) {
        std::cout << "k: " << k << std::endl;
        for (int j = 0; j < sizeMatrix; j++) {
            matrix[row][j] *= k;
        }
    }

    void subtractMatrix(double **matrix, int row, double k) {
        for (int j = 0; j < sizeMatrix; j++) {
            matrix[row][j] -= k;
        }
    }

public:

    void inverse() {
        int i = 0, j = 0, factor = 0;
        double det = 0;
        double **result = new double *[sizeMatrix];
        bool *supportMatrix = new bool[sizeMatrix - 1];
        double **adj = new double *[sizeMatrix];
        double **adjSupport;

        for (int i = 0; i < sizeMatrix - 1; i++) {
            supportMatrix[i] = true;
        }

        for (i = 0; i < sizeMatrix; i++) {
            result[i] = new double[sizeMatrix];
//            supportMatrix[i] = true;
            adj[i] = new double[sizeMatrix];
//            supportMatrix[i] = true;
            for (j = 0; j < sizeMatrix; j++) {
                adj[i][j] = this->a[i][j];
            }
        }
        i = 0;
//        for (j = 0; j < sizeMatrix; j++) {
//            adjSupport = getAdjSupport(a, &i, &j);
//            factor = (0 + j) % 2 == 0 ? 1 : -1;
//            det += this->a[0][j] * factor * findMinor(adjSupport, supportMatrix, 0 + 1, j, sizeMatrix - 1);
//        }
        det = 1;
        std::cout << "det: " << det << std::endl;
        if (det == 0) {
            std::cerr << "det == 0. Operation prohibited" << std::endl;
        }

        for (i = 0; i < sizeMatrix; i++) {
            for (j = 0; j < sizeMatrix; j++) {
                adjSupport = getAdjSupport(a, &i, &j);
                factor = (i + j) % 2 == 0 ? 1 : -1;
                adj[i][j] = factor * findMinor(adjSupport, supportMatrix, i + 1, j, sizeMatrix - 1);
//                adj[i][j] /= det;
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

    void secondMethodInverse() {
        double **rightMatrix = new double *[sizeMatrix];
        double **cloneMatrix = new double *[sizeMatrix];
        double factor = 0;
        int i = 0, j = 0, k = 0;

        for (i = 0; i < sizeMatrix; i++) {
            rightMatrix[i] = new double[sizeMatrix];
            cloneMatrix[i] = new double[sizeMatrix];
            for (j = 0; j < sizeMatrix; j++) {
                rightMatrix[i][j] = i == j ? 1 : 0;
                cloneMatrix[i][j] = a[i][j];
            }
        }
//        print2DArray("cloneMatrix: ", cloneMatrix, sizeMatrix);
        double denomenator = 1 / cloneMatrix[0][0];
        multipleMatrix(cloneMatrix, 0, denomenator);
        multipleMatrix(rightMatrix, 0, denomenator);
        cloneMatrix[0][0] = 1;
//        print2DArray("rightMatrix: ", rightMatrix, sizeMatrix);
        printTwoArrays("", cloneMatrix, rightMatrix, sizeMatrix);

        for (j = 0; j < sizeMatrix - 1; j++) {
            for (i = j + 1; i < sizeMatrix; i++) {
                if (cloneMatrix[j][j] == 0 || cloneMatrix[i][j] == 0) {
                    continue;
                }

                factor = cloneMatrix[i][j] / cloneMatrix[j][j];
                std::cout << "i: " << i << " | j: " << j << " | factor: " << factor << std::endl;
//                actions with clone matrix:
                multipleMatrix(cloneMatrix, i, 1 / factor);

//                actions with single matrix:
                multipleMatrix(rightMatrix, i, 1 / factor);
                for (k = 0; k < sizeMatrix; k++) {
                    cloneMatrix[i][k] -= cloneMatrix[j][k];
                    rightMatrix[i][k] -= rightMatrix[j][k];
                }
                std::cout << "--------------------------------------" << std::endl;
                std::cout << "--------------------------------------" << std::endl;
//                print2DArray("cloneMatrix: ", cloneMatrix, sizeMatrix);
//                print2DArray("rightMatrix: ", rightMatrix, sizeMatrix);
                printTwoArrays("", cloneMatrix, rightMatrix, sizeMatrix);
            }

            multipleMatrix(cloneMatrix, j + 1, 1 / cloneMatrix[j + 1][j + 1]);
            multipleMatrix(rightMatrix, j + 1, 1 / cloneMatrix[j + 1][j + 1]);

//            print2DArray("cloneMatrix: ", cloneMatrix, sizeMatrix);
//            print2DArray("rightMatrix: ", rightMatrix, sizeMatrix);
            printTwoArrays("", cloneMatrix, rightMatrix, sizeMatrix);
            std::cout << "--------------------------------------" << std::endl;
            std::cout << "--------------------------------------" << std::endl;
        }


        for (i = 1; i < sizeMatrix; i++) {
            for (j = 0; j < i; j++) {
                cloneMatrix[i][j] = 0;
            }
        }
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        printTwoArrays("", cloneMatrix, rightMatrix, sizeMatrix);
//        print2DArray("cloneMatrix: ", cloneMatrix, sizeMatrix);
//        print2DArray("rightMatrix: ", rightMatrix, sizeMatrix);
        std::cout << "Above main diagonal: " << std::endl;

        for (j = 1; j < sizeMatrix; j++) {
            for (i = 0; i < j; i++) {
                factor = cloneMatrix[i][j];

                for (k = 0; k < sizeMatrix; k++) {
                    cloneMatrix[i][k] -= cloneMatrix[j][k] * factor;
                    rightMatrix[i][k] -= rightMatrix[j][k] * factor;
                }
                std::cout << "j: " << j << std::endl;
                printTwoArrays("", cloneMatrix, rightMatrix, sizeMatrix);
//                print2DArray("cloneMatrix: ", cloneMatrix, sizeMatrix);
//                print2DArray("rightMatrix: ", rightMatrix, sizeMatrix);
                std::cout << "--------------------------------------" << std::endl;
                std::cout << "--------------------------------------" << std::endl;
            }
        }


        print2DArray("right matrix: ", rightMatrix, sizeMatrix);

        for (i = 0; i < sizeMatrix; i++) {
            delete[] rightMatrix[i];
            delete[] cloneMatrix[i];
        }

        delete[] rightMatrix;
        delete[] cloneMatrix;
    }

    template<typename K>
    void print2DArray(const std::string &messege, K **array2D, int arrSize) {
        std::cout << messege << std::endl;
        for (int i = 0; i < arrSize; i++) {
            for (int j = 0; j < arrSize; j++) {
                std::cout << std::fixed;
                std::cout.setf(std::ios::right);
                std::cout.width(10);
                std::cout.precision(5);
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

    template<typename K>
    void printTwoArrays(const std::string &messege, K **arrayLhs, K **arrayRhs, int arrSize) {
        std::cout << messege << std::endl;
        for (int i = 0; i < arrSize; i++) {
            for (int j = 0; j < arrSize; j++) {
                std::cout << std::fixed;
                std::cout.setf(std::ios::right);
                std::cout.width(10);
                std::cout.precision(5);
                std::cout << arrayLhs[i][j] << " ";
            }

            std::cout << "|";
            for (int j = 0; j < arrSize; j++) {
                std::cout << std::fixed;
                std::cout.setf(std::ios::right);
                std::cout.width(10);
                std::cout.precision(5);
                std::cout << arrayRhs[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif //LAB1_NEW_LIFE_BIGMATRIX_H
