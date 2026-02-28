#pragma once

#include "source/functions/density_function/DensityFunction.h"


class ExponentialDensityFunction: public DensityFunction {
private:
    double lambda = 0.0;
    void setLambda(double lambda);

public:
    ExponentialDensityFunction(double lambda);

    double operator () (const double& input) const override;
    Function<double, double>* clone() const override;
};