//
// Created by natal on 11.05.2024.
//

#ifndef PIAA_MINIPROJEKT2_ALGORYTMY_SORTOWANIA_H
#define PIAA_MINIPROJEKT2_ALGORYTMY_SORTOWANIA_H
#include "funkcje.h"
#include <iostream>
#include <vector>


class QuickSort {
public:
    static void quicksort(std::vector<Ranking>& filmy, int lewy, int prawy);
private:
    static int partition(std::vector<Ranking>& filmy, int lewy, int prawy);
};

class MergeSort {
public:
    static void mergesort(std::vector<Ranking>& filmy, int lewy, int prawy);
private:
    static void merge(std::vector<Ranking>& filmy, int lewy, int srodek, int prawy);
};

class BucketSort {
public:
    static void bucketsort(std::vector<Ranking>& filmy);
};


#endif //PIAA_MINIPROJEKT2_ALGORYTMY_SORTOWANIA_H
