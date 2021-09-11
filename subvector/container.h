//
// Created by Kolya on 11.09.2021.
//

#ifndef TEST_PROJECT_CONTAINER_H
#define TEST_PROJECT_CONTAINER_H

#include <iostream>
using std::cout;
using std::endl;


class Container{
protected:
    int *mas;
    unsigned int top;
    unsigned int capacity;

public:
    Container(){
        capacity = 0;
        top = 0;
        mas = nullptr;
    }

    ~Container(){
        delete[] this->mas;
        this->capacity = 0;
        this->top = 0;
        this->mas = nullptr;
    }
};

#endif //TEST_PROJECT_CONTAINER_H

