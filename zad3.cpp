#include <iostream>
#include "funkcje.h"
#include "Poisson.h"

int main(){
    int N = 31;
    Poisson poi(N);
    int iteracje = 500;
    std::ofstream plik_S("./zad3/S_zad3.txt");

    for(int i=0; i<iteracje; i++){
        poi.krok_S();

        plik_S<<poi.S<<" ";
    }

    plik_S.close();
    poi.oblicz_rho_prim();
    zapisz_do_pliku(poi.delta_rho(), "./zad3/delta_rho_zad3.txt");
    zapisz_do_pliku(poi.rho_prim, "./zad3/rho_prim_zad3.txt");
    zapisz_do_pliku(poi.u, "./zad3/u_500_zad3.txt");
}