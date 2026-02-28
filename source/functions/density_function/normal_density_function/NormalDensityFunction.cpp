#include "source/functions/density_function/normal_density_function/NormalDensityFunction.h"
#include "source/data_structures/combinatorics/k_selection/KSelection.h"
#include "source/Constants.h"
#include <limits>
#include <cmath>

NormalDensityFunction::NormalDensityFunction(double expectation, double sigma): 
    DensityFunction(Domain<double>(), Interval(-std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity())) {
    this->setExpectation(expectation);
    this->setSigma(sigma);
}

void NormalDensityFunction::setSigma(double sigma) {
    if (sigma <= 0) throw std::logic_error("Sigma parameter must be greater than zero");
    this->sigma = sigma;
}

void NormalDensityFunction::setExpectation(double expectation) {
    this->expectation = expectation;
}

double NormalDensityFunction::operator () (const double& input) const {
    const double exponent = -std::pow(input - this->expectation, 2) /
        (2 * std::pow(this->sigma, 2));

    return std::pow(EULER_NUMBER, exponent) /
        (this->sigma * std::sqrt(2 * PI));
}

Function<double, double>* NormalDensityFunction::clone() const {
    return new NormalDensityFunction(*this);
}
