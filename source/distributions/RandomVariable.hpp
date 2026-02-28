#pragma once

#include "source/distributions/RandomVariableType.h"


template <class T>
class RandomVariable {
public:
    virtual double calculateProbability(const T& number) const = 0;
    virtual double getExpectation() const = 0;
    virtual double getVariance() const = 0;
    virtual RandomVariableType getOverallType() const = 0;
    virtual RandomVariable* clone() const = 0;
    virtual ~RandomVariable() = default;
};