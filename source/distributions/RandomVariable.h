#pragma once

#include <iostream>
#include "source/distributions/TypeOfRandomVariable.h"


template <class T>
class RandomVariable {
public:
    virtual double calculateProbability(T number) const = 0;
    virtual double getExpectation() const = 0;
    virtual double getVariance() const = 0;
    virtual TypeOfRandomVariable getKind() const = 0;
    virtual RandomVariable* clone() const = 0;
    virtual ~RandomVariable() = default;
};