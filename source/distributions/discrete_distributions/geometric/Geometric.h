#pragma once

#include "source/distributions/BernoulliSchemeRandomVariable.hpp"


class Geometric: public BernoulliSchemeRandomVariable<uint32_t> {
public:
    Geometric(Success success);

    double calculateProbability(const uint32_t& number) const override;
    double getExpectation() const override;
    double getVariance() const override;
    BernoulliSchemeRandomVariable<uint32_t>* clone() const override;
};