#include "source/events/vector_space/VectorSpace.h"

VectorSpace::VectorSpace(const Omega* omega, const SigmaAlgebra* sigmaAlgebra, const Function<Event, uint32_t>* probabilityFunction) {
    this->setOmega(omega);
    this->setProbabilityFunction(probabilityFunction);
    this->setSigmaAlgebra(sigmaAlgebra);
}

void VectorSpace::setOmega(const Omega* omega) {
    if (!omega) throw std::runtime_error("Nullptr detected");
    this->omega = omega;
}

void VectorSpace::setSigmaAlgebra(const SigmaAlgebra* sigmaAlgebra) {
    if (!sigmaAlgebra) throw std::runtime_error("Nullptr detected");
    this->sigmaAlgebra = sigmaAlgebra;
}

void VectorSpace::setProbabilityFunction(const Function<Event, uint32_t>* probabilityFunction) {
    if (!probabilityFunction) throw std::runtime_error("Nullptr detected");
    this->probabilityFunction = probabilityFunction;
}

const Omega* VectorSpace::getOmega() const {
    return this->omega;
}

const SigmaAlgebra* VectorSpace::getSigmaAlgebra() const {
    return this->sigmaAlgebra;
}

const Function<Event, uint32_t>* VectorSpace::getProbabilityFunction() const {
    return this->probabilityFunction;
}