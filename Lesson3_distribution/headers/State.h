#ifndef LESSON3_DISTRIBUTION_STATE_H
#define LESSON3_DISTRIBUTION_STATE_H

#include "libs.h"


template<typename T>
class State{
public:
    [[nodiscard]] virtual bool contains(T st, T eps) const = 0;
};


#endif //LESSON3_DISTRIBUTION_STATE_H
