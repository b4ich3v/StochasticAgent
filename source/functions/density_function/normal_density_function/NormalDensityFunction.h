#pragma once

#include "source/functions/density_function/DensityFunction.h"


class NormalDensityFunction: public DensityFunction {
private:
    double expectation = 0.0;
    double sigma = 0.0;

    void setSigma(double sigma);
    void setExpectation(double expectation);

public:
    NormalDensityFunction(double expectation, double sigma);

    double operator () (const double& input) const override;
    Function<double, double>* clone() const override;
};