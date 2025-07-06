#include "file-io.h"
#include "sorting-algo.h"
#include "exec-time.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

int main(int, char **)
{
    try
    {
        while (true)
        {
            std::cout << "--------------- Chương trình kiểm chứng các thuật toán sắp xếp ---------------\n";
            std::cout << "1. Đo lường thời gian thực thi của một trong ba thuật toán sắp xếp.\n";
            std::cout << "2. So sánh thời gian thực thi của ba thuật toán sắp xếp.\n";
            std::cout << "3. Thoát chương trình.\n";

            std::string choice;
            while (true)
            {
                try
                {
                    std::cout << "--> Vui lòng nhập lựa chọn của bạn: ";
                    std::cin >> choice;
                    if (choice == "1" || choice == "2" || choice == "3")
                    {
                        break;
                    }
                    else
                    {
                        throw std::invalid_argument("Lựa chọn không hợp lệ. Vui lòng nhập lại!");
                    }
                }
                catch (const std::invalid_argument &e)
                {
                    std::cerr << "Lỗi: " << e.what() << "\n";
                }
            }

            if (choice == "1")
            {
                std::cout << "\nChương trình cần import một file ngẫu nhiên lớn hơn 10,000 phần tử\n";
                std::string inputFilename;
                while (true) {
                    try {
                        std::cout << "Hãy nhập tên file dữ liệu đầu vào (ví dụ input.txt): ";   
                        std::cin >> inputFilename;
                        
                        if (inputFilename.size() >= 4 && inputFilename.substr(inputFilename.size() - 4) == ".txt") {
                            break;
                        } else {
                            throw std::invalid_argument("Tên file phải có đuôi .txt. Vui lòng nhập lại!");
                        }
                    } catch (const std::invalid_argument &e) {
                        std::cerr << "Lỗi: " << e.what() << "\n";
                    }
                }

                int inputNum;
                while (true)
                {
                    try
                    {
                        std::cout << "Hãy nhập số lượng phần tử cần sắp xếp: ";
                        std::cin >> inputNum;
                        if (inputNum > 10000)
                        {
                            break;
                        }
                        else if (inputNum <= 10000)
                        {
                            throw std::invalid_argument("Số lượng phần tử phải lớn hơn 10,000. Vui lòng nhập lại!");
                        }
                        else
                        {
                            throw std::invalid_argument("Giá trị nhập không hợp lệ. Vui lòng nhập lại!");
                        }
                    }
                    catch (const std::invalid_argument &e)
                    {
                        std::cerr << "Lỗi: " << e.what() << "\n";
                    }
                }


                std::string inputFilepath = "../data/" + inputFilename;
                generateDataToFile(inputFilepath.c_str(), inputNum);

                std::vector<int> data = readDataFromFile(inputFilepath.c_str());

                if (data.size() < 10000)
                {
                    throw std::runtime_error("Số lượng phần tử của mảng phải lớn hơn hoặc bằng 10,000.");
                }

                std::cout << "Lựa chọn một trong 03 thuật toán sau: \n";
                std::cout << "\ta Bubble Sort\n";
                std::cout << "\tb Insertion Sort\n";
                std::cout << "\tc. Quick Sort\n";

                std::string choice1;
                double executionTime = 0.0;

                while (true)
                {
                    try
                    {
                        std::cout << "--> Vui lòng nhập lựa chọn của bạn: ";
                        std::cin >> choice1;
                        if (choice1 == "a" || choice1 == "b" || choice1 == "c")
                        {
                            break;
                        }
                        else
                        {
                            throw std::invalid_argument("Lựa chọn không hợp lệ. Vui lòng nhập lại!");
                        }
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << "Lỗi: " << e.what() << "\n";
                    }
                }

                const char *sortFuncname;
                if (choice1 == "a")
                {
                    sortFuncname = "Bubble Sort";
                    executionTime = measureExecTime(bubbleSort, data);
                    std::cout << "Thời gian thực thi của thuật toán Bubble Sort với đầu vào n = " << inputNum << ": " << executionTime << " giây.\n";
                }
                else if (choice1 == "b")
                {
                    sortFuncname = "Insertion Sort";
                    executionTime = measureExecTime(insertionSort, data);
                    std::cout << "Thời gian thực thi của thuật toán insertionSort với đầu vào n = " << inputNum << ": " << executionTime << " giây.\n";
                }
                else if (choice1 == "c")
                {
                    sortFuncname = "Quick Sort";
                    executionTime = measureExecTime(quickSort, data, 10);
                    std::cout << "Thời gian thực thi của thuật toán Quick Sort với đầu vào n = " << inputNum << ": " << executionTime << " giây.\n";
                }

                std::string outputFilename;
                while (true) {
                    try {
                        std::cout << "\nHãy nhập tên file bạn muốn lưu kết quả (ví dụ: output.txt): ";
                        std::cin >> outputFilename;
                        if (outputFilename.size() >= 4 && outputFilename.substr(outputFilename.size() - 4) == ".txt") {
                            break;
                        } else {
                            throw std::invalid_argument("Tên file phải có đuôi .txt. Vui lòng nhập lại!");
                        }
                    } catch(const std::exception &e) {
                        std::cerr << "Lỗi: " << e.what() << "\n";
                    }
                }

                std::string outputFilepath = "../out/" + outputFilename;

                saveExecTimeToFile(outputFilepath.c_str(), sortFuncname, inputNum, executionTime);
                std::cout << "Đã lưu kết quả vào file thành công.\n\n";
            }
            else if (choice == "2")
            {
                std::cout << "\nLựa chọn các input sau: \n";
                std::cout << "\ta. n = 10,000\n";
                std::cout << "\tb. n = 100,000\n";
                std::cout << "\tc. n = 1,000,000\n";

                std::string choice2;
                std::vector<int> data, bubbleSorted, insertionSorted, quickSorted;

                while (true)
                {
                    try
                    {
                        std::cout << "--> Vui lòng lựa chọn input của bạn: ";
                        std::cin >> choice2;

                        if (choice2 == "a" || choice2 == "b" || choice2 == "c")
                        {
                            break;
                        }
                        else
                        {
                            throw std::invalid_argument("Lựa chọn không hợp lệ. Vui lòng nhập lại.");
                        }
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << "Lỗi: " << e.what() << "\n";
                    }
                }

                if (choice2 == "a")
                {
                    int n = 10000;
                    std::string inputFilename = "input1e4.txt";
                    std::string inputFilepath = "../data/" + inputFilename;

                    generateDataToFile(inputFilepath.c_str(), n);
                    data = readDataFromFile(inputFilepath.c_str());
                    std::cout << "Đã đọc xong dữ liệu từ file " << inputFilename << "\n";

                    bubbleSorted = data;
                    double execTime1 = measureExecTime(bubbleSort, bubbleSorted);
                    std::cout << "Thời gian thực thi của thuật toán Bubble Sort: " << execTime1 << " giây.\n";

                    insertionSorted = data;
                    double execTime2 = measureExecTime(insertionSort, insertionSorted);
                    std::cout << "Thời gian thực thi của thuật toán Insertion Sort: " << execTime2 << " giây.\n";

                    quickSorted = data;
                    double execTime3 = measureExecTime(quickSort, quickSorted, 10);
                    std::cout << "Thời gian thực thi của thuật toán Quick Sort: " << execTime3 << " giây.\n";

                    std::cout << "Đã đo xong thời gian thực thi của 03 thuật toán.\n";

                    bool isTrueOutput = testSortingAlgorithms(bubbleSorted, insertionSorted, quickSorted);
                    std::string outputFilename = "output1e4.txt";

                    if (isTrueOutput) {
                        std::cout << "Tất cả các thuật toán sắp xếp cho cùng một kết quả!\n";

                        std::string outputFilepath = "../out/" + outputFilename;

                        saveResultsToFile(outputFilepath.c_str(), n, execTime1, execTime2, execTime3);
                        std::cout << "Đã lưu kết quả vào file " << outputFilename << " thành công.\n\n";
                    } else {
                        std::cerr << "Có sự khác biệt giữa các thuật toán sắp xếp. Không thực hiện lưu kết quả vào file" << outputFilename << "\n";
                        throw std::runtime_error("Kết quả sắp xếp không trùng khớp.");
                    }
                }
                else if (choice2 == "b")
                {
                    int n = 100000;
                    std::string inputFilename = "input1e5.txt";
                    std::string inputFilepath = "../data/" + inputFilename;

                    generateDataToFile(inputFilepath.c_str(), n);
                    data = readDataFromFile(inputFilepath.c_str());
                    std::cout << "Đã đọc xong dữ liệu từ file " << inputFilename << "\n";

                    bubbleSorted = data;
                    double execTime1 = measureExecTime(bubbleSort, bubbleSorted);
                    std::cout << "Thời gian thực thi của thuật toán Bubble Sort: " << execTime1 << " giây.\n";

                    insertionSorted = data;
                    double execTime2 = measureExecTime(insertionSort, insertionSorted);
                    std::cout << "Thời gian thực thi của thuật toán Insertion Sort: " << execTime2 << " giây.\n";

                    quickSorted = data;
                    double execTime3 = measureExecTime(quickSort, quickSorted, 10);
                    std::cout << "Thời gian thực thi của thuật toán Quick Sort: " << execTime3 << " giây.\n";

                    std::cout << "Đã đo xong thời gian thực thi của 03 thuật toán.\n";

                    std::string outputFilename = "output1e5.txt";
                    bool isTrueOutput = testSortingAlgorithms(bubbleSorted, insertionSorted, quickSorted);
                    
                    if (isTrueOutput) {
                        std::cout << "Tất cả các thuật toán sắp xếp cho cùng một kết quả!\n";

                        
                        std::string outputFilepath = "../out/" + outputFilename;

                        saveResultsToFile(outputFilepath.c_str(), n, execTime1, execTime2, execTime3);
                        std::cout << "Đã lưu kết quả vào file " << outputFilename << " thành công.\n\n";
                    } else {
                        std::cerr << "Có sự khác biệt giữa các thuật toán sắp xếp, Không thực hiện lưu kết quả vào file " << outputFilename << "\n";
                        throw std::runtime_error("Kết quả sắp xếp không trùng khớp.");
                    }
                }
                else if (choice2 == "c")
                {
                    int n = 1000000;
                    
                    std::string inputFilename = "input1e6.txt";
                    std::string inputFilepath = "../data/" + inputFilename;

                    generateDataToFile(inputFilepath.c_str(), n);
                    data = readDataFromFile(inputFilepath.c_str());
                    std::cout << "Đã đọc xong dữ liệu từ file " << inputFilename << "\n";

                    bubbleSorted = data;
                    double execTime1 = measureExecTime(bubbleSort, bubbleSorted);
                    std::cout << "Thời gian thực thi của thuật toán Bubble Sort: " << execTime1 << " giây.\n";
                    
                    insertionSorted = data;
                    double execTime2 = measureExecTime(insertionSort, insertionSorted);
                    std::cout << "Thời gian thực thi của thuật toán Insertion Sort: " << execTime2 << " giây.\n";
                    
                    quickSorted = data;
                    double execTime3 = measureExecTime(quickSort, data, 10);
                    std::cout << "Thời gian thực thi của thuật toán Quick Sort: " << execTime3 << " giây.\n";

                    std::cout << "Đã đo xong thời gian thực thi của 03 thuật toán.\n";

                    std::string outputFilename = "output1e6.txt";
                    bool isTrueOutput = testSortingAlgorithms(bubbleSorted, insertionSorted, quickSorted);
                    
                    if (isTrueOutput) {
                        std::cout << "Tất cả các thuật toán sắp xếp cho cùng một kết quả!\n";

                        
                        std::string outputFilepath = "../out/" + outputFilename;

                        saveResultsToFile(outputFilepath.c_str(), n, execTime1, execTime2, execTime3);
                        std::cout << "Đã lưu kết quả vào file " << outputFilename << " thành công.\n\n";
                    } else {
                        std::cerr << "Có sự khác biệt giữa các thuật toán sắp xếp, Không thực hiện lưu kết quả vào file " << outputFilename << "\n"; 
                        throw std::runtime_error("Kết quả sắp xếp không trùng khớp.");
                    }
                }
            }
            else if (choice == "3")
            {
                std::cerr << "Chương trình kết thúc thành công.\n";
                return 0;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Đã xảy ra lỗi: " << e.what() << "\n";
        return 1;
    }
    catch (...)
    {
        std::cerr << "Đã xảy ra lỗi không xác định\n";
        return 1;
    }

    return 0;
}
