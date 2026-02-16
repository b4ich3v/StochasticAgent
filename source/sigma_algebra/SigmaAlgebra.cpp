#include "SigmaAlgebra.h"
#include "source/sigma_algebra/sigma_algebra_factory/SigmaAlgebraFactory.h"

SigmaAlgebra::SigmaAlgebra(Omega* omega, SigmaAlgebraPattern pattern) {
    this->setOmegaRef(omega);
    this->setSigmaAlgebraPattern(pattern);
}

void SigmaAlgebra::setOmegaRef(Omega* omega) {
    if (omega == nullptr) throw std::logic_error("Nullptr error");
    this->omega = omega;
}

void SigmaAlgebra::setSigmaAlgebraPattern(SigmaAlgebraPattern pattern) {
    if (pattern == SigmaAlgebraPattern::NONE) throw std::logic_error("Not selected pattern");
    this->pattern = pattern;
}