//
// Created by mrbab on 04.04.2023.
//

#ifndef LAB4_SORTER_H
#define LAB4_SORTER_H

class Sorter {
private:

public:

    template<typename T>
    static void shellSort(T *a, int size) {
        T temp;
        int gap = 0, i = 0, j = 0;
//        printArr("start:", a, size);
        for (gap = size / 2; gap > 0; gap /= 2) {
            for (i = gap; i < size; i++) {
                temp = a[i];

                for (j = i; j >= gap && a[j - gap] > temp; j-=gap) {
                    a[j] = a[j - gap];
                }
                a[j] = temp;
            }
//            printArr("a:", a, size);
        }
    }

    template<typename T>
    static void printArr(const std::string &messege, T *a, int size) {
        int i = 0;


        std::cout << messege << std::endl;
        for (i = 0; i < size; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }

    template<typename T>
    static void printArrWithBound(const std::string &messege, T *a, int low, int high) {
        int i = 0;

        std::cout << messege << std::endl;
        for (i = low; i < high; i++) {
            std::cout << a[i] << " "; //<< std::endl;
        }
        std::cout << std::endl;
    }
};

#endif //LAB4_SORTER_H
