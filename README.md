# Rozwiązywanie Równania Poissona – Analiza Metod Optymalizacji

Projekt poświęcony jest numerycznemu rozwiązywaniu równania Poissona w 2D. Głównym celem jest porównanie efektywności różnych algorytmów iteracyjnych w kontekście minimalizacji funkcjonału błędu (energii układu) $S$.

## 🔬 Model Fizyczny i Matematyczny

Symulacja odbywa się na siatce kwadratowej o rozmiarze $(2N+1) \times (2N+1)$, gdzie $N=31$. 
* **Układ**: Dipol elektryczny modelowany jako różnica dwóch rozkładów Gaussa.
* **Cel**: Znalezienie rozkładu potencjału $u$, który minimalizuje różnicę względem teoretycznego gęstości ładunku $\rho$.
* **Funkcjonał $S$**: Globalny błąd numeryczny, obliczany na podstawie lokalnych operatorów różnicowych.

## 🚀 Zaimplementowane Metody

| Zadanie | Metoda | Opis |
| :--- | :--- | :--- |
| **Zadanie 1** | **Relaksacja lokalna** | Klasyczne podejście Gaussa-Seidela. |
| **Zadanie 2** | **Nadrelaksacja (SOR)** | Przyspieszenie zbieżności parametrem $\omega = 1.9$. |
| **Zadanie 3** | **Optymalizacja $\Delta$** | Lokalna modyfikacja potencjału w celu minimalizacji $S$ w każdym kroku. |
| **Zadanie 4** | **Metoda Gradientowa** | Wykorzystanie pochodnej funkcjonału $S$ do aktualizacji węzłów z parametrem $\beta$. |
| **Zadanie 5** | **Metoda Stochastyczna** | Losowe modyfikacje wartości w węzłach (podejście typu Monte Carlo). |

## 📂 Struktura Projektu

### Rdzeń obliczeniowy (C++)
* `Poisson.h / Poisson.cpp` – Klasa zarządzająca siatką i logiką wszystkich metod (`krok()`, `krok_S()`, `krok_grad_S()`, `krok_rand()`).
* `zad1.cpp` - `zad5.cpp` – Programy wykonawcze dla poszczególnych etapów analizy.
* `funkcje.h / funkcje.cpp` – Uniwersalne narzędzia do zapisu macierzy i danych.

### Wizualizacja (Python)
* `zad1_plot.py`, `zad2_plot.py` – Generowanie map potencjału $u$ oraz błędów $\Delta \rho$.
* `S_plot.py` – Kluczowy skrypt porównujący tempo spadku błędu $S$ dla wszystkich metod jednocześnie.

## 🛠 Instrukcja obsługi

Projekt posiada zaawansowany plik `Makefile`, który automatyzuje cały proces – od kompilacji po generowanie raportów graficznych.

**Uruchomienie wszystkiego:**
```
make all
```
