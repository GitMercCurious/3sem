#ifndef LESSON3_DISTRIBUTION_UNFORM_DISTRIBUTION_H
#define LESSON3_DISTRIBUTION_UNFORM_DISTRIBUTION_H

#include "libs.h"

template<typename T>
class Uniform_distribution{};


template<>
class Uniform_distribution<double> {
private:
    std::uniform_real_distribution<double> dstr{};
public:
    [[maybe_unused]] Uniform_distribution(double _min, double _max){
        dstr = std::uniform_real_distribution<double>(_min, _max);
    }

    double operator() (std::default_random_engine &rng) {
        return dstr(rng);
    }
};


template<>
class Uniform_distribution<int> {
private:
    std::uniform_int_distribution<int> dstr{};
public:
    [[maybe_unused]] Uniform_distribution(int _min, int _max){
        dstr = std::uniform_int_distribution<int>(_min, _max);
    }

    int operator() (std::default_random_engine &rng) {
        return dstr(rng);
    }
};


template<>
class Uniform_distribution<float> {
private:
    std::uniform_real_distribution<float> dstr{};
public:
    [[maybe_unused]] Uniform_distribution(float _min, float _max){
        dstr = std::uniform_real_distribution<float>(_min, _max);
    }

    float operator() (std::default_random_engine &rng) {
        return dstr(rng);
    }
};


#endif //LESSON3_DISTRIBUTION_UNFORM_DISTRIBUTION_H
