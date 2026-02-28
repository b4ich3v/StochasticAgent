#pragma once

#include "source/functions/Function.hpp"
#include "source/data_structures/integration/IntegrationApproximaton.h"
#include <stdexcept>


class Integral {
protected:
    const Function<double, double>* function = nullptr;
    IntegrationApproximaton approximation = IntegrationApproximaton::None;

    void setFunctionPtr(const Function<double, double>* function);
    void setIntegrationApproximaton(IntegrationApproximaton approximation);

public:
    Integral(const Function<double, double>* function, IntegrationApproximaton approximation);

    virtual double intergrate(double lower, double upper) const = 0;
    virtual Integral* clone() const = 0;
    virtual ~Integral() = default;
};
