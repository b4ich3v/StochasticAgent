#pragma once

#include "source/distributions/RandomVariable.hpp"
#include "source/functions/density_function/uniform_density_function/UniformDensityFunction.h"
#include <iostream>


class Uniform: public RandomVariable<Interval > {
private:
    Function<double, double>* uniformDensityFunction = nullptr;
    double lower = 0.0;
    double upper = 0.0;

    void setLower(double lower);
    void setUpper(double upper);
    void setUniformDensityFunction(const Function<double, double>* uniformDensityFunction);

public:
    Uniform(const Function<double, double>* uniformDensityFunction, double lower, double upper);

    double calculateProbability(const Interval& interval) const override;
    double getExpectation() const override;
    double getVariance() const override;
    RandomVariable* clone() const override;
};