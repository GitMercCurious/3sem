#include <iostream>
#include <set>
#include <random>
#include <iomanip>

template<typename T>
class State{
public:
    [[nodiscard]] virtual bool contains(T st) const = 0;
};


class DiscreteState: public State<int>{
private:
    int const value;
public:
    explicit DiscreteState(int val): value(val){}

    [[nodiscard]] bool contains(int st) const override{
        if(st == value)
            return true;
        else
            return false;
    }
};


class SegmentState: public State<int>{
private:
    int const beg, end;
public:
    SegmentState(): beg(0), end(-1){}
    SegmentState(int beg, int end): beg(beg), end(end){}

    [[nodiscard]] bool contains(int st) const override{
        if(beg <= st && st <= end)
            return true;
        else
            return false;
    }
};


class SetState: public State<int>{
private:
    std::set<int> const states;
public:
    SetState(): states(){}
    explicit SetState(std::set<int> const &sts): states(sts) {}

    [[nodiscard]] bool contains(int st) const override{
        return states.count(st) > 0;
    }
};


template<typename T>
class Uniform_distribution{};


template<>
class Uniform_distribution<int> {
private:
    std::uniform_int_distribution<int> dstr;
public:
    Uniform_distribution(int _min, int _max){
        dstr = std::uniform_int_distribution<int>(_min, _max);
    }

    int operator() (std::default_random_engine &rng) {
        return dstr(rng);
    }
};


template<>
class Uniform_distribution<float> {
private:
    std::uniform_real_distribution<float> dstr;
public:
    Uniform_distribution(float _min, float _max){
        dstr = std::uniform_real_distribution<float>(_min, _max);
    }

    int operator() (std::default_random_engine &rng) {
        return dstr(rng);
    }
};


template<typename T>
class ProbabilityTest {
private:
    unsigned seed;
    int test_min, test_max;
    unsigned test_count;

public:
    ProbabilityTest(unsigned seed, int test_min, int test_max, unsigned test_count):
    seed(seed), test_min(test_min), test_max(test_max), test_count(test_count) { }

    float operator()(State<T> const &s) const {
        std::default_random_engine rng(seed);
        Uniform_distribution<T> dstr(test_min,test_max);
        unsigned good = 0;
        for (unsigned cnt = 0; cnt != test_count; ++cnt)
            if (s.contains(dstr(rng))) ++good;

        return static_cast<float>(good)/static_cast<float>(test_count);
    }
};

int main() {
    DiscreteState d(50);
    SegmentState s(0,9);
    SetState ss({1, 3, 5, 7, 23, 57, 60, 90, 99});

    ProbabilityTest<int> pt_d(175,0,99,1000000);
    //ProbabilityTest<double> pt_c(175, 0, 99, 1000000);

    //std::cout << std::fixed << std::setprecision(7);
    std::cout << pt_d(d) << std::endl;
    std::cout << pt_d(s) << std::endl;
    std::cout << pt_d(ss) << std::endl;
    return 0;
}
