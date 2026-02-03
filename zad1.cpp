#include <iostream>
#include "Poisson.h"
#include "funkcje.h"
#define N 31

int main() {
    Poisson poi(N);
    long long int iteracje = 500;
    zapisz_do_pliku(poi.rho, "./zad1/rho_zad1.txt");
    std::ofstream plik_S("./zad1/S_zad1.txt");

    for(int i = 0; i < iteracje; ++i){
        poi.krok();

        plik_S<<poi.S<<" ";

        if(i == 100){
            zapisz_do_pliku(poi.u, "./zad1/u_100_zad1.txt");
            poi.oblicz_rho_prim();
            zapisz_do_pliku(poi.rho_prim, "./zad1/rho_prim_100_zad1.txt");
            zapisz_do_pliku(poi.delta_rho(), "./zad1/delta_rho_100_zad1.txt");
        }            
    }

    plik_S.close();
    poi.oblicz_rho_prim();
    zapisz_do_pliku(poi.u, "./zad1/u_500_zad1.txt");
    zapisz_do_pliku(poi.rho_prim, "./zad1/rho_prim_zad1.txt");
    zapisz_do_pliku(poi.delta_rho(), "./zad1/delta_rho_zad1.txt");
}
