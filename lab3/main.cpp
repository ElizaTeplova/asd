#include <iostream>
#include <chrono>
#include "Sorters/Sorter.h"
#include "PDT/PDTTestObject.h"



int main() {
//    std::cout << "Hello, World!" << std::endl;

    int i = 0;
//    int intArr[arrSize] = {9, 12, 5, 7, 6, 9, 1, 2, 3};
//
//    double * intPtrArr = new double [arrSize];
//    for (i = 0; i < arrSize; i++) {
//        intPtrArr[i] = std::rand() % 5000;
//    }

    PDTTestObject *object = new PDTTestObject[arrSize]();
    std::cout << "sorting..." << std::endl;
    auto start = std::chrono::system_clock::now();
    Sorter::mergeSort<PDTTestObject>(object, 0, arrSize);
//    Sorter::mergeSort<double>(intPtrArr, 0, arrSize);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout.precision(5);
    std::cout << std::setw(7) << arrSize << "   " << std::setw(10) << elapsed_seconds.count() << std::endl;

//    for (i = 0; i < arrSize; i++) {
//        std::cout << object[i] << std::endl;
//    }

    delete[] object;
//    Sorter::mergeSort<int>(intPtrArr, 0, arrSize);
//
//    Sorter::printArr<int>("", intPtrArr, arrSize);

//    delete[] intPtrArr;

    return 0;
}
