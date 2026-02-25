#pragma once

#include "source/sigma_algebra/SigmaAlgebra.h"
#include "source/events/set_of_elementary_events/omega/Omega.h"
#include "source/functions/function/Function.hpp"


class VectorSpace {
private:
    const Omega* omega = nullptr;
    const SigmaAlgebra* sigmaAlgebra = nullptr;
    const Function<Event, uint32_t>* probabilityFunction = nullptr;

    void setOmega(const Omega* omega);
    void setSigmaAlgebra(const SigmaAlgebra* sigmaAlgebra);
    void setProbabilityFunction(const Function<Event, uint32_t>* probaprobabilityFunctionbiltiyFunction);

public:
    VectorSpace(const Omega* omega, const SigmaAlgebra* sigmaAlgebra, const Function<Event, uint32_t>* probabilityFunction);

    const Omega* getOmega() const;
    const SigmaAlgebra* getSigmaAlgebra() const;
    const Function<Event, uint32_t>* getProbabilityFunction() const;
};
