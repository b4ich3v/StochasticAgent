#include "source/functions/density_function/exponential_density_function/ExponentialDensityFunction.h"

ExponentialDensityFunction::ExponentialDensityFunction(double lambda): 
    DensityFunction(Domain<double>(), Interval(0, std::numeric_limits<double>::infinity())){
    this->setLambda(lambda);
}

void ExponentialDensityFunction::setLambda(double lambda) {
    if (lambda < 0) throw std::runtime_error("Lambda must be greater than 0");
    this->lambda = lambda;
}

double ExponentialDensityFunction::operator () (const double& input) const {
    this->lambda * std::exp(-this->lambda * input);
}
    
Function<double, double>* ExponentialDensityFunction::clone() const {
    return new ExponentialDensityFunction(*this);
}