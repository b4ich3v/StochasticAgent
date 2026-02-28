#pragma once

#include "source/functions/density_function/DensityFunction.h"


class NormalDensityFunction: public DensityFunction {
private:
    double expectation = 0.0;
    double sigmaSquared = 0.0;

    void setSigma(double sigmaSquared);
    void setExpectation(double expectation);

public:
    NormalDensityFunction(double expectation, double sigmaSquared);

    double operator () (const double& input) const override;
    Function<double, double>* clone() const override;
};