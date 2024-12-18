Implementation of algorithms are taken from the paper **"Lower Bounds for a Subexponential Optimization Algorithm" by Matoušek**.  
Linear Programming Problem is from Section 4 of the paper.

---

## Run Results

I used Euler Cluster with 48 cores(maximum available number of cores without a special request).
The following tests use `d` variables and `2d` constraints.  

### Runs for **Sharir-Welzl Standard Algorithm**

| **Number of Runs** | **d**   | **Average Number of Basis Changes** |
|---------------------|---------|-------------------------------------|
| 10000              | 10      | 15.5209                             |
| 10000              | 20      | 31.8501                             |
| 10000              | 50      | 80.7577                             |
| 10000              | 100     | 162.3129                            |
| 10000              | 200     | 325.3922                            |
| 1000               | 400     | 651.845                             |
| 1000               | 600     | 977.960                             |
| 1000               | 800     | 1303.904                            |
| 1000               | 1000    | 1630.662                            |

---

### Runs for **Sharir-Welzl One Permutation Variant Algorithm**

| **Number of Runs** | **d**   | **Average Number of Basis Changes** |
|---------------------|---------|-------------------------------------|
| 1000               | 10      | 39.092                              |
| 1000               | 20      | 176.094                             |
| 1000               | 50      | 1720.856                            |
| 1000               | 100     | 12031.589                           |
| 20                 | 150     | 44882.100                           |
| 20                 | 200     | 189287.950                          |
| 20                 | 250     | 220581.850                          |

#### Notes:
  
- There is high variance in the One Permutation Variant, so 20 runs are definitely not a reliable indicator.  
- For `d = 200`, 1000 repeats might take half a day.  
- For `d = 500`, 1000 repeats might take months to complete.

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


