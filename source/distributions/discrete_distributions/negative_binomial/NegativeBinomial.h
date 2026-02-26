#pragma once

#include <cstdint>
#include "source/distributions/BernoulliSchemeRandomVariable.hpp"
#include "source/distributions/discrete_distributions/bernoulii/Bernoulli.h"
#include "source/data_structures/heterogeneous_container/HeterogeneousContainer.hpp"


class NegativeBinomial: public BernoulliSchemeRandomVariable<uint32_t> {
private:
    uint32_t successesTarget = 0;
    void setCountOfExperiments(uint32_t successesTarget);

public:
    NegativeBinomial(uint32_t successesTarget, Success success);
    NegativeBinomial(const HeterogeneousContainer<BernoulliSchemeRandomVariable<uint32_t>>& countainerOfGeometrics);
    uint32_t getCountOfSuccessesTarget() const;

    double calculateProbability(const uint32_t& number) const override;
    double getExpectation() const override;
    double getVariance() const override;
    BernoulliSchemeRandomVariable<uint32_t>* clone() const override;
};