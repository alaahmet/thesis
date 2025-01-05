import numpy as np
from math import sqrt

import matplotlib.pyplot as plt

# Data for Sharir-Welzl One Permutation Variant Algorithm
d_one_perm = [5, 10, 20, 50, 100, 150, 200, 250, 300, 400]
avg_basis_changes_one_perm = [4.98, 17.13, 76.15, 1040, 16517, 129847, 732461, 3363161, 12945857, 142997652]

# Using the formula for standard Sharir-Welzl Algorithm.
d_standard = d_one_perm
avg_basis_changes_standard = [d * (d + 3) / 8 for d in d_standard]

# Calculate e^d
exp_d = [np.exp(sqrt(d)) for d in d_standard]

plt.figure(figsize=(10, 6))
plt.plot(d_standard, avg_basis_changes_standard, label=r'Sharir-Welzl: $d(d+3)/8$', marker='o')
plt.plot(d_one_perm, avg_basis_changes_one_perm, label=r'One Permutation Variant: Average of $10^5$ repetitions', marker='s')
plt.plot(d_standard, exp_d, label=r'$e^{\sqrt{d}}$', marker='^', color='lightgrey')
plt.xlabel('d (Number of Variables)', fontsize=12)
plt.ylabel('Number of Basis Changes (Log Scale)', fontsize=12)
plt.title('Comparison of Basis Changes', fontsize=14)
plt.legend()
plt.grid(True)
plt.yscale('log')
plt.savefig('/home/ahmet/thesis/plot.png')
plt.show()
