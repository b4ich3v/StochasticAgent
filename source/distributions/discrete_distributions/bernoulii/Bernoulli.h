#pragma once

#include "source/distributions/RandomVariable.hpp"


class Bernoulli: public RandomVariable<bool> {
public:
    Bernoulli(Success success);

    double calculateProbability(bool number) const override;
    double getExpectation() const override;
    double getVariance() const override;
    RandomVariable* clone() const override;
};