//
// Created by natal on 11.05.2024.
//
#include "funkcje.h"
#include "algorytmy_sortowania.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>

void wczytaj_i_filtruj(std::vector<Ranking>& filmy, const std::string& nazwa_pliku, int n) {
    std::ifstream plik(nazwa_pliku);
    if (!plik.is_open()) {
        std::cerr << "Nie można otworzyć pliku: " << nazwa_pliku << std::endl;
        return;
    }

    std::string linia;
    int count = 0;
    auto start = std::chrono::high_resolution_clock::now();
    while (getline(plik, linia) && count < n) {
        size_t lastComma = linia.rfind(',');
        if (lastComma != std::string::npos) {
            try {
                Ranking film;
                film.film = linia.substr(0, lastComma);
                film.ocena = std::stof(linia.substr(lastComma + 1));
                filmy.push_back(film);
                count++;
            } catch (const std::invalid_argument& e) {
                // Ignoruj linie z błędnymi danymi
            } catch (const std::out_of_range& e) {
                // Ignoruj linie z danymi poza zakresem
            }
        }
    }
    plik.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Czas wczytywania i filtrowania: " << elapsed.count() << " sekund" << std::endl;
    std::cout<<"Licznik:"<<count<<std::endl;
}

void wyswietl(const std::vector<Ranking>& filmy){
    for (const auto& film : filmy) {
        std::cout << "Film: " << film.film << ", Ocena: " << film.ocena << std::endl;
    }
}

float mediana(const std::vector<Ranking>& filmy) {
    if (filmy.empty()) {
        std::cout << "Nie można obliczyć mediany: pusty zbiór danych." << std::endl;
        return 0.0;
    }

    size_t n = filmy.size();
    if (n % 2 == 0) {
        return (filmy[n / 2 - 1].ocena + filmy[n / 2].ocena) / 2.0;
    } else {
        return filmy[n / 2].ocena;
    }
}

float srednia(const std::vector<Ranking>& filmy) {
    if (filmy.empty()) {
        std::cout << "Nie można obliczyć średniej: pusty zbiór danych." << std::endl;
        return 0.0;
    }

    float suma = 0.0;
    for (const auto& film : filmy) {
        suma += film.ocena;
    }
    return suma / filmy.size();
}

void testQuickSort(std::vector<Ranking>& filmy) {
    auto start = std::chrono::high_resolution_clock::now();
    QuickSort::quicksort(filmy, 0, filmy.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Czas sortowania QuickSort: " << elapsed.count() << " sekund\n";
}

void testMergeSort(std::vector<Ranking>& filmy) {
    auto start = std::chrono::high_resolution_clock::now();
    MergeSort::mergesort(filmy, 0, filmy.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Czas sortowania MergeSort: " << elapsed.count() << " sekund\n";
}

void testBucketSort(std::vector<Ranking>& filmy) {
    auto start = std::chrono::high_resolution_clock::now();
    BucketSort::bucketsort(filmy);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Czas sortowania BucketSort: " << elapsed.count() << " sekund\n";
}