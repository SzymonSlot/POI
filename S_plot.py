import matplotlib.pyplot as plt
import sys 
import pandas as pd

plik_S_z1 = sys.argv[1]
plik_S_z2 = sys.argv[2]
plik_S_z3 = sys.argv[3]
plik_S_z4 = sys.argv[4]
plik_S_z5 = sys.argv[5]
plik_r_i = sys.argv[6]

S1 = pd.read_csv(plik_S_z1, delim_whitespace=True, header=None)
S2 = pd.read_csv(plik_S_z2, delim_whitespace=True, header=None)
S3 = pd.read_csv(plik_S_z3, delim_whitespace=True, header=None)
S4 = pd.read_csv(plik_S_z4, delim_whitespace=True, header=None, skiprows=1)
S5 = pd.read_csv(plik_S_z5, delim_whitespace=True, header=None, skiprows=1)
r_i = pd.read_csv(plik_r_i, delim_whitespace=True)

plt.scatter(range(1, len(S1.iloc[0]) + 1), S1.iloc[0], label="relaksacja", s=10)
plt.scatter(range(1, len(S2.iloc[0]) + 1), S2.iloc[0], label="nadrelaksacja", s=10)
plt.xlabel("Numer iteracji", fontsize=14)
plt.ylabel("S", fontsize=14)
plt.grid(True)
plt.legend()
plt.tick_params(axis='both', which='major', labelsize=14)
plt.savefig("./plots/S_porow_z2.png", dpi=300, bbox_inches="tight")
plt.close()

plt.plot(range(1, len(S1.iloc[0]) + 1), S1.iloc[0], label="relaksacja")
plt.scatter(range(1, len(S1.iloc[0]) + 1), S1.iloc[0], s=1)
plt.scatter(range(1, len(S2.iloc[0]) + 1), S2.iloc[0], label="nadrelaksacja", s=10)
plt.scatter(range(1, len(S3.iloc[0]) + 1), S3.iloc[0], label="zad3", s=10, alpha=0.5, c="red")
plt.xlabel("Numer iteracji", fontsize=14)
plt.ylabel("S", fontsize=14)
plt.legend()
plt.grid(True)
plt.tick_params(axis='both', which='major', labelsize=14)
plt.savefig("./plots/S_porow_z3.png", dpi=300, bbox_inches="tight")
plt.close()

plt.scatter(range(1, len(S1.iloc[0]) + 1), S1.iloc[0], label="relaksacja", s=10)
plt.scatter(range(1, len(S2.iloc[0]) + 1), S2.iloc[0], label="nadrelaksacja", s=10)
plt.scatter(range(1, len(S4.iloc[5][1:]) + 1), S4.iloc[5][1:], label=r"$\beta = 0.477$", s=10)
plt.xlabel("Numer iteracji", fontsize=14)
plt.ylabel("S", fontsize=14)
plt.legend()
plt.grid(True)
plt.tick_params(axis='both', which='major', labelsize=14)
plt.savefig("./plots/S_porow_z4.png", dpi=300, bbox_inches="tight")
plt.close()

idxmin = S5[len(S5.iloc[0])-1].argmin()

plt.scatter(range(1, len(S1.iloc[0]) + 1), S1.iloc[0], label="relaksacja", s=10)
plt.scatter(range(1, len(S2.iloc[0]) + 1), S2.iloc[0], label="nadrelaksacja", s=10)
plt.scatter(range(1, len(S5.iloc[idxmin][1:]) + 1), S5.iloc[idxmin][1:], label=f"r={S5.iloc[idxmin][0]}", s=10)
plt.xlabel("Numer iteracji", fontsize=14)
plt.ylabel("S", fontsize=14)
plt.legend()
plt.grid(True)
plt.tick_params(axis='both', which='major', labelsize=14)
plt.savefig("./plots/S_porow_z5_2.png", dpi=300, bbox_inches="tight")
plt.close()

plt.scatter(S5[0], S5[len(S5.iloc[0])-1], s=10)
plt.xlabel("r", fontsize=14)
plt.ylabel("S", fontsize=14)
plt.grid(True)
plt.tick_params(axis='both', which='major', labelsize=14)
plt.savefig("./plots/S(r)_2.png", dpi=300, bbox_inches="tight")
plt.close()

plt.scatter(r_i["beta"], r_i["i"], s=10)
plt.xlabel(r"$\beta$", fontsize=14)
plt.ylabel("Liczba iteracji", fontsize=14)
plt.grid(True)
plt.tick_params(axis='both', which='major', labelsize=14)
plt.savefig("./plots/i(beta).png", dpi=300, bbox_inches="tight")
plt.close()