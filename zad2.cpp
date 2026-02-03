#include <iostream>
#include "Poisson.h"
#include "funkcje.h"
#define N 31

int main() {
    Poisson poi(N, 1.9);
    long long int iteracje = 500;
    std::ofstream plik_S("./zad2/S_zad2.txt");

    for(int i = 0; i < iteracje; ++i){
        poi.krok();

        plik_S<<poi.S<<" ";        
    }

    plik_S.close();
    poi.oblicz_rho_prim();
    zapisz_do_pliku(poi.u, "./zad2/u_500_zad2.txt");
    zapisz_do_pliku(poi.rho_prim, "./zad2/rho_prim_zad2.txt");
    
    zapisz_do_pliku(poi.delta_rho(), "./zad2/delta_rho_zad2.txt");
}
