#ifndef SORTING_ALGO_H
#define SORTING_ALGO_H

#include <vector>

// Function declarations for sorting algorithms
void bubbleSort(std::vector<int>& arr, int lo, int hi);
void insertionSort(std::vector<int>& arr, int lo, int hi);
void quickSort(std::vector<int> &arr, int lo, int hi, const int threshold);

// Utility function for quick sort
int partition(std::vector<int> &arr, int lo, int hi);
int medianOfThree(std::vector<int> &arr, int lo, int hi);

#endif // SORTING_ALGO_H