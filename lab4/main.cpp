#include <iostream>
#include <chrono>
#include "PDT/PDTTestObject.h"
#include "Utils/Sorter.h"
#include "Utils/Search.h"
#include <vector>

int main() {
//    std::cout << "Hello, World!" << std::endl;
//
    int i = 0;
    int arrSize = 20;
    double position = -1;
    std::srand(time(nullptr));
    int * intPtrArr = new int [arrSize];
    for (i = arrSize - 1; i >= 0; i--) {
        intPtrArr[i] = std::rand() % 1000;
    }
    double *nonExistingEl;
    nonExistingEl = &position;
//    Sorter::printArr("Start arr: ", intPtrArr, arrSize);
////    PDTTestObject *object = new PDTTestObject[arrSize]();

//    Sorter::shellSort<PDTTestObject>(object, arrSize);
    Sorter::shellSort<int>(intPtrArr, arrSize);
    Sorter::printArr("sortedArr: ", intPtrArr, arrSize);
    std::cout << "Sorting was ended." << std::endl;
    auto start = std::chrono::system_clock::now();
    position = Search::fibonacciSearch<int>(intPtrArr, intPtrArr[3], arrSize);
//    position = Search::interpolationSearch<int>(intPtrArr, intPtrArr[10], arrSize);
//    position = Search::binarySearch<int>(intPtrArr, intPtrArr[3], arrSize);
    std::cout << "el: " << intPtrArr[3] << std::endl;

    auto end = std::chrono::system_clock::now();
    std::cout << "position: " << position << std::endl;
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout.precision(5);
    std::cout << std::setw(7) << arrSize << "   " << std::setw(10) << elapsed_seconds.count() << std::endl;


    delete[] intPtrArr;
}
