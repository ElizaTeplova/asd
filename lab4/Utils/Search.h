//
// Created by mrbab on 04.04.2023.
//

#ifndef LAB4_SEARCH_H
#define LAB4_SEARCH_H

#include <iostream>

class Search {

public:
    template<typename T>
    static int binarySearch(T *a, T el, int size) {
        int left = 0, right = size - 1;
        int middle = 0;

        while (left <= right) {
            std::cout << "left: " << left << " right: " << right << std::endl;
            middle = (left + right) / 2;

            if (a[middle] == el) {
                return middle;
            }

            if (el > a[middle]) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        std::cerr << "No such element in current array. Returning -1" << std::endl;
        return -1;
    }

    template<typename T>
    static int fibonacciSearch(T* arr, T x, int size)
    {
        // Инициализируем числа Фибоначчи
        int fib2 = 0; // два числа Фибоначчи назад
        int fib1 = 1; // одно число Фибоначчи назад
        int fib = fib1 + fib2; // текущее число Фибоначчи

        // Находим ближайшее число Фибоначчи, не превышающее длину массива
        while (fib < size) {
            fib2 = fib1;
            fib1 = fib;
            fib = fib1 + fib2;
        }

        // Индекс последнего проверенного элемента в массиве
        int index = -1;

        // Пока остается одно непроверенное значение
        while (fib > 1) {
//            std::cout << "a ";
            int i = std::min(index + fib2, size - 1); // индекс элемента для проверки
            if (arr[i] < x) {
                fib = fib1;
                fib1 = fib2;
                fib2 = fib - fib1;
                index = i;
            } else if (arr[i] > x) {
                fib = fib2;
                fib1 = fib1 - fib2;
                fib2 = fib - fib1;
            } else {
                return i;
            }
            std::cout << "fib: " << fib << " fib1: " << fib1 << " fib2: " << fib2 << std::endl;
        }

        // Если искомое значение не найдено
        if (arr[index + 1] == x) {
            return index + 1;
        } else {
            return -1;
        }

        std::cout<< std::endl;
    }

    template<typename T>
    static int interpolationSearch(T* arr, T x, int size)
    {
        int low = 0; // начальный индекс
        int high = size - 1; // конечный индекс

        while (low <= high && x >= arr[low] && x <= arr[high]) {
//            std::cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaa";
            // Используем формулу линейной интерполяции для нахождения приблизительной позиции искомого
            int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]);
            int val = arr[pos]; // получаем значение в найденной позиции

            if (val == x) {
                return pos; // элемент найден
            } else if (val < x) {
                low = pos + 1; // элемент находится в правой половине массива
            } else {
                high = pos - 1; // элемент находится в левой половине массива
            }
        }
        std::cout << std::endl;
        return -1; // элемент не найден
    }
};

#endif //LAB4_SEARCH_H
