import matplotlib.pyplot as plt

# Data for Sharir-Welzl One Permutation Variant Algorithm
d_one_perm = [5, 10, 20, 50, 100, 150, 200, 250]
avg_basis_changes_one_perm = [4.94, 16.82, 73.27, 1086.45, 15961, 123510, 727927, 3171021]

# Data for Sharir-Welzl Standard Algorithm
d_standard = d_one_perm
avg_basis_changes_standard = [d * (d + 3) / 8 for d in d_standard]

plt.figure(figsize=(10, 6))
plt.plot(d_standard, avg_basis_changes_standard, label='Sharir-Welzl', marker='o')
plt.plot(d_one_perm, avg_basis_changes_one_perm, label='One Permutation Variant', marker='s')
plt.xlabel('d (number of variables)', fontsize=12)
plt.ylabel('Average Number of Basis Changes', fontsize=12)
plt.title('Comparison of Basis Changes', fontsize=14)
plt.legend()
plt.grid(True)
plt.yscale('log')
plt.savefig('/home/ahmet/thesis/plot.png')
plt.show()
