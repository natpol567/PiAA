//
// Created by natal on 06.04.2024.
//
#ifndef STACKLIST_H
#define STACKLIST_H

#include <iostream>

class StackList {
private:
    //Wewnętrzna klasa reprezentująca węzeł listy
    class Node {
    public:
        int data;
        Node* next; //wskaźnik na następny węzeł w stosie

        Node(int data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* wierz;
    int currentSize;

public:
    StackList();
    ~StackList();
    void push(int data);
    int pop();
    int top() const;
    int size() const;
    bool isEmpty() const;
    void clear();
    void display() const;
};

#endif
