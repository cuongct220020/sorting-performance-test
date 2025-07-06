**Program Description**  
This program is designed to test and compare the execution times of three sorting algorithms: 
Bubble Sort, Insertion Sort, and Quick Sort. It allows users to measure the performance of individual 
sorting algorithms or compare all three simultaneously, using large datasets.

---

**Features**  
**1. Measure Execution Time of a Single Algorithm**  
   * 1.1 Import a .txt file containing more than 10,000 elements.  
   * 1.2 Specify the number of elements to sort.  
   * 1.3 Select one of three sorting algorithms (Bubble Sort, Insertion Sort, or Quick Sort).  
   * 1.4 Display the execution time of the chosen algorithm and save the results to a specified output file.  

**2. Compare Execution Times of All Three Algorithms**  
   * 2.1 Select a pre-defined dataset size: 10,000, 100,000, or 1,000,000 elements.  
   * 2.2 Automatically load the corresponding input file.  
   * 2.3 Measure and display the execution times of all three algorithms.  
   * 2.4 Verify the accuracy of the sorted results and save them to an output file if all algorithms produce identical outputs.  

**3. Exit Program**  
The program allows users to exit gracefully at any point.

---

**System Requirements**  
   * **CMake** version **>= 3.10** (Tested up to 3.21)  
   * A **C++ compiler** that supports **C++23** (e.g., GCC >= 13, Clang >= 15)  
   * Compatible with macOS, Linux, or Windows with a proper build environment (e.g., MSYS2, WSL, or Visual Studio)

---

**Build and Run Instructions**

**1. Clone the repository (if not already done):**
```bash
git clone https://github.com/Cuongit1-hust/IT3150-Project1-Sorting-Performance-Test.git
cd IT3150-Project1-Sorting-Performance-Test
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