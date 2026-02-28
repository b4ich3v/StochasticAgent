#include "source/distributions/continuous_distributions/exponential/Exponential.h"
#include <algorithm>
#include <cmath>
#include <limits>

Exponential::Exponential(double lambda): ContinuousRandomVariable([&]() {
    Vector<double> params;
    params.push_back(lambda);
    return params;
}(), ContinuousRandomVariableType::Exponential) {}

double Exponential::calculateProbability(const Interval& interval) const {
    const double lambda = this->getParameters()[0];
    const double lower = interval.getLeftComponent();
    const double upper = interval.getRightComponent();

    if (upper <= 0.0) return 0.0;
    const double a = std::max(0.0, lower);
    const bool upperIsInf = std::isinf(upper) && upper > 0;
    const double leftTerm = std::exp(-lambda * a);
    const double rightTerm = upperIsInf ? 0.0 : std::exp(-lambda * upper);
    return leftTerm - rightTerm;
}

double Exponential::getExpectation() const {
    return 1 / this->getParameters()[0];
}

double Exponential::getVariance() const {
    return 1 / std::pow(this->getParameters()[0], 2);
}

RandomVariable<Interval>* Exponential::clone() const {
    return new Exponential(*this);
}
