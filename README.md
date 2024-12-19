Implementation of algorithms are taken from the paper **"Lower Bounds for a Subexponential Optimization Algorithm" by Matoušek**.  
Linear Programming Problem is from Section 4 of the paper.

---

## Run Results

I used Euler Cluster with 48 cores(maximum available number of cores without a special request).
The following tests use `d` variables and `2d` constraints.  

### Runs for **Sharir-Welzl Standard Algorithm**

| **Number of Repeats** | **d**   | **Average Number of Basis Changes** | **Ratio (Average Number / d)** |
|---------------------|---------|-------------------------------------|--------------------------------|
| 100'000              | 10      | 15.5201                             | 1.552010                        |
| 100'000              | 20      | 31.836640                             | 1.591832                       |
| 100'000              | 50      | 80.752910                             | 1.615058                       |
| 100'000              | 100     | 162.333190                            | 1.623332                       |
| 100'000              | 200     | 325.412140                            | 1.627061                       |
| 10'000              | 400     | 651.5723                            | 1.628931                       |
| 10'000              | 600     | 977.7707                            | 1.629618                       |
| 1'000               | 800     | 1303.904                            | 1.62988                        |
| 1'000               | 1000    | 1630.662                            | 1.630662                       |
| 100                |2000    | 3263.42                             |  1.63171               |

---

### Runs for **Sharir-Welzl One Permutation Variant Algorithm**

| **Number of Repeats** | **d**   | **Average Number of Basis Changes** |
|---------------------|---------|-------------------------------------|
| 100'000               | 10      | 38.13669                              |
| 100'000               | 20      | 172.5733                            |
| 100'000               | 50      | 1757.99164                            |
| 1'000               | 100     | 12031.589                           |
| 1'000                 | 150     | 39657.767                           |
| 400                 | 200     | 104334.322500                          |
| 400                 | 250     | 154732.19                        |

#### Notes:
  
- There is a high variance in the One Permutation Variant.

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
         ./runlpsw <r> 0 <d>
         ```
   - Option 2:
       - Takes 'r' (number of repeats), while the list of variable values 'd' is hardcoded in `runlpsw.sh`. This option was primarily designed to genereate runtime table for multiple d values in a single run.
         ```bash
         ./runlpsw <r> 1
         ```
      
4. **`runlpswop.sh`**: A bash script for parallelizing the runs of `lpswop.cpp`. Uses all the cores available.
   - Option 1:
       - Takes 'r' (number of repeats) and 'd' (number of variables).
         ```bash
         ./runlpswop <r> 0 <d>
         ```
   - Option 2:
       - Takes 'r' (number of repeats), while the list of variable values 'd' is hardcoded in `runlpswop.sh`. This option was primarily designed to genereate runtime table for multiple d values in a single run.
         ```bash
         ./runlpswop <r> 1
         ```


