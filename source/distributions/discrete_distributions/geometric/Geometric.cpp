#include "source/distributions/discrete_distributions/geometric/Geometric.h"
#include "source/data_structures/combinatorics/k_selection/KSelection.h"

Geometric::Geometric(Success success): BernoulliSchemeRandomVariable(success, TypeOfRandomVariable::Discrete) {}

double Geometric::calculateProbability(uint32_t number) const {
    return this->getSuccessRate() * HelperFunctions::power(this->getFailureRate(), number - 1);
}

double Geometric::getExpectation() const {
    return this->getFailureRate() / this->getSuccessRate();
}

double Geometric::getVariance() const {
    return this->getFailureRate() / HelperFunctions::power(this->getSuccessRate(), 2);
}

BernoulliSchemeRandomVariable<uint32_t>* Geometric::clone() const {
    return new Geometric(*this);
}
