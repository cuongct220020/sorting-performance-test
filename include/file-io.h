#ifndef FILE_IO_H
#define FILE_IO_H

#include <vector>
#include <string>

// Function to read numbers from a file
std::vector<int> readDataFromFile(const char* filename);

void saveExecTimeToFile(const char* filename, const char* sortFuncname, const int inputNum, const double execTime);
// Function to write numbers to a file
void saveResultsToFile(const char* filename, const int inputNum, const double execTime1, const double execTime2, const double execTime3);

void generateDataToFile(const char* filename, int count);

#endif // FILE_IO_H