//
// Created by natal on 06.04.2024.
//
#include "StackArray.h" // Dołącza definicję klasy StackArray
#include <iostream>
using namespace std;

// Konstruktor inicjalizuje stos o określonej pojemności oraz ustawia indeks na -1, co oznacza pusty stos.
StackArray::StackArray(int capacity) : capacity(capacity), index(-1) {
    array = new int[capacity]; // Tworzy dynamiczną tablicę o zadanej pojemności
}

// Destruktor zwalnia pamięć zaalokowaną dla tablicy.
StackArray::~StackArray() {
    delete[] array; // Usuwa tablicę
}

// Metoda push dodaje element na górę stosu, jeśli jest miejsce.
void StackArray::push(int element) {
    if (!isFull()) { // Sprawdza, czy stos nie jest pełen
        array[++index] = element; // Najpierw zwiększa indeks, potem przypisuje element
    }
}

// Metoda top zwraca wartość elementu na górze stosu bez usuwania go.
int StackArray::top() const {
    if (!isEmpty()) { // Sprawdza, czy stos nie jest pusty
        return array[index]; // Zwraca element na górze stosu
    } else {
        return -1; // Jeśli stos jest pusty, zwraca -1
    }
}

// Metoda pop zwraca wartość elementu na górze stosu i usuwa go.
int StackArray::pop() {
    if (!isEmpty()) { // Sprawdza, czy stos nie jest pusty
        return array[index--]; // Zwraca wartość i zmniejsza indeks (usuwa element ze stosu)
    } else {
        return -1; // Jeśli stos jest pusty, zwraca -1
    }
}

// Metoda size zwraca bieżący rozmiar stosu.
int StackArray::size() const {
    return index + 1; // Indeks zaczyna się od -1, więc rozmiar to indeks+1
}

// Metoda isFull sprawdza, czy stos jest pełen.
bool StackArray::isFull() const {
    return index == capacity - 1; // Sprawdza, czy indeks osiągnął maksymalną pojemność
}

// Metoda isEmpty sprawdza, czy stos jest pusty.
bool StackArray::isEmpty() const {
    return index == -1; // Stos jest pusty, gdy indeks jest równy -1
}

// Metoda clear czyści stos, resetując indeks do -1.
void StackArray::clear() {
    index = -1; // Resetuje indeks, efektywnie "czyści" stos
}

// Metoda display wypisuje zawartość stosu od góry do dołu.
void StackArray::display() const {
    for (int i = index; i >= 0; i--) { // Iteruje od góry stosu do dołu
        cout << array[i] << endl; // Wypisuje element stosu
    }
}