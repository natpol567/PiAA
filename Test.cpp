//
// Created by natal on 06.04.2024.
//
#include "Test.h" // Dołącza definicję klasy Test oraz niezbędne deklaracje


// Metoda testująca wydajność stosu opartego na tablicy
void Test::testStackArray(int n) {
    auto start = std::chrono::high_resolution_clock::now(); // Zaczynamy pomiar czasu

    StackArray sa(n); // Tworzy obiekt stosu opartego na tablicy o pojemności 'n'
    for (int i = 0; i < n; i++) {
        sa.push(i); // Dodaje kolejne liczby całkowite do stosu, od 0 do n-1
    }

    auto end = std::chrono::high_resolution_clock::now(); // Kończy pomiar czasu
    std::chrono::duration<double, std::milli> elapsed = end - start; // Oblicza czas trwania operacji w milisekundach
    std::cout << "StackArray (" << n << " elementow): " << elapsed.count() << " ms\n"; // Wypisuje czas trwania na ekran
}

// Metoda testująca wydajność stosu opartego na liście jednokierunkowej
void Test::testStackList(int n) {
    auto start = std::chrono::high_resolution_clock::now(); // Zaczyna pomiar czasu

    StackList sl; // Tworzy obiekt stosu opartego na liście, nie potrzebuje inicjalnej pojemności jak StackArray
    for (int i = 0; i < n; i++) {
        sl.push(i); // Dodaje kolejne liczby całkowite do stosu, od 0 do n-1
    }

    auto end = std::chrono::high_resolution_clock::now(); // Kończy pomiar czasu
    std::chrono::duration<double, std::milli> elapsed = end - start; // Oblicza czas trwania operacji w milisekundach
    std::cout << "StackList (" << n << " elementow): " << elapsed.count() << " ms\n"; // Wypisuje czas trwania na ekran
}
