//
// Created by natal on 06.04.2024.
//

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <iostream>

class StackArray {
private:
    int *array;
    int capacity;
    int index;

public:
    StackArray(int capacity);
    ~StackArray();
    void push(int element);
    int pop();
    int top() const;
    int size() const;
    bool isFull() const;
    bool isEmpty() const;
    void clear();
    void display() const;
};

#endif