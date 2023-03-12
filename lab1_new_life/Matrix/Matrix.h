//
// Created by mrbab on 26.02.2023.
//

#ifndef LAB1_NEW_LIFE_MATRIX_H
#define LAB1_NEW_LIFE_MATRIX_H

#include <iostream>
#include <iomanip>

template<typename T>
class Matrix {

private:
    T **a;
public:
    static const int size = 3;

    explicit Matrix(T **a) {
        int i, j;
        this->a = (T **) new T *[size];
        for (i = 0; i < size; i++) {
            this->a[i] = (T *) new T[size];
            for (j = 0; j < size; j++) {
                this->a[i][j] = a[i][j];
            }
        }
    }

    friend std::ostream &operator<<(std::ostream &stream, Matrix<T> &matrix) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                stream << std::setw(3) << matrix.a[i][j];
            }
            stream << std::endl;
        }
        return stream;
    }


    void inverse() {
        double **adj;
        double det = det3By3(a);
        int i, j;
        if (det == 0) {
            std::cout << "det eq 0! Operation prohibited";
            return;
        }


        adj = findAdj(a);
        std::cout<<"inversed matrix:" <<std::endl;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; ++j) {
                std::cout<<std::fixed;
                std::cout.setf(std::ios::right);
                std::cout.width(7);
                std::cout.precision(4);
                std::cout << adj[i][j] / det << "  ";
            }
            std::cout << std::endl;
        }
        for (i = 0; i < 3; i++) {
            delete[] adj[i];
        }
        delete[] adj;
    }

    double **findAdj(T **matrix) {
        double **adj = new double *[3];
        double **cofactor = new double *[3];
        int factor = 0;
        int i, j;

        for (i = 0; i < size; i++) {
            adj[i] = new double[3];
            cofactor[i] = new double[3];
            for (j = 0; j < size; j++) {
                factor = (i + j) % 2 == 0 ? 1 : -1;
                cofactor[i][j] = factor * det2By2(get2By2Matrix(matrix, i, j));
//                std::cout << "cofactor[" << i << "][" << j << "]: " << cofactor[i][j] << "  ";
            }
//            std::cout << std::endl;
        }

        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                adj[i][j] = cofactor[j][i];
//                std::cout << "adj[" << i << "][" << j << "]: " << adj[i][j] << "  ";
            }
//            std::cout << std::endl;
        }

        for (i = 0; i < 3; i++) {
            delete[] cofactor[i];
        }
        delete[] cofactor;

        return adj;
    }

    double det3By3(T **matrix3By3) {
        double det = 0;
        int j = 0;
        int factor = 0;
        T **detMatrix;

        for (j = 0; j < size; j++) {
            detMatrix = get2By2Matrix(this->a, 0, j);
            factor = j % 2 == 0 ? 1 : -1;
//            std::cout << "results: " << detMatrix[0][0] << " " << detMatrix[0][1] << " " << detMatrix[1][0] << " "
//                      << detMatrix[1][1] << std::endl;
//            std::cout << "det: " << det2By2(detMatrix) << std::endl;
//            std::cout << "factor: " << factor << std::endl;
            det += factor * a[0][j] * det2By2(detMatrix);
//            std::cout << "current det: " << det << std::endl;
            delete[] detMatrix;
        }
        return det;
    }

private:
    constexpr static const double eps = 1e-10;

    T **get2By2Matrix(T **matrix, int row, int column) {
        T **matrix2By2 = (T **) new T *[2];
//        T (*matrix2By2)[2];
//        matrix2By2 = new T[2][2];
        int i, j;
        int iIndex = 0, jIndex = 0;

        for (i = 0; i < size; i++) {
            if (i == row) {
                continue;
            }
            jIndex = 0;
            matrix2By2[iIndex] = new T[2];
            for (j = 0; j < size; j++) {
                if (j == column) {
                    continue;
                }
                matrix2By2[iIndex][jIndex] = matrix[i][j];
//                std::cout << "matrix2By2[" << iIndex << "][" << jIndex << "]: " << matrix2By2[iIndex][jIndex]
//                          << std::endl;
                jIndex++;
            }
            iIndex++;
        }
        return matrix2By2;
    }

    double det2By2(T **matrix2By2) {
//        std::cout << "det2By2:" << std::endl;
//        for (int i = 0; i < 2; i++) {
//            for (int j = 0; j < 2; j++) {
//                std::cout << "matrix2By2[" << i << "][" << j << "]: " << matrix2By2[i][j] << std::endl;
//            }
//        }
        double result = matrix2By2[0][0] * matrix2By2[1][1] - matrix2By2[1][0] * matrix2By2[0][1];
        return result;
    }


};


#endif //LAB1_NEW_LIFE_MATRIX_H
