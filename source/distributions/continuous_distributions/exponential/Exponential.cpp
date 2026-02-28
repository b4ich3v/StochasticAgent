#include "source/distributions/continuous_distributions/exponential/Exponential.h"
#include "source/data_structures/integration/Integral.h"
#include "source/data_structures/integration/trapezoidal_rule_intergral/TrapezoidalRuleIntergral.h"
#include "source/Constants.h"

Exponential::Exponential(double lambda): ContinuousRandomVariable([&]() {
    Vector<double> params;
    params.push_back(lambda);
    return params;
}(), ContinuousRandomVariableType::Exponential) {}

double Exponential::calculateProbability(const Interval& interval) const {
    Integral* integral = new TrapezoidalRuleIntergral(this->getDensityFunction(), COUNT_OF_SUB_INTERVALS);
    double result = integral->intergrate(interval.getLeftComponent(), interval.getRightComponent());

    delete integral;
    integral = nullptr;
    return result;
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