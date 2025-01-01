Algorithms are taken from the paper **"Lower Bounds for a Subexponential Optimization Algorithm" by Matoušek**.  
Linear Programming Problem is from Section 4 of the paper.

---

## Run Results

I used Euler Cluster with 48 cores(maximum available number of cores without a special request).
The following tests use `d` variables and `2d` constraints.  

### Runs for **Sharir-Welzl Standard Algorithm**

| **Number of Repeats** | **d** | **d*(d+3)/8** | **Average Number of Basis Changes** | **Standard Deviation** |
|------------------------|-------|---------------|-------------------------------------|------------------------|
| 1000 | 5 | 5.00 | 5.08 | 3.26 |
| 1000 | 10 | 16.25 | 16.25 | 8.61 |
| 1000 | 20 | 57.50 | 57.27 | 25.06 |
| 1000 | 50 | 331.25 | 334.45 | 102.63 |
| 1000 | 100 | 1287.50 | 1306.33 | 290.68 |
| 1000 | 150 | 2868.75 | 2879.15 | 532.85 |

- In average, we observe d(d+3)/8 basis changes, which aligns with the number of basis changes theoretically proven in the paper.


### Runs for **Sharir-Welzl One Permutation Variant Algorithm**

| **Number of Repeats** | **d**   | **Average Number of Basis Changes** | **Standard Deviation** |
|---------------------|---------|-------------------------------------| ---------------|
| 1'000 | 5 | 4.939000 | 3.100789 | 
| 1'000 | 10 | 16.818000 | 10.395428 |
| 1'000 | 20 | 73.272000 | 51.090451 |
| 1'000 | 50 | 1086.459000 | 1162.721033 | 
| 1'000 | 100 | 15961.600000 | 18915.799967 |
| 1'000 | 150 | 123510.937000 | 184339.910585 |

- There is a high variance going on.

---


## Files

1. **`lpsw.cpp`**: Implements the Standard Sharir-Welzl Algorithm (Section 2 of the paper).
   - Takes `d` (number of variables) as an argument.
   - Compile and test using:
     ```bash
     g++ -o lpsw lpsw.cpp -std=c++17 -O3
     ./lpsw <d>
     ```

2. **`lpswop.cpp`**: Implements the One Permutation Variant of the Sharir-Welzl Algorithm (Section 3 of the paper).
   - Takes `d` (number of variables) as an argument.
   - Compile and test using:
     ```bash
     g++ -o lpswop lpswop.cpp -std=c++17 -O3
     ./lpswop <d>
     ```

3. **`runlpsw.sh`**: A bash script for parallelizing the runs of `lpsw.cpp`. Uses all the cores available.
   - Option 1:
       - Takes 'r' (number of repeats) and 'd' (number of variables).
         ```bash
         ./runlpsw.sh <r> 0 <d>
         ```
   - Option 2:
       - Takes 'r' (number of repeats), while the list of variable values 'd' is hardcoded in `runlpsw.sh`. This option was primarily designed to genereate runtime table for multiple d values in a single run.
         ```bash
         ./runlpsw.sh <r> 1
         ```
      
4. **`runlpswop.sh`**: A bash script for parallelizing the runs of `lpswop.cpp`. Uses all the cores available.
   - Option 1:
       - Takes 'r' (number of repeats) and 'd' (number of variables).
         ```bash
         ./runlpswop.sh <r> 0 <d>
         ```
   - Option 2:
       - Takes 'r' (number of repeats), while the list of variable values 'd' is hardcoded in `runlpswop.sh`. This option was primarily designed to genereate runtime table for multiple d values in a single run.
         ```bash
         ./runlpswop.sh <r> 1
         ```


