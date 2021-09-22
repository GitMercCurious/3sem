//
// Created by Kolya on 11.09.2021.
//
#include "subvector.h"

#ifndef TEST_PROJECT_STACK_H
#define TEST_PROJECT_STACK_H

class Stack: protected Subvector{
public:
    bool push_back(int d) override{return Subvector::push_back(d);}
    int pop_back() override{return Subvector::pop_back();}
    void print() override{
        for (int i = 0; i < this->top; i++){
            cout << *(this->mas + i) << "|";
            cout << endl;
        }
    }
};

#endif //TEST_PROJECT_STACK_H
