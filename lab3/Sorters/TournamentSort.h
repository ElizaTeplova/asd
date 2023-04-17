//
// Created by mrbab on 21.03.2023.
//
#pragma once
#ifndef LAB3_TOURNAMENTSORT_H
#define LAB3_TOURNAMENTSORT_H

#include <iostream>
#include <vector>
#include <limits>
#include "Sorter.h"

using namespace std;

#define N arrSize
#define MAXINT 32767


int *tournamentSort(int *A, int size) {

    int tree[size * 2];
    int i;

    int k, j = 0;

    while (j < N) {
        tree[size + j] = A[j];
        ++j;
    }

    j = size;
    while (j < 2 * size) {
        if (tree[j] >= tree[j + 1]) tree[j / 2] = j;
        else tree[j / 2] = j + 1;
        j += 2;
    }

    k = size / 2;
    while (k >= 1) {
        j = k;
        while (j < 2 * k) {
            if (tree[tree[j]] >= tree[tree[j + 1]])
                tree[j / 2] = tree[j];
            else tree[j / 2] = tree[j + 1];
            j += 2;
        }
        k /= 2;
//        Sorter::printArr("while", tree, size * 2);
    }

    for (k = N; k >= 2; --k) {
        i = tree[1];
        A[k - 1] = tree[i];
        tree[i] = -MAXINT;


        if (i % 2) tree[i / 2] = i - 1;
        else tree[i / 2] = i + 1;

        i /= 2;

        while (i > 1) {
            if (i % 2) j = i - 1;
            else j = i + 1;
            if (tree[tree[i]] > tree[tree[j]]) tree[i / 2] = tree[i];
            else tree[i / 2] = tree[j];
            i /= 2;
        }
//        Sorter::printArr("for", tree, size * 2);
    }
    A[0] = tree[tree[1]];
    return A;
}

#include <cmath>
#include <algorithm>

//template<typename T>
//void tournamentSort(T arr[], int size) {
//    T temp[size];
//    std::copy(arr, arr + size, temp);
//
//    int n = pow(2, ceil(log2(size))); // находим ближайшую границу выпуклости
//    T tree[n * 2]; // создаем массив с размером 2n
//
//    // Инициализируем элементы, соответствующие листьям дерева
//    for (int i = 0; i < size; i++) {
//        tree[n + i] = temp[i];
//    }
//    // Вычисляем победителей на каждом уровне дерева
//    for (int i = n - 1; i > 0; i--) {
//        tree[i] = (tree[i * 2] < tree[(i * 2) + 1]) ? tree[i * 2] : tree[(i * 2) + 1];
//    }
//
//    // Располагаем победителей в корне. Пересчитываем победителей при добавлении нового элемента
//    for (int i = n + size; i < n * 2; i++) {
//        tree[i] = std::numeric_limits<T>::max();
//    }
//    for (int i = n - 1; i > 0; i--) {
//        tree[i] = (tree[i * 2] < tree[(i * 2) + 1]) ? tree[i * 2] : tree[(i * 2) + 1];
//    }
//    for (int i = 0; i < size - 1; i++) {
//        T curWinner = tree[1]; // Извлекаем победителя
//
//        // Перемещаем последний элемент в текущее место победителя
//        tree[n + curWinner - 1] = tree[n + size - 1 - i];
//        tree[n + size - 1 - i] = std::numeric_limits<T>::max();
//
//        // Вычисляем победителей на пути к корню, начиная от родителя перемещенного элемента
//        int cur = (n + size - 1 - i) / 2;
//        while (cur > 0) {
//            tree[cur] = (tree[cur * 2] < tree[(cur * 2) + 1]) ? tree[cur * 2] : tree[(cur * 2) + 1];
//            cur /= 2;
//        }
//    }
//
//    // Копируем данные в исходный массив
////    for (int i = 0; i < size; i++) {
////        arr[i] = temp[i];
////    }
//    // Копируем данные из временного массива в исходный массив
//    std::copy(temp, temp + size, arr);
//    Sorter::printArr("", arr, size);
//}



#endif //LAB3_TOURNAMENTSORT_H
