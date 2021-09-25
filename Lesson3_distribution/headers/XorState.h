#ifndef LESSON3_DISTRIBUTION_XORSTATE_H
#define LESSON3_DISTRIBUTION_XORSTATE_H


#include "State.h"


template<typename T, typename V>
class XorState: public State<double>{
private:
    State<T> *firstState;
    State<V> *secondState;

public:

    XorState(State<T> *s1, State<V> *s2): firstState(s1), secondState(s2) {}

    [[nodiscard]] bool contains(double st, double eps) const override{
        return firstState->contains((T)st, (T)eps) != secondState->contains((V)st, (V)eps);
    }
};


#endif //LESSON3_DISTRIBUTION_XORSTATE_H
