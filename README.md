Algorithms are taken from the paper **"Lower Bounds for a Subexponential Optimization Algorithm" by Matoušek**.  
Linear Programming Problem is from Section 4 of the paper.

---

## Run Results

I used Euler Cluster with 48 cores(maximum available number of cores without a special request).
The following tests use `d` variables and `2d` constraints.  

### Runs for **Sharir-Welzl**

| **Number of Repeats** | **d** | **d\*(d+3)/8** | **Average Number of Basis Changes** | **Standard Deviation**|
|------------------------|-------|-----------|---------------|--------|
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
|---------|---------|-------|-----------|-----------------|
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
| 10'000 | 500 | 1'126'429'600 | 5'141'851'163 | 3'363'969'994 |
| 40 | 600 | 7'004'421'118 |43'450'901'136 | 16'745'889'716 |
| 40 | 700 | 44'003'718'785 | 309'280'079'868 |  107'362'015'115 |



- There is a high variance going on.

---
### Runs for **One Permutation Variant of Sharir-Welzl (Different Bases Selections)**

| ||
|--|----|
| ![plot1](https://github.com/user-attachments/assets/55db7598-0490-4a27-a4f9-ad9f8fcca8c0) | ![plot2](https://github.com/user-attachments/assets/c9647251-f12e-4b98-89b8-9a9e4c41ab13)|



**Number of Repeats**| **d** | **All Initial Bases Randomized** | **Worst Initial Basis Chosen: (0,0,0,...)** | **Median Best Basis Chosen(1,0,0,...)** | **Quartile Best Basis Chosen(1,1,0,...)** | **$\mathbf{e^{\sqrt{d}}}$** |
--|-------|-------------------|---------|------------|--------|----|
10'000| 5     | 4.98                             | 7.31                           | 5.17                           | 3.49                             | 9.36                       |
10'000| 10    | 17.13                            | 23.61                          | 19.58                          | 15.99                            | 23.62                      |
10'000| 20    | 76.15                            | 101.53                          | 91.44                           | 79.89                            | 87.54                      |
10'000| 50    | 1040                             | 1369                           | 1281                           | 1219                          | 1177                       |
10'000| 100   | 16'517                           | 21'621                          | 20'872                          | 19'881                       | 22'026                     |
10'000| 150   | 129'847                          | 171'007                        | 163'053                         | 158'793                        | 208'449                    |
10'000| 200   | 732'461                          | 962'074                        | 933'594                         | 897'786                        | 1'386'281                  |
10'000| 250   | 3'363'161                        | 4'355'781                      | 4'240'430                       | 4'082'864                       | 7'358'657                  |
10'000| 300   | 12'945'857                       | 17'241'407                     | 16'634'965                      | 15'841'373                      | 33'281'361                 |

### Runs for **One Permutation Variant of Sharir-Welzl (Worst Basis Chosen)**

Running 100000 times for each d in: 10 50 100 200 300 400 500 600 700 800 900 1000
| **Number of Repeats** | **d** |  **Average Number of Basis Changes** | **$\mathbf{e^{\sqrt{d}}}$** | **Standard Deviation** |
|------------------------|-------|-------------------|------------------|------------------------|
| 100'000 | 10 | 23.76 | 23.624327 | 10.81 |
| 100'000 | 50 | 1379.06 | 1177.403653 | 1312.32 |
| 100'000 | 100 | 21'759.94 | 22'026.465794 | 28386.05 |
| 100'000 | 200 | 961'099.83 | 1'386'280.750628 | 1934625.93 |
| 100'000 | 300 | 16'862'009.58 | 33'281'358.719768 | 41724756.54 |
| 100'000 | 400 | 188'967'445.80 | 485'165'195.409790 | 542839461.14 |

![plot](https://github.com/user-attachments/assets/10549310-173b-44ff-90a3-60962309bb17)



## Brute-Forcing All Possible Outcomes

I brute-force all possible outcomes upto `d=6` to find the exact expected value for the one-permutation variant. For a given ``d``, there are $(2d!) \cdot 2^d$ possibilities.

### d = 1

Expected Value for d=1: 0.5
Basis: | 1 | 0 |
|--|--|--|
Expected Number of Basis Changes: | 0 | 1 |
$\text{Numerator}$ for the $\frac{\text{Numerator}}{ (2d)!}$: | 0 | 2 |

### d = 2

Expected Value for d=2: 1.25
Basis: | 1,1 | 1,0 | 0,0 | 0,1 |
|--|--|--|--|--|
Expected Number of Basis Changes: | 0 | 1 | 2 | 2 |
$\text{Numerator}$ for the $\frac{\text{Numerator}}{ (2d)!}$: | 0 | 24 | 48 | 48 |

### d = 3

Expected Value for d=3: 2.24167
Basis: | 1,1,1 | 1,1,0 | 1,0,0 | 1,0,1 | 0,0,1 | 0,1,1 | 0,1,0 | 0,0,0 |
|--|--|--|--|--|--|--|--|--|
Expected Number of Basis Changes: | 0 | 1 | 2 | 2 | 3 | 3.1 | 3.33333 | 3.5 |
$\text{Numerator}$ for the $\frac{\text{Numerator}}{ (2d)!}$: | 0 | 720 | 1440 | 1440 | 2160 | 2232 | 2400 | 2520 |

### d = 4

Expected Value for d=4: 3.48274
Basis: | 1,1,1,1 | 1,1,1,0 | 1,1,0,0 | 1,1,0,1 | 1,0,0,1 | 1,0,1,1 | 1,0,1,0 | 1,0,0,0 | 0,0,1,1 | 0,1,1,1 | 0,1,1,0 | 0,0,1,0 | 0,1,0,1 | 0,1,0,0 | 0,0,0,1 | 0,0,0,0 |
|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|
Expected Number of Basis Changes: | 0 | 1 | 2 | 2 | 3 | 3.1 | 3.33333 | 3.5 | 4.1 | 4.33333 | 4.66032 | 4.69444 | 4.70476 | 5.04206 | 5.07222 | 5.18333 |
$\text{Numerator}$ for the $\frac{\text{Numerator}}{ (2d)!}$: | 0 | 40320 | 80640 | 80640 | 120960 | 124992 | 134400 | 141120 | 165312 | 174720 | 187904 | 189280 | 189696 | 203296 | 204512 | 208992 |

### d = 5

Expected Value for d=5: 4.987
Basis: | 1,1,1,1,1 | 1,1,1,1,0 | 1,1,1,0,0 | 1,1,1,0,1 | 1,1,0,0,1 | 1,1,0,1,1 | 1,1,0,1,0 | 1,1,0,0,0 | 1,0,0,1,1 | 1,0,1,1,1 | 1,0,1,1,0 | 1,0,0,1,0 | 1,0,1,0,1 | 1,0,1,0,0 | 1,0,0,0,1 | 1,0,0,0,0 | 0,0,1,1,1 | 0,1,1,1,1 | 0,0,1,1,0 | 0,1,1,1,0 | 0,1,0,1,1 | 0,1,1,0,1 | 0,0,1,0,1 | 0,1,1,0,0 | 0,0,1,0,0 | 0,1,0,1,0 | 0,0,0,1,1 | 0,1,0,0,1 | 0,0,0,0,1 | 0,1,0,0,0 | 0,0,0,1,0 | 0,0,0,0,0 |
|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|
Expected Number of Basis Changes: | 0 | 1 | 2 | 2 | 3 | 3.1 | 3.33333 | 3.5 | 4.1 | 4.33333 | 4.66032 | 4.69444 | 4.70476 | 5.04206 | 5.07222 | 5.18333 | 5.33333 | 5.72068 | 5.9619 | 6.09562 | 6.21112 | 6.28733 | 6.47421 | 6.55101 | 6.55159 | 6.66712 | 6.80317 | 6.85242 | 6.95486 | 7.02064 | 7.06478 | 7.31052 |
$\text{Numerator}$ for the $\frac{\text{Numerator}}{ (2d)!}$: | 0 | 3628800 | 7257600 | 7257600 | 10886400 | 11249280 | 12096000 | 12700800 | 14878080 | 15724800 | 16911360 | 17035200 | 17072640 | 18296640 | 18406080 | 18809280 | 19353600 | 20759220 | 21634560 | 22119780 | 22538900 | 22815460 | 23493600 | 23772300 | 23774400 | 24193660 | 24687360 | 24866060 | 25237800 | 25476500 | 25636680 | 26528400 |

### d = 6

Expected Value for d=6: 6.77171

Basis: | 1,1,1,1,1,1 | 1,1,1,1,1,0 | 1,1,1,1,0,0 | 1,1,1,1,0,1 | 1,1,1,0,0,1 | 1,1,1,0,1,1 | 1,1,1,0,1,0 | 1,1,1,0,0,0 | 1,1,0,0,1,1 | 1,1,0,1,1,1 | 1,1,0,1,1,0 | 1,1,0,0,1,0 | 1,1,0,1,0,1 | 1,1,0,1,0,0 | 1,1,0,0,0,1 | 1,1,0,0,0,0 | 1,0,0,1,1,1 | 1,0,1,1,1,1 | 1,0,0,1,1,0 | 1,0,1,1,1,0 | 1,0,1,0,1,1 | 1,0,1,1,0,1 | 1,0,0,1,0,1 | 1,0,1,1,0,0 | 1,0,0,1,0,0 | 1,0,1,0,1,0 | 0,0,1,1,1,1 | 1,0,0,0,1,1 | 1,0,1,0,0,1 | 1,0,0,0,0,1 | 1,0,1,0,0,0 | 1,0,0,0,1,0 | 0,1,1,1,1,1 | 1,0,0,0,0,0 | 0,0,1,1,1,0 | 0,1,1,1,1,0 | 0,1,0,1,1,1 | 0,0,1,1,0,1 | 0,1,1,1,0,1 | 0,0,1,1,0,0 | 0,1,1,0,1,1 | 0,1,1,1,0,0 | 0,1,0,1,1,0 | 0,0,1,0,1,1 | 0,1,1,0,1,0 | 0,0,1,0,0,1 | 0,1,1,0,0,1 | 0,0,1,0,1,0 | 0,0,0,1,1,1 | 0,1,0,1,0,1 | 0,1,1,0,0,0 | 0,1,0,0,1,1 | 0,1,0,1,0,0 | 0,0,1,0,0,0 | 0,0,0,0,1,1 | 0,0,0,1,1,0 | 0,1,0,0,0,1 | 0,1,0,0,1,0 | 0,0,0,1,0,1 | 0,0,0,0,1,0 | 0,1,0,0,0,0 | 0,0,0,1,0,0 | 0,0,0,0,0,1 | 0,0,0,0,0,0 |
|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|
Expected Number of Basis Changes: | 0 | 1 | 2 | 2 | 3 | 3.1 | 3.33333 | 3.5 | 4.1 | 4.33333 | 4.66032 | 4.69444 | 4.70476 | 5.04206 | 5.07222 | 5.18333 | 5.33333 | 5.72068 | 5.9619 | 6.09562 | 6.21112 | 6.28733 | 6.47421 | 6.55101 | 6.55159 | 6.66712 | 6.72068 | 6.80317 | 6.85242 | 6.95486 | 7.02064 | 7.06478 | 7.27917 | 7.31052 | 7.36584 | 7.68229 | 7.88853 | 7.92365 | 7.94732 | 7.98774 | 8.07302 | 8.1715 | 8.3906 | 8.42905 | 8.4633 | 8.51934 | 8.56396 | 8.67128 | 8.72761 | 8.74586 | 8.76458 | 8.84516 | 8.86819 | 8.88659 | 8.90328 | 9.05546 | 9.11984 | 9.13092 | 9.17188 | 9.3574 | 9.41307 | 9.44023 | 9.57584 | 9.72235 |
$\text{Numerator}$ for the $\frac{\text{Numerator}}{ (2d)!}$: | 0 | 479001600 | 958003200 | 958003200 | 1437004800 | 1484904960 | 1596672000 | 1676505600 | 1963906560 | 2075673600 | 2232299520 | 2248646400 | 2253588480 | 2415156480 | 2429602560 | 2482824960 | 2554675200 | 2740217040 | 2855761920 | 2919810960 | 2975134800 | 3011640720 | 3101155200 | 3137943600 | 3138220800 | 3193563120 | 3219218640 | 3258731520 | 3282319920 | 3331389600 | 3362898000 | 3384041760 | 3486734160 | 3501748800 | 3528249120 | 3679827600 | 3778616712 | 3795440616 | 3806778480 | 3826140648 | 3866988672 | 3914163720 | 4019110536 | 4037528352 | 4053935160 | 4080778944 | 4102151208 | 4153556352 | 4180538208 | 4189280472 | 4198250016 | 4236846120 | 4247876952 | 4256690592 | 4264686624 | 4337577552 | 4368419688 | 4373725584 | 4393347552 | 4482209424 | 4508874360 | 4521887040 | 4586844768 | 4657020720 |




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
4. **`bruteforce.cpp`**: Used for finding the exact expected value of one-permutation variant.
   - For a given D, for every d in [1,...,D] prints the exact expected value and the expected value for every basis choice.
   - Compile and test using:
     ```bash
     g++ -o bruteforce bruteforce.cpp -std=c++17 -O3
     ./bruteforce <D>
     ```
   - Runtime for D is $\Omega((2D)! \cdot 2^D)$, so only works up to D=5.



5. **`runlpsw.sh`**: A bash script for parallelizing the runs of `lpsw.cpp`. Uses all the cores available.
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
      
6. **`runlpswop.sh`**: A bash script for parallelizing the runs of `lpswop.cpp`. Uses all the cores available.
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

7. **`runfastlpswop.sh`**: A bash script for parallelizing the runs of `fastlpswop.cpp`. Uses all the cores available.
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
