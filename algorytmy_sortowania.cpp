//
// Created by natal on 11.05.2024.
//
#include "algorytmy_sortowania.h"
#include <iostream>

// Implementacja QuickSort
int QuickSort::partition(std::vector<Ranking>& filmy, int lewy, int prawy) {
    float pivot = filmy[lewy + (prawy - lewy) / 2].ocena;
    int i = lewy - 1;
    int j = prawy + 1;
    while (true) {
        do {
            i++;
        } while (filmy[i].ocena < pivot);
        do {
            j--;
        } while (filmy[j].ocena > pivot);
        if (i >= j)
            return j;
        std::swap(filmy[i], filmy[j]);
    }

}

void QuickSort::quicksort(std::vector<Ranking>& filmy, int lewy, int prawy) {
    if (lewy < prawy) {
        int pivot = partition(filmy, lewy, prawy);
        quicksort(filmy, lewy, pivot);
        quicksort(filmy, pivot + 1, prawy);
    }
}

// Implementacja MergeSort
void MergeSort::merge(std::vector<Ranking>& filmy, int lewy, int srodek, int prawy) {
    std::vector<Ranking> lewa(filmy.begin() + lewy, filmy.begin() + srodek + 1);
    std::vector<Ranking> prawa(filmy.begin() + srodek + 1, filmy.begin() + prawy + 1);

    size_t i = 0, j = 0, k = lewy;
    while (i < lewa.size() && j < prawa.size()) {
        if (lewa[i].ocena <= prawa[j].ocena) {
            filmy[k] = lewa[i++];
        } else {
            filmy[k] = prawa[j++];
        }
        k++;
    }
    while (i < lewa.size()) {
        filmy[k++] = lewa[i++];
    }
    while (j < prawa.size()) {
        filmy[k++] = prawa[j++];
    }
}

void MergeSort::mergesort(std::vector<Ranking>& filmy, int lewy, int prawy) {
    if (lewy < prawy) {
        int srodek = lewy + (prawy - lewy) / 2;
        mergesort(filmy, lewy, srodek);
        mergesort(filmy, srodek + 1, prawy);
        merge(filmy, lewy, srodek, prawy);
    }
}


// Implementacja BucketSort
void BucketSort::bucketsort(std::vector<Ranking>& filmy) {
    if (filmy.empty()) return;
    size_t n = filmy.size();
    float minwartosc = filmy[0].ocena;
    float maxwartosc = filmy[0].ocena;

    for (const auto& film : filmy) {
        if (film.ocena < minwartosc) minwartosc = film.ocena;
        if (film.ocena > maxwartosc) maxwartosc = film.ocena;
    }

    float range = (maxwartosc - minwartosc + 1) / n;
    std::vector<std::vector<Ranking>> kubelki(n);

    for (const auto& film : filmy) {
        size_t indeks = int((film.ocena - minwartosc) / range);
        if (indeks >= n) indeks = n - 1;
        kubelki[indeks].push_back(film);
    }

    size_t x = 0;
    for (size_t i = 0; i < n; ++i) {
        if (!kubelki[i].empty()) {
            if (kubelki[i].size() > 1) {
                MergeSort::mergesort(kubelki[i], 0, kubelki[i].size() - 1);
            }
            for (const auto& film : kubelki[i]) {
                filmy[x++] = film;
            }
        }
    }
}