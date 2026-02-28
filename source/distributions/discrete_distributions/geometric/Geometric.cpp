#include "source/distributions/discrete_distributions/geometric/Geometric.h"
#include "source/data_structures/combinatorics/k_selection/KSelection.h"

Geometric::Geometric(Success success): BernoulliSchemeRandomVariable(success, TypeOfRandomVariable::Discrete) {}

double Geometric::calculateProbability(const uint32_t& number) const {
    return this->getSuccessRate() * std::pow(this->getFailureRate(), number);
}

double Geometric::getExpectation() const {
    return this->getFailureRate() / this->getSuccessRate();
}

double Geometric::getVariance() const {
    return this->getFailureRate() / std::pow(this->getSuccessRate(), 2);
}

BernoulliSchemeRandomVariable<uint32_t>* Geometric::clone() const {
    return new Geometric(*this);
}
