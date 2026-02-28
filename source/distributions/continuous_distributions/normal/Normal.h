#pragma once

#include "source/distributions/continuous_distributions/ContinuousRandomVariable.hpp"
#include <iostream>


class Normal: public ContinuousRandomVariable<double> {
public:
    Normal(double expectation, double sigmaSquared);

    double calculateProbability(const Interval& interval) const override;
    double getExpectation() const override;
    double getVariance() const override;
    RandomVariable<Interval>* clone() const override;
};