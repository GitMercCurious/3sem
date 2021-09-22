#include "headers/libs.h"
#include "headers/StateEngine.h"
#include "headers/ProbabilityTest.h"


int main() {
    DiscreteState d(50);
    SegmentState s(0,9);
    SetState ss({1, 3, 5, 7, 23, 57, 60, 90, 99});


    ProbabilityTest<int> pt_d(175,0,99,1000000);
    ProbabilityTest<double> pt_c(175, 0, 99, 1000000, 1e-6);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << pt_d(d) << std::endl;
    std::cout << pt_d(s) << std::endl;
    std::cout << pt_d(ss) << std::endl;
    return 0;
}
