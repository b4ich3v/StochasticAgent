#pragma once

#include "source/functions/probability_function/ProbabilityFunction.h"


class ConditionalProbabilityFunction: public ProbabilityFunction {
public:
    ConditionalProbabilityFunction(const SigmaAlgebra* sigmaAlgebra, ProbabilityFunctionFilter filter);
    double operator () (const Event& left, const Event& right) const;
};