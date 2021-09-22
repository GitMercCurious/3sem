#ifndef LESSON3_DISTRIBUTION_SETSTATE_H
#define LESSON3_DISTRIBUTION_SETSTATE_H

#include "State.h"


class SetState: public State<int>{
private:
    std::set<int> const states{};
public:
    SetState(): states(){}
    explicit SetState(std::set<int> const &sts): states(sts) {}

    [[nodiscard]] bool contains(int st, int eps) const override{
        return states.count(st) > 0;
    }
};


#endif //LESSON3_DISTRIBUTION_SETSTATE_H
