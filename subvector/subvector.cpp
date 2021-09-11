struct subvector{
    int *mas;
    unsigned int top;
    unsigned int capacity;
};

bool init(subvector *qv);                                  //инициализация пустого недовектора
bool push_back(subvector *qv, int d);                      //добавление элемента в конец недовектора
                                                           //с выделением дополнительной памяти при необходимости

int pop_back(subvector *qv);                               //удаление элемента с конца недовектора


bool resize(subvector *qv, unsigned int new_capacity);     //увеличить емкость недовектора


void shrink_to_fit(subvector *qv);                         //очистить неиспользуемую память


void clear(subvector *qv);                                 //очистить содержимое недовектора, занимаемое место
                                                           //при этом не меняется

void destructor(subvector *qv);                            //очистить всю используемую память, инициализировать
                                                           //недовектор как пустой

bool init_from_file(subvector *qv, char *filename);        //инициализировать недовектор из файла


//Реализация
bool init(subvector *qv){
    qv->top = 0;
    qv->capacity = 0;
    qv->mas = NULL;

    return true;
}


bool push_back(subvector *qv, int d){
    if(qv->top == qv->capacity){
        resize(qv, (qv->top == 0) ? 1 : (2 + qv->capacity));
    }

    *(qv->mas + qv->top) = d;
    ++qv->top;

    return true;
}


int pop_back(subvector *qv){
    if(qv->top == 0)
        return 0;

    qv->top -= 1;
    return *(qv->mas + qv->top);
}


bool resize(subvector *qv, unsigned int new_capacity){
    if(new_capacity < qv->top) {
        return false;
    }

    int *new_mas = new int[new_capacity];

    for (int i = 0; i < qv->top; ++i) {
        *(new_mas + i) = *(qv->mas + i);
    }

    if(qv->mas)
        delete[] qv->mas;

    qv->mas = new_mas;
    qv->capacity = new_capacity;

    return true;
}


void shrink_to_fit(subvector *qv){
    resize(qv, qv->top);
}


void clear(subvector *qv){
    qv->top = 0;
    resize(qv, qv->capacity);
}


void destructor(subvector *qv){
    delete[] qv->mas;
    init(qv);
}
