#include <iostream>
#include "funkcje.h"
#include "Poisson.h"

int main(){
    int N = 31;
    Poisson poi(N);
    int iteracje = 500;
    std::ofstream plik_r_S("./zad5/r_S_zad5.txt");
    std::ofstream plik_S("./zad5/S_zad5.txt");

    // std::vector<double> rs = {0.01, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1, 0.11, 0.2, 0.3, 0.4, 0.5, 0.6};
    plik_S<<"r\n";
    plik_r_S<<"r i\n";
    bool flag = true;

    // for(double r: rs){
    for(double r=0.001; r<2; r+=0.001){
        Poisson poi(N);
        poi.r = r;
        plik_S<<r<<" ";
        for(int i=0; i<iteracje; i++){
            poi.krok_rand();

            plik_S<<poi.S<<" ";

            if(poi.S <= -255.017 && flag) {
                plik_r_S<<r<<" "<<i<<"\n";
                flag = false;
            }
        }
        plik_S<<"\n";
        flag = true;
    }

    plik_S.close();
    zapisz_do_pliku(poi.delta_rho(), "./zad5/delta_rho_zad5.txt");
    zapisz_do_pliku(poi.u, "./zad5/u_500_zad5.txt");
}