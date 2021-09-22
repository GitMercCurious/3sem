#include <iostream>
#include "stack.h"

int main() {
    Subvector s;
    s.push_back(1);
    s.push_back(2);
    s.print();
    s.pop_back();
    s.print();
    s.clear();
    s.print();
    std::cout << "subvec tested" <<std::endl;

    Stack a;
    a.push_back(3);
    a.push_back(4);
    a.print();
    cout << endl;
    a.pop_back();
    a.print();


    return 0;
}
