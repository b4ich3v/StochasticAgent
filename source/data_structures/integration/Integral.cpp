#include "source/data_structures/integration/Integral.h"

Integral::Integral(Function<double, double>* function, IntegrationApproximaton approximation) {
    this->setFunctionPtr(function);
    this->setIntegrationApproximaton(approximation);
}

void Integral::setFunctionPtr(Function<double, double>* function) {
    if (!function) throw std::runtime_error("Nullptr detected");
    this->function = function;
}

void Integral::setIntegrationApproximaton(IntegrationApproximaton approximation) {
    if (approximation == IntegrationApproximaton::None) 
        throw std::runtime_error("Approximation must be different from None");
    this->approximation = approximation;
}