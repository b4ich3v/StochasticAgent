#include "source/events/probability_space/ProbabilitySpace.h"

ProbabilitySpace::ProbabilitySpace(const Omega* omega, const SigmaAlgebra* sigmaAlgebra, const Function<Event, double>* probabilityFunction) {
    this->setOmega(omega);
    this->setProbabilityFunction(probabilityFunction);
    this->setSigmaAlgebra(sigmaAlgebra);
}

void ProbabilitySpace::setOmega(const Omega* omega) {
    if (!omega) throw std::runtime_error("Nullptr detected");
    this->omega = omega;
}

void ProbabilitySpace::setSigmaAlgebra(const SigmaAlgebra* sigmaAlgebra) {
    if (!sigmaAlgebra) throw std::runtime_error("Nullptr detected");
    this->sigmaAlgebra = sigmaAlgebra;
}

void ProbabilitySpace::setProbabilityFunction(const Function<Event, double>* probabilityFunction) {
    if (!probabilityFunction) throw std::runtime_error("Nullptr detected");
    this->probabilityFunction = probabilityFunction;
}

const Omega* ProbabilitySpace::getOmega() const {
    return this->omega;
}

const SigmaAlgebra* ProbabilitySpace::getSigmaAlgebra() const {
    return this->sigmaAlgebra;
}

const Function<Event, double>* ProbabilitySpace::getProbabilityFunction() const {
    return this->probabilityFunction;
}