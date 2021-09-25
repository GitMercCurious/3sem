#include "headers/libs.h"
#include "headers/StateEngine.h"
#include "headers/ProbabilityTest.h"


int main() {
    DiscreteState d(50);
    SegmentState s(0,9);
    SetState ss({1, 3, 5, 7, 23, 57, 60, 90, 99});
    ContExceptionState ces(0, 10, {1, 0.124, 1.23, 4.75, 4.4351});
    ContAddingState cas(1, 43, {12, 35.12, 12.12, 75, 90.0192423});
    OrState<int, double> os(&d, &cas);
    AndState<int, int> as(&s, &ss);
    XorState<double, double> xs(&ces, &cas);

    ProbabilityTest<int> pt_d(175,0,99,100000000);
    ProbabilityTest<double> pt_c(125, 0.0, 100.0, 00, 1e-6);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << pt_d(d) << std::endl;
    std::cout << pt_d(s) << std::endl;
    std::cout << pt_d(ss) << std::endl;
    std::cout << pt_c(ces) << std::endl;
    std::cout << pt_c(cas) << std::endl;
    std::cout << pt_c(os) << std::endl;
    std::cout << pt_c(as) << std::endl;
    std::cout << pt_c(xs) << std::endl;

/*
0.01022
0.10012
0.08946
0.09987
0.41930
0.42919
0.03978
0.33949
 */

    return 0;
}
