import matplotlib.pyplot as plt
import sys 
import pandas as pd

# Argumenty
plik_S = sys.argv[1]
plik_rho = sys.argv[2]
plik_delta = sys.argv[3]
plik_u500 = sys.argv[4]
plik_u100 = sys.argv[5]
plik_rho_org = sys.argv[6]
plik_rho_prim_100 = sys.argv[7]
plik_delta_rho_100 = sys.argv[8]

# Wczytaj dane
S = pd.read_csv(plik_S, delim_whitespace=True, header=None)
rho = pd.read_csv(plik_rho, delim_whitespace=True, header=None)
delta = pd.read_csv(plik_delta, delim_whitespace=True, header=None)
u500 = pd.read_csv(plik_u500, delim_whitespace=True, header=None)
u100 = pd.read_csv(plik_u100, delim_whitespace=True, header=None)
rho_org = pd.read_csv(plik_rho_org, delim_whitespace=True, header=None)
rho_prim_100 = pd.read_csv(plik_rho_prim_100, delim_whitespace=True, header=None)
rho_delta_rho_100 = pd.read_csv(plik_delta_rho_100, delim_whitespace=True, header=None)

plt.scatter(range(1, len(S.iloc[0]) + 1), S.iloc[0], s=5)
plt.xlabel("Numer iteracji", fontsize=14)
plt.ylabel("S", fontsize=14)
plt.grid(True)
plt.tick_params(axis='both', which='major', labelsize=14)
plt.savefig("./plots/S_zad1.png", dpi=300, bbox_inches="tight")
plt.close()

fig, ax = plt.subplots()
im_delta = ax.imshow(rho, cmap='bwr')
ax.tick_params(axis='both', length=0, labelbottom=False, labelleft=False)
ax.set_xlabel("x", fontsize = 14)
ax.set_ylabel("y", fontsize = 14)
fig.colorbar(im_delta, ax=ax, label=r"$\rho'$")
fig.savefig("./plots/rho_prim_zad1.png", dpi=300, bbox_inches="tight")
plt.close(fig)

fig, ax = plt.subplots()
im_delta = ax.imshow(rho_org, cmap='bwr')
ax.tick_params(axis='both', length=0, labelbottom=False, labelleft=False)
ax.set_xlabel("x", fontsize = 14)
ax.set_ylabel("y", fontsize = 14)
fig.colorbar(im_delta, ax=ax, label=r"$\rho$")
fig.savefig("./plots/rho_org.png", dpi=300, bbox_inches="tight")
plt.close(fig)

fig, ax = plt.subplots()
im_delta = ax.imshow(delta, cmap='bwr')
ax.tick_params(axis='both', length=0, labelbottom=False, labelleft=False)
ax.set_xlabel("x", fontsize = 14)
ax.set_ylabel("y", fontsize = 14)
fig.colorbar(im_delta, ax=ax, label=r"$\delta(x,y)$")
fig.savefig("./plots/delta_rho_zad1.png", dpi=300, bbox_inches="tight")
plt.close(fig)

fig, ax = plt.subplots()
im_delta = ax.imshow(u500, cmap='bwr')
ax.tick_params(axis='both', length=0, labelbottom=False, labelleft=False)
ax.set_xlabel("x", fontsize = 14)
ax.set_ylabel("y", fontsize = 14)
fig.colorbar(im_delta, ax=ax, label=r"u")
fig.savefig("./plots/u500_zad1.png", dpi=300, bbox_inches="tight")
plt.close(fig)

fig, ax = plt.subplots()
im_delta = ax.imshow(u100, cmap='bwr')
ax.tick_params(axis='both', length=0, labelbottom=False, labelleft=False)
ax.set_xlabel("x", fontsize = 14)
ax.set_ylabel("y", fontsize = 14)
fig.colorbar(im_delta, ax=ax, label=r"u")
fig.savefig("./plots/u100_zad1.png", dpi=300, bbox_inches="tight")
plt.close(fig)

fig, ax = plt.subplots()
im_delta = ax.imshow(rho_delta_rho_100, cmap='bwr')
ax.tick_params(axis='both', length=0, labelbottom=False, labelleft=False)
ax.set_xlabel("x", fontsize = 14)
ax.set_ylabel("y", fontsize = 14)
fig.colorbar(im_delta, ax=ax, label=r"$\delta(x,y)$")
fig.savefig("./plots/delta_rho_100_zad1.png", dpi=300, bbox_inches="tight")
plt.close(fig)

fig, ax = plt.subplots()
im_delta = ax.imshow(rho_prim_100, cmap='bwr')
ax.tick_params(axis='both', length=0, labelbottom=False, labelleft=False)
ax.set_xlabel("x", fontsize = 14)
ax.set_ylabel("y", fontsize = 14)
fig.colorbar(im_delta, ax=ax, label=r"$\delta(x,y)$")
fig.savefig("./plots/rho_100_zad1.png", dpi=300, bbox_inches="tight")
plt.close(fig)