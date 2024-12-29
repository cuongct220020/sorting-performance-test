#include "file-io.h"
#include <cstdio>
#include <vector>
#include <iostream>
#include <random>

// Hàm sinh input ngẫu nhiên để ghi vào file. 
void generateDataToFile(const char* filename, int count) {
    int minVal = -1e9;
    int maxVal = 1e9;

    FILE* file = fopen(filename, "w");
    if (!file) {
        std::cerr << "Lỗi không mở được file" << filename << "\n";
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(minVal, maxVal);

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d ", distr(gen));
    }

    fclose(file);
}

// Hàm đọc dữ liệu từ file. 
std::vector<int> readDataFromFile(const char* filename) {
    std::vector<int> data;
    FILE* file = fopen(filename, "r");

    if (!file) {
        std::cerr << "Lỗi không mở được file: " << filename << "\n";
        return data;
    }

    int number;
    while (fscanf(file, "%d", &number) != EOF) {
        data.push_back(number);
    }
    return data;
}

// Hàm lưu thời gian thực thi của thuật toán vào file. 
void saveExecTimeToFile(const char* filename, const char* sortFuncname,const int inputNum, const double execTime) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        std::cerr << "Lỗi: không thể mở file" << filename << "\n";
        return;
    }
    fprintf(file, "Thời gian thực thi của thuật toán %s với input n = %d: %f giây\n", sortFuncname, inputNum, execTime);
    fclose(file);
}

// Hàm lưu kết quả thực thi của 03 thuật toán vào file. 
void saveResultsToFile(const char* filename, const int inputNum, const double execTime1, const double execTime2, const double execTime3) {
    FILE* file = fopen(filename, "a");
    if (!file) {
        std::cerr << "Lỗi: Không mở được file: " << filename << "\n";
        return;
    }

    fprintf(file, "Thời gian thực thi của thuật toán với input n = %d:\n", inputNum);
    fprintf(file, "\t1. Bubble Sort: %f giây\n", execTime1);
    fprintf(file, "\t2. Insertion Sort: %f giây\n", execTime2);
    fprintf(file, "\t3. Quick Sort: %f giây\n", execTime3);

    fclose(file);
}