#pragma once

#include <iostream>
#include "source/distributions/TypeOfRandomVariable.h"
#include "source/functions/probability_function/ProbabilityFunction.h"

typedef double Success;
typedef double Failure;


template <class T>
class RandomVariable {
private:
    TypeOfRandomVariable type = TypeOfRandomVariable::NONE;
    Success success = 0.0;
    Failure failure = 0.0;

    void setType(TypeOfRandomVariable type);
    void setSuccessRate(Success success);
    void setFailureRate(Failure failure);

public:
    RandomVariable(Success success, TypeOfRandomVariable type);

    Success getSuccessRate() const;
    Failure getFailureRate() const;
    TypeOfRandomVariable getType() const;

    virtual double calculateProbability(T number) const = 0;
    virtual double getExpectation() const = 0;
    virtual double getVariance() const = 0;
    virtual RandomVariable* clone() const = 0;
    virtual ~RandomVariable() = default;
};

template <class T>
RandomVariable<T>::RandomVariable(Success success, TypeOfRandomVariable type) {
    this->setType(type);
    this->setSuccessRate(success);
    this->setFailureRate(1 - success);
}

template <class T>
void RandomVariable<T>::setType(TypeOfRandomVariable type) {
    if (type == TypeOfRandomVariable::NONE) throw std::logic_error("Must be type different from None");
    this->type = type;
}

template <class T>
void RandomVariable<T>::setSuccessRate(Success success) {
    if (success < 0 || success > 1) throw std::logic_error("Success rate must be between 0 and 1");
    this->success = success;
}

template <class T>
void RandomVariable<T>::setFailureRate(Failure failure) {
    if (failure < 0 || failure > 1) throw std::logic_error("Failure rate must be between 0 and 1");
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

template <class T>
TypeOfRandomVariable RandomVariable<T>::getType() const {
    return this->type;
}