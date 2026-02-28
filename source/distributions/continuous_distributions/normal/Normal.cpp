#include "source/distributions/continuous_distributions/normal/Normal.h"
#include "source/data_structures/vector/Vector.hpp"
#include "source/functions/density_function/normal_density_function/NormalDensityFunction.h"
#include <cmath>
#include <limits>

Normal::Normal(double expectation, double sigmaSquared): ContinuousRandomVariable([&]() {
    Vector<double> params;
    params.push_back(expectation);
    params.push_back(sigmaSquared);
    return params;
}(), ContinuousRandomVariableType::Normal) {}

double Normal::calculateProbability(const Interval& interval) const {
    const double mu = this->getExpectation();
    const double variance = this->getVariance();
    const double sigma = std::sqrt(variance);
    const double left = interval.getLeftComponent();
    const double right = interval.getRightComponent();
    const double leftZ = std::isinf(left) && left < 0 ? -std::numeric_limits<double>::infinity(): (left - mu) / (sigma * std::sqrt(2.0));
    const double rightZ = std::isinf(right) && right > 0 ? std::numeric_limits<double>::infinity(): (right - mu) / (sigma * std::sqrt(2.0));

    return 0.5 * (std::erf(rightZ) - std::erf(leftZ));
}

double Normal::getExpectation() const {
    return this->getParameters()[0];
}

double Normal::getVariance() const {
    return this->getParameters()[1];
}

RandomVariable<Interval>* Normal::clone() const {
    return new Normal(*this);
}
