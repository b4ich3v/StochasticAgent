#include "source/distributions/discrete_distributions/poisson/Poisson.h"
#include "source/data_structures/combinatorics/k_selection/KSelection.h"
#include "source/data_structures/combinatorics/factoriel/Factoriel.h"
#include "source/Constants.h"

Poisson::Poisson(size_t lambda) {
    this->setLambda(lambda);
}

double Poisson::calculateProbability(uint32_t number) const {
    return (HelperFunctions::power((uint32_t)this->lambda, number) / Factoriel().operator()(number)) * 
        HelperFunctions::power(EULER_NUMBER, -1 * this->lambda);
    
}

double Poisson::getExpectation() const {
    return this->lambda;
};

double Poisson::getVariance() const {
    return this->lambda;
}

RandomVariable<uint32_t>* Poisson::clone() const {
    return new Poisson(*this);
}