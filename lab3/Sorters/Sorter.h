//
// Created by mrbab on 19.03.2023.
//

#ifndef LAB3_SORTER_H
#define LAB3_SORTER_H


class Sorter {
private:

    template<typename T>
    static void merge(T *a, int left, int mid, int right) {
        int sizeLeftArray = mid - left + 1;
        int sizeRightArray = right - mid;
        int indexLeftArray, indexRightArray, indexMergedArray;
        int i = 0, j = 0;
        T *arrayLeft = new T[sizeLeftArray];
        T *arrayRight = new T[sizeRightArray];

        for (i = 0; i < sizeLeftArray; i++) {
            arrayLeft[i] = a[left + i];
        }
        for (j = 0; j < sizeRightArray; j++) {
            arrayRight[j] = a[mid + 1 + j];
        }
//        std::cout << "left: " << left << " right: " << right << std::endl;

        indexLeftArray = 0;
        indexRightArray = 0;
        indexMergedArray = left;

//        printArrWithBound("mergeBefore: ", a, left, right);

        while (indexRightArray < sizeRightArray &&
               indexLeftArray < sizeLeftArray) {

            if (arrayLeft[indexLeftArray] <= arrayRight[indexRightArray]) {
                a[indexMergedArray] = arrayLeft[indexLeftArray];
                indexLeftArray++;
            } else {
                a[indexMergedArray] = arrayRight[indexRightArray];
                indexRightArray++;
            }
            indexMergedArray++;
        }

        while (indexRightArray < sizeRightArray) {
            a[indexMergedArray] = arrayRight[indexRightArray];
            indexRightArray++;
            indexMergedArray++;
        }

        while (indexLeftArray < sizeRightArray) {
            a[indexMergedArray] = arrayLeft[indexLeftArray];
            indexLeftArray++;
            indexMergedArray++;
        }
//        printArrWithBound("mergeAfter: ", a, left, right);

        delete[] arrayLeft;
        delete[] arrayRight;
    }

public:

    template<typename T>
    static void mergeSort(T *a, int begin, int end) {
        if (begin >= end) {
            return;
        }

        int mid = begin + (end - begin) / 2;
//            printArrWithBound("mergeSort: ", a, begin, mid);
            mergeSort(a, begin, mid);
//            printArrWithBound("mergeSort: ", a, mid + 1, end);
            mergeSort(a, mid + 1, end);
//            printArrWithBound("merge: ", a, begin, end);
            merge<T>(a, begin, mid, end);
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
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif //LAB3_SORTER_H
