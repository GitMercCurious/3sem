//
// Created by Kolya on 04.09.2021.
//

#include <iostream>
#include "container.h"

class Subvector: public Container{
public:
    virtual bool push_back(int d){
        if ( (this->capacity - this->top) >= 1 ){
            *(this->mas + this->top) = d;
            this->top++;
        }else{
            resize(this->capacity + 1);
            *(this->mas + this->top) = d;
            this->top++;
        }
        return true;
    }
//добавление элемента в конец недовектора
//с выделением дополнительной памяти при необходимости

    virtual int pop_back(){
        if(this->top >= 1){
            this->top--;
            return *(this->mas + this->top);
        }
        return 0;
    }
//удаление элемента с конца недовектора

    bool resize(unsigned int new_capacity){
        if(this->capacity >= new_capacity){
            return false;
        }
        int* new_mas = new int[new_capacity];
        for (int i = 0; i < this->top; i++){
            *(new_mas + i) = *(this->mas + i);
        }

        if(this->mas){delete[] this->mas;}
        this->mas = new_mas;
        this->capacity = new_capacity;
        return true;
    }


    void shrink_to_fit(){
        int* new_mas = new int[this->top];
        for (int i = 0; i < this->top; i++){
            *(new_mas + i) = *(this->mas + i);
        }
        this->capacity = this->top;
        delete[] this->mas;
        this->mas = new_mas;
    }
//очистить неиспользуемую память


    void clear(){
        this->top = 0;
    }
//очистить содержимое недовектора, занимаемое место
//при этом не меняется

    virtual void print(){
        cout << "_";
        for (int i = 0; i < this->top; i++){
            cout << *(this->mas + i) << "_";
        }
        cout << endl;
    }
};
