Algorithms are taken from the paper **"Lower Bounds for a Subexponential Optimization Algorithm" by Matoušek**.  
Linear Programming Problem is from Section 4 of the paper.

---

## Run Results

I used Euler Cluster with 48 cores(maximum available number of cores without a special request).
The following tests use `d` variables and `2d` constraints.  

### Runs for **Sharir-Welzl Standard Algorithm**

| **Number of Repeats** | **d** | **d\*(d+3)/8** | **Average Number of Basis Changes** | **Standard Deviation**|
|------------------------|-------|---------------|-------------------------------------|--------|
| 1000 | 5 | 5.00 | 5.00 | 3.14 |
| 1000 | 10 | 16.25 | 16.49 | 8.65 |
| 1000 | 20 | 57.50 | 57.84 | 24.50 |
| 1000 | 50 | 331.25 | 332.27 | 98.12 |
| 1000 | 100 | 1287.50 | 1271.00 | 287.45 |
| 1000 | 150 | 2868.75 | 2874.38 | 554.81 |
| 1000 | 200 | 5075.00 | 5090.37 | 834.30 |
| 1000 | 250 | 7906.25 | 7866.99 | 1190.97 |
| 1000 | 300 | 11362.50 | 11240.06 | 1489.59 |

- In average, we observe d(d+3)/8 basis changes, which aligns with the number of basis changes theoretically proven in the paper.


### Runs for **Sharir-Welzl One Permutation Variant Algorithm**

| **Number of Repeats** | **d**   | **Average Number of Basis Changes** | **Standard Deviation** |
|---------------------|---------|-------------------------------------| ---------------|
| 1'000 | 5 | 4.939000 | 3.100789 | 
| 1'000 | 10 | 16.818000 | 10.395428 |
| 1'000 | 20 | 73.272000 | 51.090451 |
| 1'000 | 50 | 1086.459000 | 1162.721033 | 
| 1'000 | 100 | 15'961 | 18'916 |
| 1'000 | 150 | 123'510 | 184'339 |
| 1'000 | 200 | 727'927 | 1'227'171 |

- There is a high variance going on.

---


## Files

1. **`lpsw.cpp`**: Implements the Standard Sharir-Welzl Algorithm (Section 2 of the paper). Initial Start Basis is rerandomized in every run.
   - Takes `d` (number of variables) as an argument.
   - Compile and test using:
     ```bash
     g++ -o lpsw lpsw.cpp -std=c++17 -O3
     ./lpsw <d>
     ```

2. **`lpswop.cpp`**: Implements the One Permutation Variant of the Sharir-Welzl Algorithm (Section 3 of the paper). Initial Start Basis is rerandomized in every run.
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


