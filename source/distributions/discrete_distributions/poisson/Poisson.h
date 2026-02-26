#pragma once

#include <cmath>
#include <iostream>
#include "source/distributions/RandomVariable.hpp"


class Poisson: public RandomVariable<uint32_t> {
private:
    double lambda = 0.0;
    void setLambda(double lambda);

public:
    Poisson(double lambda);
    double calculateProbability(const uint32_t& number) const override;
    double getExpectation() const override;
    double getVariance() const override;
    RandomVariable<uint32_t>* clone() const override;
};