#ifndef LESSON3_DISTRIBUTION_SETADDINGS_H
#define LESSON3_DISTRIBUTION_SETADDINGS_H

#include "libs.h"


template<typename T>
bool contains(std::set<T> arr,T value, T eps = 0){
    bool res = false;
    int l = 0, r = arr.size() - 1;
    int m = (r - l) / 2 + l;
    auto it = std::next(arr.begin(), m);

    while (r - l > 0){
        if(fabs(value - *it) <= eps / 2){
            r = m;
            l = m;
        }else if(value < *it)
            r = m;
        else
            l = m + 1;

        m = (r - l) / 2 + l;
        it = std::next(arr.begin(), m);
    }

    res = fabs(value - *it) <= eps / 2;

    return res;
}



#endif //LESSON3_DISTRIBUTION_SETADDINGS_H
