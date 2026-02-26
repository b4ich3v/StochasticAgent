#pragma once

#include "source/distributions/discrete_distributions/BernoulliSchemeRandomVariable.hpp"


class Bernoulli: public BernoulliSchemeRandomVariable<bool> {
public:
    Bernoulli(Success success);

    double calculateProbability(const bool& number) const override;
    double getExpectation() const override;
    double getVariance() const override;
    BernoulliSchemeRandomVariable<bool>* clone() const override;
};