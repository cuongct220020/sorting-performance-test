#include "exec-time.h"
#include <chrono>
#include <iostream>

// Hàm đo lường thời gian thực thi của thuật toán sắp xếp
double measureExecTime(void (*sortFunc)(std::vector<int> &, int, int), std::vector<int> &arr)
{
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(arr, 0, arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

double measureExecTime(void (*sortFunc)(std::vector<int> &, int, int, int), std::vector<int> &arr, const int threshold) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(arr, 0, arr.size() - 1, threshold);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

bool testSortingAlgorithms(std::vector<int>& bubbleSorted, std::vector<int> &insertionSorted, std::vector<int> &quickSorted) {
    if (bubbleSorted.size() != insertionSorted.size() || bubbleSorted.size() != quickSorted.size()) {
        return false;
    }

    return true;
}