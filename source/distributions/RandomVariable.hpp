#pragma once

#include <iostream>
#include "source/distributions/TypeOfRandomVariable.h"
#include "source/functions/probability_function/ProbabilityFunction.h"

typedef double Success;
typedef double Failure;


template <class T>
class RandomVariable {
private:
    Success success = 0.0;
    Failure failure = 0.0;

    void setSuccessRate(Success success);
    void setFailureRate(Failure failure);

public:
    RandomVariable(Success success);

    Success getSuccessRate() const;
    Failure getFailureRate() const;

    virtual double calculateProbability(T number) const = 0;
    virtual double getExpectation() const = 0;
    virtual double getVariance() const = 0;
    virtual TypeOfRandomVariable getType() const = 0;
    virtual RandomVariable* clone() const = 0;
    virtual ~RandomVariable() = default;
};

template <class T>
RandomVariable<T>::RandomVariable(Success success) {
    this->setSuccessRate(success);
    this->setFailureRate(1 - success);
}

template <class T>
void RandomVariable<T>::setSuccessRate(Success success) {
    this->success = success;
}

template <class T>
void RandomVariable<T>::setFailureRate(Failure failure) {
    this->failure = failure;
}

template <class T>
Success RandomVariable<T>::getSuccessRate() const {
    return this->success;
}

template <class T>
Failure RandomVariable<T>::getFailureRate() const {
    return this->failure;
}