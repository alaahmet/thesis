Algorithms are taken from the paper **"Lower Bounds for a Subexponential Optimization Algorithm" by Matoušek**.  
Linear Programming Problem is from Section 4 of the paper.

---

## Run Results

![plot](https://github.com/user-attachments/assets/bd4a3107-3f68-41bc-b302-80439871db06)



I used Euler Cluster with 48 cores(maximum available number of cores without a special request).
The following tests use `d` variables and `2d` constraints.  

### Runs for **Sharir-Welzl**

| **Number of Repeats** | **d** | **d\*(d+3)/8** | **Average Number of Basis Changes** | **Standard Deviation**|
|------------------------|-------|---------------|-------------------------------------|--------|
| 100'000 | 5 | 5.00 | 5.00 | 3.09 |
| 100'000 | 10 | 16.25 | 16.26 | 8.54 |
| 100'000 | 20 | 57.50 | 57.66 | 24.67 |
| 100'000 | 50 | 331.25 | 331.43 | 100.74 |
| 100'000 | 100 | 1287.50 | 1287.10 | 289.04 |
| 100'000 | 150 | 2868.75 | 2868.48 | 534.65 |
| 100'000 | 200 | 5075.00 | 5072.85 | 831.59 |
| 100'000 | 250 | 7906.25 | 7909.34 | 1168.91 |
| 100'000 | 300 | 11362.50 | 11352.50 | 1534.01 |
| 100'000 | 400 | 20150.00 | 20140.51 | 2378.50 |


- We observe around d(d+3)/8 basis changes, which aligns with the number of basis changes theoretically proven in the paper.


### Runs for **One Permutation Variant of Sharir-Welzl**


| **Number of Repeats** | **d**   | **Average Number of Basis Changes** | **$\mathbf{e^{\sqrt{d}}}$** | **Standard Deviation** |
|-----------------------|---------|-------------------------------------|------------------------|-----------------------------|
| 100'000               | 5       | 4.98                                | 9.36                   | 3.17                        |
| 100'000               | 10      | 17.13                               | 23.62                  | 10.98                       |
| 100'000               | 20      | 76.15                               | 87.54                  | 56.67                       |
| 100'000               | 50      | 1040.44                             | 1177.40                | 1088.33                     |
| 100'000               | 100     | 16'517                              | 22'026                 | 24'172                      |
| 100'000               | 150     | 129'847                             | 208'449                | 232'435                     |
| 100'000               | 200     | 732'461                             | 1'386'282              | 1'429'494                   |
| 100'000               | 250     | 3'363'161                           | 7'358'659              | 8'576'896                   |
| 100'000               | 300     | 12'945'857                          | 33'281'361             | 37'933'793                  |
| 100'000               | 400     | 142'997'652                         | 485'165'195            | 411'153'281                 |



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
3. **`fastlpswop.cpp`**: Faster running version of `lpswop.cpp`.
   - The number of variables `d` is defined using a preprocesser macro `DVAL`, which defaults to 10 if not specified.
   - Compile and test using:
     ```bash
     g++ -o fastlpswop fastlpswop.cpp -std=c++17 -O3 -DDVAL=<d>
     ./fastlpswop
     ```

4. **`runlpsw.sh`**: A bash script for parallelizing the runs of `lpsw.cpp`. Uses all the cores available.
   - Before running the script for the first time, make it executable:
     ```bash
     chmod +x runlpsw.sh
     ```
   - Option 0:
       - Takes 'r' (number of repeats) and 'd' (number of variables).
         ```bash
         ./runlpsw.sh <r> 0 <d>
         ```
   - Option 1:
       - Takes 'r' (number of repeats), while the list of variable values 'd' is hardcoded in `runlpsw.sh`. This option was primarily designed to genereate runtime table for multiple d values in a single run.
         ```bash
         ./runlpsw.sh <r> 1
         ```
      
5. **`runlpswop.sh`**: A bash script for parallelizing the runs of `lpswop.cpp`. Uses all the cores available.
   - Before running the script for the first time, make it executable:
     ```bash
     chmod +x runlpswop.sh
     ```
   - Option 0:
       - Takes 'r' (number of repeats) and 'd' (number of variables).
         ```bash
         ./runlpswop.sh <r> 0 <d>
         ```
   - Option 1:
       - Takes 'r' (number of repeats), while the list of variable values 'd' is hardcoded in `runlpswop.sh`. This option was primarily designed to genereate runtime table for multiple d values in a single run.
         ```bash
         ./runlpswop.sh <r> 1
         ```

6. **`runfastlpswop.sh`**: A bash script for parallelizing the runs of `fastlpswop.cpp`. Uses all the cores available.
   - Before running the script for the first time, make it executable:
     ```bash
     chmod +x runfastlpswop.sh
     ```
   - Option 0:
       - Takes 'r' (number of repeats) and 'd' (number of variables).
         ```bash
         ./runfastlpswop.sh <r> 0 <d>
         ```
   - Option 1:
       - Takes 'r' (number of repeats), while the list of variable values 'd' is hardcoded in `runfastlpswop.sh`. This option was primarily designed to genereate runtime table for multiple d values in a single run.
         ```bash
         ./runfastlpswop.sh <r> 1
         ```
7. **`plot.py`**: It plots the average number of basis changes against the number of variables (d) for both algorithms. The y-axis uses a logarithmic scale to handle the large range of values
