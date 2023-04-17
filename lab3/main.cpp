#include <iostream>
#include <chrono>
#include "Sorters/Sorter.h"
#include "PDT/PDTTestObject.h"
#include "Sorters/TournamentSort.h"


int main() {
//    std::cout << "Hello, World!" << std::endl;
//
    int i = 0;
//    int intArr[arrSize] = {9, 12, 5, 7, 6, 9, 1, 2, 3};

    int * intPtrArr = new int [arrSize];
    for (i = arrSize - 1; i >= 0; i--) {
        intPtrArr[i] = std::rand() % 10;
//        intPtrArr[arrSize - 1 - i] = i;
    }
    Sorter::printArr("Start arr: ", intPtrArr, arrSize);
//
////    PDTTestObject *object = new PDTTestObject[arrSize]();
//    std::cout << "sorting..." << std::endl;
    auto start = std::chrono::system_clock::now();
////    Sorter::mergeSort<PDTTestObject>(object, 0, arrSize);
//    Sorter::shellSort<PDTTestObject>(object, arrSize);
//    Sorter::shellSort<int>(intPtrArr, arrSize);
//    tournamentSort2(intPtrArr, arrSize);
    Sorter::mergeSort<int>(intPtrArr, 0, arrSize);
//    std::vector<int> arr = { 5, 3, 8, 4, 2, 7, 1, 6 };
//    tournamentSort(intPtrArr, arrSize);
    auto end = std::chrono::system_clock::now();
    Sorter::printArr("sortedArr: ", intPtrArr, arrSize);
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout.precision(5);
    std::cout << std::setw(7) << arrSize << "   " << std::setw(10) << elapsed_seconds.count() << std::endl;

//    std::vector<int> arr = { 5, 3, 8, 4, 2, 7, 1, 6 };
//    tournamentSort(intPtrArr, arrSize);
//    Sorter::printArr("end arr: ", intPtrArr, arrSize);


//    for (i = 0; i < arrSize; i++) {
//        std::cout << object[i] << std::endl;
//    }

//    delete[] object;
//    Sorter::mergeSort<int>(intPtrArr, 0, arrSize);
//
//    Sorter::printArr<int>("", intPtrArr, arrSize);

    delete[] intPtrArr;

    return 0;
}
