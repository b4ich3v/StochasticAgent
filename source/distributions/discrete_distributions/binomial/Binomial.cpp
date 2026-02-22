#include "source/distributions/discrete_distributions/binomial/Binomial.h"
#include "source/data_structures/combinatorics/k_selection/KSelection.h"

Binomial::Binomial(uint32_t countOfExperiments, Success success): RandomVariable(success, TypeOfRandomVariable::Discrete) {
    this->setCountOfExperiments(countOfExperiments);
}

Binomial::Binomial(const HeterogeneousContainer<RandomVariable<bool>>& countainerOfBernouliis): 
    RandomVariable(countainerOfBernouliis.getSize() > 0 ? countainerOfBernouliis[0]->getSuccessRate() : 0.0, TypeOfRandomVariable::Discrete) {
        if (countainerOfBernouliis.getSize() == 0) {
            throw std::logic_error("Binomial requires at least one Bernoulli trial");
        }

        const double probabilityForSuccess = countainerOfBernouliis[0]->getSuccessRate();
        for (size_t i = 1; i < countainerOfBernouliis.getSize(); i++) {
            if (countainerOfBernouliis[i]->getSuccessRate() != probabilityForSuccess) {
                throw std::logic_error("All Bernoulli trials must have identical success rate");
            }
        }

        this->setCountOfExperiments(countainerOfBernouliis.getSize());
}

uint32_t Binomial::getCountOfExperiments() const {
    return this->countOfExperiments;
}

void Binomial::setCountOfExperiments(uint32_t countOfExperiments) {
    if (countOfExperiments == 0) throw std::logic_error("Binomial requires at least one experiment");
    this->countOfExperiments = countOfExperiments;
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