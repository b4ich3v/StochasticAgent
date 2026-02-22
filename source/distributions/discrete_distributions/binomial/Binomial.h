#pragma once

#include "source/distributions/RandomVariable.hpp"
#include "source/distributions/discrete_distributions/bernoulii/Bernoulli.h"
#include "source/data_structures/heterogeneous_container/HeterogeneousContainer.hpp"


class Binomial: public RandomVariable<uint32_t> {
private:
    uint32_t countOfExperiments = 0;
    void setCountOfExperiments(uint32_t countOfExperiments);

public:
    Binomial(uint32_t countOfExperiments, Success success);
    Binomial(const HeterogeneousContainer<RandomVariable<bool>>& countainerOfBernouliis);
    uint32_t getCountOfExperiments() const;

    double calculateProbability(uint32_t number) const override;
    double getExpectation() const override;
    double getVariance() const override;
    RandomVariable* clone() const override;
};