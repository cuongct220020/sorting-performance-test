# Sorting Performance Test

> **IT3150 - Project 1 - Hanoi University of Science and Technology**

A simple C++ program to **benchmark and compare** the execution time of three classic sorting algorithms: **Bubble Sort**, **Insertion Sort**, and **Quick Sort**.

## 📌 Overview

This project measures and compares the real-world performance of three sorting algorithms on large datasets (10K, 100K, 1M elements). It also includes a theoretical analysis of their time complexity to explain the observed results.

## 🧪 Algorithms & Theoretical Complexity

The table below summarizes the theoretical time complexity of each algorithm:

<table>
  <thead>
    <tr>
      <th>Algorithm</th>
      <th>Average Time Complexity</th>
      <th>Worst-Case Time Complexity</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>Bubble Sort</strong></td>
      <td>O(n²)</td>
      <td>O(n²)</td>
    </tr>
    <tr>
      <td><strong>Insertion Sort</strong></td>
      <td>O(n²)</td>
      <td>O(n²)</td>
    </tr>
    <tr>
      <td><strong>Quick Sort</strong></td>
      <td>O(n log n)</td>
      <td>O(n²)</td>
    </tr>
  </tbody>
</table>

> 💡 **Key Insight**:  
> Bubble Sort and Insertion Sort scale quadratically — doubling the input size increases runtime by ~4×.  
> Quick Sort’s average-case `O(n log n)` is far more efficient, especially for large `n` (e.g., 1M elements).

## ✅ Features

- **Single Algorithm Test**: Load a custom `.txt` file, choose one algorithm, measure & save its runtime.
- **Full Comparison Mode**: Automatically test all 3 algorithms on pre-defined datasets (10K, 100K, 1M).
- **Result Validation**: Verify that all algorithms produce identical sorted output.
- **Output Logging**: Save results to a file for later analysis.

## ⚙️ System Requirements

- **CMake** >= 3.10  
- **C++ Compiler** supporting **C++23** (e.g., GCC 13+, Clang 15+)  
- Works on **macOS**, **Linux**, and **Windows** (with WSL, MSYS2, or Visual Studio)

## 🚀 How to Build & Run

### 1. Clone the repository:
```bash
git clone https://github.com/cuongct220020/sorting-performance-test.git
cd sorting-performance-test
```

**2. Create a build directory and navigate into it:**
```bash
mkdir build
cd build
```

**3. Configure the project using Cmake:**
```bash
cmake ..
```

**4. Compile the program:**
```bash
make
```

**5. Run the program:**
```bash
./sorting_performance_test_cpp
```

## 📊 Results & Analysis
Empirical results (see your attached plot) confirm the theoretical expectations:

- Bubble Sort and Insertion Sort become impractically slow beyond 100K elements.
- Quick Sort remains efficient even at 1M elements, demonstrating the advantage of O(n log n) scaling.
  
> For full experimental details and visualizations, refer to the project report.

## 📝 License
Educational purpose

## 👨‍💻 Author
[@cuongct220020](https://github.com/cuongct220020)
