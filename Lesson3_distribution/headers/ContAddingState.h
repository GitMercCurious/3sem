#ifndef LESSON3_DISTRIBUTION_CONTADDINGSTATE_H
#define LESSON3_DISTRIBUTION_CONTADDINGSTATE_H


#include "State.h"
#include "SetAddings.h"

class ContAddingState: public State<double>{
private:
    double beg{}, end{};
    std::set<double> exceptions{};
public:
    ContAddingState(): ContAddingState(0, -1) {}
    ContAddingState(double beg, double end): ContAddingState(beg, end, {}) {}
    ContAddingState(double beg, double end, std::set<double> exs): beg(beg), end(end), exceptions(exs) {}

    [[nodiscard]] bool contains(double st, double eps) const override{

        return (beg - eps / 2 <= st) && (st <= end - eps / 2) || (::contains<double>(exceptions, st, eps));
    }
};


#endif //LESSON3_DISTRIBUTION_CONTADDINGSTATE_H
