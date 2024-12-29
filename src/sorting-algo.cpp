#include "sorting-algo.h"
#include <algorithm>
#include <vector>

// Bubble Sort
void bubbleSort(std::vector<int>& arr, int lo, int hi) {
    int n = hi - lo + 1;
    while (n > 1) {
        int newn = lo;
        for (int i = lo; i < hi; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                newn = i + 1;
            }
        }
        n = newn;
    }
}
// Insertion Sort
void insertionSort(std::vector<int>& arr, int lo, int hi) {
    for (int i = lo + 1; i <= hi; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= lo && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
// Quick Sort
void quickSort(std::vector<int> &arr, int lo, int hi, const int threshold) {
    while (lo < hi) {
        if (hi - lo + 1 <= threshold) {
            insertionSort(arr, lo, hi);
            return;
        }

        int p = partition(arr, lo, hi);
        if (p - lo < hi - p) {
            quickSort(arr, lo, p, threshold);
            lo = p + 1;
        } else {
            quickSort(arr, p + 1, hi, threshold);
            hi = p;
        }
    }
}
int partition(std::vector<int> &arr, int lo, int hi) {
    int pivot = medianOfThree(arr, lo, hi);
    int i = lo - 1;
    int j = hi + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        
        if (i >= j) return j;

        std::swap(arr[i], arr[j]);
    }
}
int medianOfThree(std::vector<int> &arr, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;

    if (arr[mid] < arr[lo]) {
        std::swap(arr[mid], arr[lo]);
    }
    if (arr[hi] < arr[lo]) {
        std::swap(arr[lo], arr[hi]);
    }
    if (arr[mid] < arr[hi]) {
        std::swap(arr[mid], arr[hi]);
    }
    return arr[hi];
}

