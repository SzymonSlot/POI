#include <iostream>
#include "funkcje.h"
#include <fstream>

void zapisz_do_pliku(const std::vector<std::vector<double>>& macierz, const std::string& nazwa) {
    std::ofstream plik(nazwa);
    for (int j = 0; j<macierz[0].size(); j++) {
        for (int i = 0; i<macierz.size(); i++) {
            plik << macierz[i][j] << " ";
        }
        plik << "\n";
    }
}