#include "source/distributions/discrete_distributions/binomial/Binomial.h"
#include "source/data_structures/combinatorics/k_selection/KSelection.h"

Binomial::Binomial(uint32_t countOfExperiments, Success success): RandomVariable(success, TypeOfRandomVariable::Discrete) {
    this->setCountOfExperiments(countOfExperiments);
}

Binomial::Binomial(const HeterogeneousContainer<RandomVariable<bool>>& countainerOfBernouliis): 
    RandomVariable(countainerOfBernouliis[0]->getSuccessRate(), TypeOfRandomVariable::Discrete) {
        this->setCountOfExperiments(countainerOfBernouliis.getSize());
}

uint32_t Binomial::getCountOfExperiments() const {
    return this->countOfExperiments;
}

double Binomial::calculateProbability(uint32_t number) const {
    if (number > this->countOfExperiments) return 0.0;
    return KSelection(KSelectionPattern::Combination, this->countOfExperiments, number).generateCount() * 
        HelperFunctions::power(this->getSuccessRate(), number) * 
        HelperFunctions::power(this->getFailureRate(), this->countOfExperiments - number);
}

double Binomial::getExpectation() const {
    return this->getSuccessRate() * this->countOfExperiments;
}

double Binomial::getVariance() const {
    return this->getSuccessRate() * this->getFailureRate() * this->countOfExperiments;
}

RandomVariable<uint32_t>* Binomial::clone() const {
    return new Binomial(*this);
}