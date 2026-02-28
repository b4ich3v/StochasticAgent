#pragma once

#include "source/data_structures/integration/Integral.h"
#include "source/functions/Function.hpp"


class TrapezoidalRuleIntergral: public Integral {
private:
    size_t countOfNonSubIntervals = 0;
    void setCountOfNonSubIntervals(size_t countOfNonSubIntervals);

public:
    TrapezoidalRuleIntergral(const Function<double, double>* function, size_t countOfNonSubIntervals);
    
    double intergrate(double lower, double upper) const override;
    Integral* clone() const override;
};