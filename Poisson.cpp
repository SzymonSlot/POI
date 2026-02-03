#include "Poisson.h"
#include <iostream>

Poisson::Poisson(int N, double w): N(N), w(w), size(2*N+1)
{
    u.resize(size, std::vector<double>(size, 0.0));
    rho.resize(size, std::vector<double>(size, 0.0));
    rho_prim.resize(size, std::vector<double>(size, 0.0));
    init_rho();
}

void Poisson::init_rho() {
    for (int i = 0; i < size; i++) {
        int x = i - N;
        for (int j = 0; j < size; j++) {
            int y = j - N;
            double val1 = std::exp(-((x - x0)*(x - x0) + y*y) / (d*d));
            double val2 = std::exp(-((x + x0)*(x + x0) + y*y) / (d*d));
            rho[i][j] = val1 - val2;
        }
    }
}

// zadania 1 i 2
void Poisson::krok() {
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            double u_ij = (u[i + 1][j] + u[i - 1][j] + u[i][j + 1] + u[i][j - 1] + rho[i][j])*0.25;
            u[i][j] = (1 - w) * u[i][j] + w * u_ij;
        }
    }
    oblicz_S();
}

void Poisson::oblicz_rho_prim() {
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            rho_prim[i][j] = -(u[i + 1][j] + u[i - 1][j] + u[i][j - 1] + u[i][j + 1] - 4 * u[i][j]);
        }
    }
}

void Poisson::oblicz_S() {
    S = 0.0;
    for (int i = 1; i < size - 1; i++) {
        for (int j = 1; j < size - 1; j++) {
            S += - (0.5 * u[i][j] * (u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1] - 4.0 * u[i][j]) + rho[i][j] * u[i][j]);
        }
    }
}

std::vector<std::vector<double>> Poisson::delta_rho(){
    std::vector<std::vector<double>> delta_rho(size, std::vector<double>(size, 0));
    for (size_t i = 0; i < size; ++i){
        for (size_t j = 0; j < size; ++j){
            delta_rho[i][j] = rho_prim[i][j] - rho[i][j];
        }
    }
    return delta_rho;
}


double Poisson::S_loc(int i, int j, double delta){
    double uij = u[i][j] + delta;
    return -0.5*(2*uij*(u[i+1][j] + u[i-1][j] + u[i][j+1] + u[i][j-1]) - 4*std::pow(uij,2)) - rho[i][j]*uij;
}

// zadanie 3
void Poisson::krok_S(){
    for(int i = 1; i<size-1; i++){
        for(int j = 1; j<size-1; j++){
            double Sloc = S_loc(i,j);
            double S1 = S;
            double S2 = S - Sloc + S_loc(i,j,0.5);
            double S3 = S - Sloc + S_loc(i,j,1);

            double delta4 = 0.25*(3*S1-4*S2+S3)/(S1-2*S2+S3);
            double S4 = S - Sloc + S_loc(i,j,delta4);

            std::vector<double> S_values = {S1, S2, S3, S4};
            std::vector<double> deltas = {0.0, 0.5, 1.0, delta4};

            int min_index = 0;
            for (int k = 1; k < 4; ++k) {
                if (S_values[k] < S_values[min_index]) {
                    min_index = k;
                }
            }

            double delta_min = deltas[min_index];

            u[i][j] += delta_min;
            S = S_values[min_index];
        }
    }
    oblicz_S();
}

// zadanie 4
void Poisson::krok_grad_S(){
    for (int i = 1; i < 2 * N; ++i) {
        for (int j = 1; j < 2 * N; ++j) {
            double Sloc = S_loc(i,j);
            double Splus = S - Sloc + S_loc(i,j,del);
            double Sminus = S - Sloc + S_loc(i,j,-del);
            double grad_S = (Splus-Sminus)/(2*del);

            S = S - Sloc + S_loc(i,j,-beta*grad_S);
            u[i][j] -= beta*grad_S;
        }
    }
    oblicz_S();
}

// zadanie 5
void Poisson::krok_rand(){
    // double rd = (2.0*rand()/ RAND_MAX - 1.0) * r;
    for (int i = 1; i < 2 * N; ++i) {
        for (int j = 1; j < 2 * N; ++j) {
            double rd = (2.0*rand()/ RAND_MAX - 1.0) * r;
            u[i][j] += S_loc(i,j) > S_loc(i,j,rd) ? rd:0.0;
        }
    }
    oblicz_S();
}