#include <iostream>
#include "funkcje.h"
#include "Poisson.h"

int main(){
    int N = 31;
    int iteracje = 500;
    std::ofstream plik_S("./zad4/S_zad4.txt");
    std::ofstream plik_beta_S("./zad4/beta_S_zad4.txt");

    // std::vector<double> betas = {0.5, 0.49, 0.48, 0.479, 0.478, 0.477, 0.476, 0.475, 0.474, 0.473, 0.47, 0.46, 0.45, 0.44, 0.43, 0.42, 0.41, 0.4, 0.3, 0.39, 0.38, 0.37, 0.36, 0.35, 0.34, 0.33, 0.32, 0.31, 0.2, 0.1, 0.05, 0.01, 0.005, 0.001, 0.0005, 0.0001};
    plik_S<<"beta\n";
    plik_beta_S<<"beta i\n";
    bool flag = true;

    for(double beta=0.4; beta<=0.5; beta += 0.001){
        Poisson poi(N);
        poi.beta = beta;
        plik_S<<beta<<" ";
        for(int i=0; i<iteracje; i++){
            poi.krok_grad_S();

            plik_S<<poi.S<<" ";

            if(poi.S < -255.017 && flag) {
                plik_beta_S<<beta<<" "<<i<<"\n";
                flag = false;
            }
        }
        plik_S<<"\n";
        flag = true;
    }

    plik_S.close();
    plik_beta_S.close();
    // zapisz_do_pliku(poi.delta_rho(), "./zad4/delta_rho_zad4.txt");
}