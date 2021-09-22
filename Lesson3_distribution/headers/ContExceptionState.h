#ifndef LESSON3_DISTRIBUTION_CONTEXCEPTIONSTATE_H
#define LESSON3_DISTRIBUTION_CONTEXCEPTIONSTATE_H


class ContExceptionState: public State<double>{
private:
    double beg{}, end{};
    std::set<double> exceptions{};
public:
    ContExceptionState(): ContExceptionState(0, -1) {}
    ContExceptionState(double beg, double end): ContExceptionState(beg, end, {}) {}
    ContExceptionState(double beg, double end, std::set<double> exs): beg(beg), end(end), exceptions(exs) {}

    [[nodiscard]] bool contains(double st, double eps) const override{
        if(beg - eps/2 <= st && st <= end + eps/2)
            return true;
    }
};


#endif //LESSON3_DISTRIBUTION_CONTEXCEPTIONSTATE_H
