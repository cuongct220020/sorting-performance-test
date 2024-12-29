#ifndef EXECUTION_TIME_H
#define EXECUTION_TIME_H

#include <vector>

double measureExecTime(void (*sortFunc)(std::vector<int> &, int, int), std::vector<int> &arr);

double measureExecTime(void (*sortFunc)(std::vector<int> &, int, int, int), std::vector<int> &arr, const int threshold);

bool testSortingAlgorithms(std::vector<int>& bubbleSorted, std::vector<int> &insertionSorted, std::vector<int> &quickSorted);

#endif // EXECUTION_TIME_H
