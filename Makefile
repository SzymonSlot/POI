# Domyślny cel
all: zad1_plot zad2_plot fast_plot_S

# ===============================
# Zadanie 1
# ===============================

zad1.exe: zad1.cpp Poisson.cpp funkcje.cpp
	g++ -o zad1.exe zad1.cpp Poisson.cpp funkcje.cpp

zad1_run: zad1.exe
	zad1.exe

zad1_plot: zad1_run
	python zad1_plot.py ./zad1/S_zad1.txt ./zad1/rho_prim_zad1.txt ./zad1/delta_rho_zad1.txt ./zad1/u_500_zad1.txt ./zad1/u_100_zad1.txt ./zad1/rho_zad1.txt ./zad1/rho_prim_100_zad1.txt ./zad1/delta_rho_100_zad1.txt

# ===============================
# Zadanie 2
# ===============================

zad2.exe: zad2.cpp Poisson.cpp funkcje.cpp
	g++ -o zad2.exe zad2.cpp Poisson.cpp funkcje.cpp

zad2_run: zad2.exe
	zad2.exe

zad2_plot: zad2_run
	python zad2_plot.py ./zad2/S_zad2.txt ./zad2/rho_prim_zad2.txt ./zad2/delta_rho_zad2.txt ./zad2/u_500_zad2.txt

# ===============================
# Zadanie 3
# ===============================


zad3.exe: zad3.cpp Poisson.cpp funkcje.cpp
	g++ -o zad3.exe zad3.cpp Poisson.cpp funkcje.cpp

zad3_run: zad3.exe
	zad3.exe

zad3_plot: zad3_run
	python zad3_plot.py ./zad1/S_zad3.txt ./zad1/rho_prim_zad3.txt ./zad1/delta_rho_zad3.txt

# ===============================
# Zadanie 4
# ===============================

zad4.exe: zad4.cpp Poisson.cpp funkcje.cpp
	g++ -o zad4.exe zad4.cpp Poisson.cpp funkcje.cpp

zad4_run: zad4.exe
	zad4.exe

# ===============================
# Zadanie 5
# ===============================

zad5.exe: zad5.cpp Poisson.cpp funkcje.cpp
	g++ -o zad5.exe zad5.cpp Poisson.cpp funkcje.cpp

zad5_run: zad5.exe
	zad5.exe

# zad4_plot: zad3_run
# 	python zad3_plot.py S_zad3.txt rho_prim_zad3.txt delta_rho_zad3.txt

# ===============================
# Sprzątanie
# ===============================

plot_S: zad1_run zad2_run zad3_run zad4_run zad5_run
	python S_plot.py ./zad1/S_zad1.txt ./zad2/S_zad2.txt ./zad3/S_zad3.txt ./zad4/S_zad4.txt ./zad5/S_zad5.txt ./zad4/beta_S_zad4.txt

fast_plot_S:
	python S_plot.py ./zad1/S_zad1.txt ./zad2/S_zad2.txt ./zad3/S_zad3.txt ./zad4/S_zad4.txt ./zad5/S_zad5.txt ./zad4/beta_S_zad4.txt

clean:
	del /Q *.txt *.exe
