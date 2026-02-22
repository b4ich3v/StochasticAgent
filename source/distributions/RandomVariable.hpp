#pragma once

#include <iostream>
#include "source/distributions/TypeOfRandomVariable.h"
#include "source/functions/probability_function/ProbabilityFunction.h"


template <class T>
class RandomVariable {
private:
    const ProbabilityFunction* probabilityFunction = nullptr;
    void setProbabilityFunction(const ProbabilityFunction* probabilityFunction);

public:
    RandomVariable(const ProbabilityFunction* probabilityFunction);
    const ProbabilityFunction* getProbabiltiyFunction() const;

    virtual double calculateProbability(T number) const = 0;
    virtual double getExpectation() const = 0;
    virtual double getVariance() const = 0;
    virtual TypeOfRandomVariable getType() const = 0;
    virtual RandomVariable* clone() const = 0;
    virtual ~RandomVariable() = default;
};

template <class T>
RandomVariable<T>::RandomVariable(const ProbabilityFunction* probabilityFunction) {
    this->setProbabilityFunction(probabilityFunction);
}

template <class T>
void RandomVariable<T>::setProbabilityFunction(const ProbabilityFunction* probabilityFunction) {
    if (!probabilityFunction) throw std::runtime_error("Nullptr detected");
    this->probabilityFunction = probabilityFunction;
}


template <class T>
const ProbabilityFunction* RandomVariable<T>::getProbabiltiyFunction() const {
    return this->probabilityFunction;
}