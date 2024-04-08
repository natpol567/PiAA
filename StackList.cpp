//
// Created by natal on 06.04.2024.
//
#include "StackList.h" // Dołącza definicję klasy StackList i struktury Node
#include <iostream>
using namespace std;

// Konstruktor: inicjalizuje stos jako pusty (wierz = nullptr) oraz rozmiar stosu jako 0.
StackList::StackList() : wierz(nullptr), currentSize(0) {}

// Destruktor: usuwa wszystkie elementy stosu przed zwolnieniem zasobów.
StackList::~StackList() {
    clear();
}

// Metoda push: dodaje nowy element na górze stosu.
void StackList::push(int data) {
    Node* newNode = new Node(data, wierz); // Tworzy nowy węzeł z danymi i wskaźnikiem na poprzedni wierzchołek
    wierz = newNode; // Ustawia nowy węzeł jako wierzchołek stosu
    currentSize++; // Zwiększa rozmiar stosu
}

// Metoda pop: usuwa element z góry stosu i zwraca jego wartość.
int StackList::pop() {
    if (!isEmpty()) { // Sprawdza, czy stos nie jest pusty
        Node* temp = wierz; // Zapisuje wierzchołek do tymczasowej zmiennej
        int data = wierz->data; // Pobiera dane z wierzchołka
        wierz = wierz->next; // Ustawia następny element jako nowy wierzchołek stosu
        delete temp; // Usuwa stary wierzchołek stosu
        currentSize--; // Zmniejsza rozmiar stosu
        return data; // Zwraca dane z usuniętego wierzchołka
    }
    return -1; // Zwraca -1 jako sygnał błędu, jeśli stos jest pusty
}

// Metoda top: zwraca wartość elementu na górze stosu bez jego usuwania.
int StackList::top() const {
    if (!isEmpty()) {
        cout << endl << wierz->data; // Wypisuje dane z wierzchołka stosu
    }
    return -1;
}

// Metoda size: zwraca aktualny rozmiar stosu.
int StackList::size() const {
    return currentSize;
}

// Metoda isEmpty: sprawdza, czy stos jest pusty.
bool StackList::isEmpty() const {
    return wierz == nullptr;
}

// Metoda clear: usuwa wszystkie elementy ze stosu.
void StackList::clear() {
    while (!isEmpty()) { // Dopóki stos nie jest pusty, usuwa elementy z góry stosu
        pop();
    }
}

// Metoda display: wypisuje wszystkie elementy stosu od góry do dołu.
void StackList::display() const {
    Node* current = wierz; // Zaczyna od wierzchołka stosu

    while (current != nullptr) { // Przechodzi przez wszystkie elementy
        cout << current->data << endl; // Wypisuje dane każdego węzła
        current = current->next; // Przechodzi do następnego węzła
    }
}