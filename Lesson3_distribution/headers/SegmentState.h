#ifndef LESSON3_DISTRIBUTION_SEGMENTSTATE_H
#define LESSON3_DISTRIBUTION_SEGMENTSTATE_H

#include "State.h"


class SegmentState: public State<int>{
private:
    int const beg, end;
public:
    SegmentState(): beg(0), end(-1){}
    SegmentState(int beg, int end): beg(beg), end(end){}

    [[nodiscard]] bool contains(int st, int eps) const override{
        if(beg <= st && st <= end)
            return true;
        else
            return false;
    }
};


#endif //LESSON3_DISTRIBUTION_SEGMENTSTATE_H
