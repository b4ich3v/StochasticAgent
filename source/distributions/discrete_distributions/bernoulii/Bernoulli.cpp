#include "source/distributions/discrete_distributions/bernoulii/Bernoulli.h"

Bernoulli::Bernoulli(Success success): RandomVariable(success, TypeOfRandomVariable::Discrete) {}

double Bernoulli::calculateProbability(bool number) const {
    if (number == 1) return this->getSuccessRate();
    else if (number == 0) return this->getFailureRate();
    else throw std::logic_error("Bolean must be 0 or 1");
}

double Bernoulli::getExpectation() const {
    return this->getSuccessRate();
}

double Bernoulli::getVariance() const {
    return this->getFailureRate() * this->getSuccessRate();
}

RandomVariable<bool>* Bernoulli::clone() const {
    return new Bernoulli(*this);
}
