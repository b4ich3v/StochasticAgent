#pragma once

#include <iostream>
#include <stdexcept>
#include "source/distributions/TypeOfRandomVariable.h"
#include "source/distributions/RandomVariable.hpp"
#include "source/functions/probability_function/ProbabilityFunction.h"

typedef double Success;
typedef double Failure;


template <class T>
class BernoulliSchemeRandomVariable: public RandomVariable<T> {
private:
    TypeOfRandomVariable type = TypeOfRandomVariable::None;
    Success success = 0.0;
    Failure failure = 0.0;

    void setType(TypeOfRandomVariable type);
    void setSuccessRate(Success success);
    void setFailureRate(Failure failure);

public:
    BernoulliSchemeRandomVariable(Success success, TypeOfRandomVariable type);

    Success getSuccessRate() const;
    Failure getFailureRate() const;
    TypeOfRandomVariable getType() const;
};

template <class T>
BernoulliSchemeRandomVariable<T>::BernoulliSchemeRandomVariable(Success success, TypeOfRandomVariable type) {
    this->setType(type);
    this->setSuccessRate(success);
    this->setFailureRate(1 - success);
}

template <class T>
void BernoulliSchemeRandomVariable<T>::setType(TypeOfRandomVariable type) {
    if (type == TypeOfRandomVariable::None) throw std::logic_error("Must be type different from None");
    this->type = type;
}

template <class T>
void BernoulliSchemeRandomVariable<T>::setSuccessRate(Success success) {
    if (success < 0 || success > 1) throw std::logic_error("Success rate must be between 0 and 1");
    this->success = success;
}

template <class T>
void BernoulliSchemeRandomVariable<T>::setFailureRate(Failure failure) {
    if (failure < 0 || failure > 1) throw std::logic_error("Failure rate must be between 0 and 1");
    this->failure = failure;
}

template <class T>
Success BernoulliSchemeRandomVariable<T>::getSuccessRate() const {
    return this->success;
}

template <class T>
Failure BernoulliSchemeRandomVariable<T>::getFailureRate() const {
    return this->failure;
}

template <class T>
TypeOfRandomVariable BernoulliSchemeRandomVariable<T>::getType() const {
    return this->type;
}