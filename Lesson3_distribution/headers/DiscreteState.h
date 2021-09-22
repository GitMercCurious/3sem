#ifndef LESSON3_DISTRIBUTION_DISCRETESTATE_H
#define LESSON3_DISTRIBUTION_DISCRETESTATE_H

#include "State.h"


class DiscreteState: public State<int>{
private:
    int const value;
public:
    explicit DiscreteState(int val) : value(val) {}

    [[nodiscard]] bool contains(int st, int eps) const override{
        if(st == value)
            return true;
        else
            return false;
    }
};


#endif //LESSON3_DISTRIBUTION_DISCRETESTATE_H
