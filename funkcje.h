//
// Created by natal on 11.05.2024.
//
#ifndef PIAA_MINIPROJEKT2_FUNKCJE_H
#define PIAA_MINIPROJEKT2_FUNKCJE_H
#include <vector>
#include <string>

struct Ranking {
    std::string film;
    float ocena;
};

void wczytaj_i_filtruj(std::vector<Ranking>& filmy, const std::string& nazwa_pliku, int n);
void wyswietl(const std::vector<Ranking>& filmy);
float srednia(const std::vector<Ranking>& filmy);
float mediana(const std::vector<Ranking>& filmy);
void testQuickSort(std::vector<Ranking>& filmy);
void testMergeSort(std::vector<Ranking>& filmy);
void testBucketSort(std::vector<Ranking>& filmy);

#endif //PIAA_MINIPROJEKT2_FUNKCJE_H
