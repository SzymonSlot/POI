import matplotlib.pyplot as plt
import sys 
import pandas as pd

plik_S = sys.argv[1]
plik_rho_prim = sys.argv[2]
plik_delta = sys.argv[3]
# plik_u500 = sys.argv[4]

S = pd.read_csv(plik_S, delim_whitespace=True, header=None)
rho = pd.read_csv(plik_rho_prim, delim_whitespace=True, header=None)
delta = pd.read_csv(plik_delta, delim_whitespace=True, header=None)
# u500 = pd.read_csv(plik_u500, delim_whitespace=True, header=None)

plt.plot(range(1, len(S.iloc[0]) + 1), S.iloc[0])
plt.xlabel("Numer iteracji", fontsize=14)
plt.ylabel("S", fontsize=14)
plt.grid(True)
plt.tick_params(axis='both', which='major', labelsize=14)
plt.savefig("./plots/S_zad2.png", dpi=300, bbox_inches="tight")
plt.close()

fig, ax = plt.subplots()
im_delta = ax.imshow(rho, cmap='bwr')
ax.tick_params(axis='both', length=0, labelbottom=False, labelleft=False)
ax.set_xlabel("x", fontsize = 14)
ax.set_ylabel("y", fontsize = 14)
fig.colorbar(im_delta, ax=ax, label=r"$\rho'$")
fig.savefig("./plots/rho_prim_zad2.png", dpi=300, bbox_inches="tight")
plt.close(fig)

fig, ax = plt.subplots()
im_delta = ax.imshow(delta, cmap='bwr')
ax.tick_params(axis='both', length=0, labelbottom=False, labelleft=False)
ax.set_xlabel("x", fontsize = 14)
ax.set_ylabel("y", fontsize = 14)
fig.colorbar(im_delta, ax=ax, label=r"$\delta(x,y)$")
fig.savefig("./plots/delta_rho_zad2.png", dpi=300, bbox_inches="tight")
plt.close(fig)