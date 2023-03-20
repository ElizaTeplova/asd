#include <iostream>
#include "Sorters/Sorter.h"

int main() {
//    std::cout << "Hello, World!" << std::endl;
    const int arrSize = 9;
    int i = 0;
    int intArr[arrSize] = {9, 12, 5, 7, 6, 9, 1, 2, 3};

    int* intPtrArr = new int[arrSize];
    for (i = 0; i < arrSize; i++) {
        intPtrArr[i] = intArr[i];
    }

    Sorter::mergeSort<int>(intPtrArr, 0, arrSize);

    Sorter::printArr<int>("", intPtrArr, arrSize);

    delete[] intPtrArr;

    return 0;
}
