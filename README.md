Algorithms are taken from the paper **"Lower Bounds for a Subexponential Optimization Algorithm" by Matoušek**.  
Linear Programming Problem is from Section 4 of the paper.

---

## Run Results

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


### Runs for **One Permutation Variant of Sharir-Welzl (Initial Basis Randomized)**

![plot](https://github.com/user-attachments/assets/53827f19-54c3-4c46-a578-21db37d48fe9)


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
| 40 | 500 | 1'123'437'722 |5'141'855'147 | 1'775'601'485 |
| 40 | 600 | 7'004'421'118 |43'450'901'136 | 16'745'889'716 |
| 40 | 700 | 44'003'718'785 | 309'280'079'868 |  107'362'015'115 |



- There is a high variance going on.

---
### Runs for **One Permutation Variant of Sharir-Welzl (Different Bases Selections)**

**Number of Repeats**| **d** | **All Initial Bases Randomized** | **Worst Initial Basis Chosen: (0,0,0,...)** | **Middle Ranked Basis Chosen(1,0,0,...)** | **$\mathbf{e^{\sqrt{d}}}$** |
--|-------|----------------------------------|--------------------------------|--------------------------------|-----------------------------|
10'000| 5     | 4.98                             | 7.31                           | 5.17                           | 9.36                       | 
10'000| 10    | 17.13                            | 23.61                          | 19.58                          | 23.62                      | 
10'000| 50    | 1040                          | 1369                        | 1281                        | 1177                    | 
10'000| 100   | 16'517                           | 21'621                      | 20'872                      | 22'026                     | 
10'000| 150   | 129'847                          | 171'007                        | 163'053                     | 208'449                    | 
10'000| 200   | 732'461                          | 962'074                        | 933'594                     | 1'386'281                  | 
10'000| 250   | 3'363'161                        | 4'355'781                      | 4'240'430                   | 7'358'657                  | 
10'000| 300   | 12'945'857                       | 17'241'407                     | 16'634'965               | 33'281'361                 |



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





## Brute-Forcing All Possible Outcomes

I brute-force all possible outcomes upto d=5 to find the exact expected value for the one-permutation variant.

### $d=1$

$\mu=0.5$

Basis: | 1 | 0 |
|--|--|--|
Expected Number of Basis Changes: | 0 | 1 |


### $d=2$

$\mu=1.25$

Basis: | 1,1 | 1,0 | 0,0 | 0,1 |
|--|--|--|--|--|
Expected Number of Basis Changes: | 0 | 1 | 2 | 2 |




### $d=3$

$\mu=2.24167$

Basis: | 1,1,1 | 1,1,0 | 1,0,0 | 1,0,1 | 0,0,1 | 0,1,1 | 0,1,0 | 0,0,0 |
|--|--|--|--|--|--|--|--|--|
Expected Number of Basis Changes: | 0 | 1 | 2 | 2 | 3 | 3.1 | 3.33333 | 3.5 |

### $d=4$

$\mu=3.48274$


Basis: | 1,1,1,1 | 1,1,1,0 | 1,1,0,0 | 1,1,0,1 | 1,0,0,1 | 1,0,1,1 | 1,0,1,0 | 1,0,0,0 | 0,0,1,1 | 0,1,1,1 | 0,1,1,0 | 0,0,1,0 | 0,1,0,1 | 0,1,0,0 | 0,0,0,1 | 0,0,0,0 |
|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|
Expected Number of Basis Changes: | 0 | 1 | 2 | 2 | 3 | 3.1 | 3.33333 | 3.5 | 4.1 | 4.33333 | 4.66032 | 4.69444 | 4.70476 | 5.04206 | 5.07222 | 5.18333 |

### $d=5$

$\mu=4.987$

Basis: | 1,1,1,1,1 | 1,1,1,1,0 | 1,1,1,0,0 | 1,1,1,0,1 | 1,1,0,0,1 | 1,1,0,1,1 | 1,1,0,1,0 | 1,1,0,0,0 | 1,0,0,1,1 | 1,0,1,1,1 | 1,0,1,1,0 | 1,0,0,1,0 | 1,0,1,0,1 | 1,0,1,0,0 | 1,0,0,0,1 | 1,0,0,0,0 | 0,0,1,1,1 | 0,1,1,1,1 | 0,0,1,1,0 | 0,1,1,1,0 | 0,1,0,1,1 | 0,1,1,0,1 | 0,0,1,0,1 | 0,1,1,0,0 | 0,0,1,0,0 | 0,1,0,1,0 | 0,0,0,1,1 | 0,1,0,0,1 | 0,0,0,0,1 | 0,1,0,0,0 | 0,0,0,1,0 | 0,0,0,0,0 |
|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|
Expected Number of Basis Changes: | 0 | 1 | 2 | 2 | 3 | 3.1 | 3.33333 | 3.5 | 4.1 | 4.33333 | 4.66032 | 4.69444 | 4.70476 | 5.04206 | 5.07222 | 5.18333 | 5.33333 | 5.72068 | 5.9619 | 6.09562 | 6.21112 | 6.28733 | 6.47421 | 6.55101 | 6.55159 | 6.66712 | 6.80317 | 6.85242 | 6.95486 | 7.02064 | 7.06478 | 7.31052 |
