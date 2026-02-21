#pragma once

#include "source/distributions/TypeOfRandomVariable.h"


class RandomVariable {
public:
    virtual double getExpectation() const = 0;
    virtual double getVariance() const = 0;
    virtual TypeOfRandomVariable getKind() const = 0;

    virtual RandomVariable* clone() const = 0;
    virtual ~RandomVariable() = default;
};