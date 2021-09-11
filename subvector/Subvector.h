#ifndef SUBVECTOR_SUBVECTOR_H
#define SUBVECTOR_SUBVECTOR_H

class Subvector{
private:
    int *mas;
    unsigned int top;
    unsigned int capacity;

public:


    Subvector(){
         top = 0;
         capacity = 0;
         mas = NULL;
    }


    bool push_back(int d);                      //добавление элемента в конец недовектора
                                                               //с выделением дополнительной памяти при необходимости

    int pop_back( );                               //удаление элемента с конца недовектора


    bool resize(unsigned int new_capacity);     //увеличить емкость недовектора


    void shrink_to_fit();                         //очистить неиспользуемую память


    void clear();                                 //очистить содержимое недовектора, занимаемое место
                                                               //при этом не меняется

    void destructor();                            //очистить всю используемую память, инициализировать
                                                               //недовектор как пустой

    //Реализация
    bool push_back(int d){
        if( top ==  capacity){
            resize(( top == 0) ? 1 : (2 +  capacity));
        }

        *(mas +  top) = d;
        ++top;

        return true;
    }


    int pop_back(){
        if( top == 0)
            return 0;

         top -= 1;
        return *( mas +  top);
    }


    bool resize(unsigned int new_capacity){
        if(new_capacity <  top) {
            return false;
        }

        int *new_mas = new int[new_capacity];

        for (int i = 0; i <  top; ++i) {
            *(new_mas + i) = *( mas + i);
        }

        delete[]  mas;

        mas = new_mas;
        capacity = new_capacity;

        return true;
    }


    void shrink_to_fit(){
        resize(top);
    }


    void clear(){
        top = 0;
        resize(capacity);
    }


    void destructor(){
        delete[]  mas;
        top = 0;
        capacity = 0;
        mas = NULL;
    }
}






#endif //SUBVECTOR_SUBVECTOR_H
