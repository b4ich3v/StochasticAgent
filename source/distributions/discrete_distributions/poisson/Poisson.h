#pragma once

#include <iostream>
#include "source/distributions/RandomVariable.hpp"


class Poisson: RandomVariable<uint32_t> {
private:
    size_t lambda = 0;
    void setLambda(size_t lambda);

public:
    Poisson(size_t lambda);
    double calculateProbability(uint32_t number) const override;
    double getExpectation() const override;
    double getVariance() const override;
    RandomVariable<uint32_t>* clone() const override;
};