#include "funkcje.h"
#include "algorytmy_sortowania.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Ranking> filmy;
    std::string nazwa_pliku = "C:\\Users\\natal\\OneDrive\\Pulpit\\projekt2_dane.csv";
    int n = 1000000;
    wczytaj_i_filtruj(filmy, nazwa_pliku, n);


    testQuickSort(filmy);
    //testMergeSort(filmy);
//      testBucketSort(filmy);
    //wyswietl(filmy);
    mediana(filmy);
    std::cout << "Mediana wynosi: " << mediana(filmy) << std::endl;
    srednia(filmy);
    std::cout << "Srednia wynosi: " << srednia(filmy) << std::endl;

    return 0;
}