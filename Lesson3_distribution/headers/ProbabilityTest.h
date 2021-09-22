#ifndef LESSON3_DISTRIBUTION_PROBABILITYTEST_H
#define LESSON3_DISTRIBUTION_PROBABILITYTEST_H

#include "Unform_distribution.h"


template<typename T>
class ProbabilityTest {
private:
    unsigned seed;
    T test_min, test_max;
    unsigned test_count;
    T precise;
public:
    ProbabilityTest(unsigned seed, T test_min, T test_max, unsigned test_count, T precise = 0):
            seed(seed), test_min(test_min), test_max(test_max), test_count(test_count), precise(precise) { }

    float operator()(State<T> const &s) const {
        std::default_random_engine rng(seed);
        Uniform_distribution<T> dstr(test_min,test_max);
        unsigned good = 0;
        for (unsigned cnt = 0; cnt != test_count; ++cnt)
            if (s.contains(dstr(rng), precise)) ++good;

        return static_cast<float>(good)/static_cast<float>(test_count);
    }
};


#endif //LESSON3_DISTRIBUTION_PROBABILITYTEST_H
