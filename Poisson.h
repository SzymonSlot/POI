#ifndef POISSON_H
#define POISSON_H

#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <algorithm> 

class Poisson {
public:
    double S = 0.0;
    double w;
    int N;
    int size;
    double d = 4.0;
    double x0 = 4.0;
    double del = 0.001;
    double beta = 0.001;
    double r = 0.5;

    std::vector<std::vector<double>> u;
    std::vector<std::vector<double>> rho;
    std::vector<std::vector<double>> rho_prim;

    Poisson(int N, double w = 1.0);

    void krok(); // zadania 1 i 2
    void krok_S(); // zadanie 3
    void krok_grad_S(); // zadanie 4
    void krok_rand(); // zadanie 5
    void oblicz_rho_prim();
    std::vector<std::vector<double>> delta_rho();

private:
    void init_rho();
    void oblicz_S();
    double S_loc(int, int, double dleta = 0.0);
};

#endif
