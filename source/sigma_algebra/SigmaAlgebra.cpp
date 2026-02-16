#include "SigmaAlgebra.h"
#include "sigma_algebra_factory/SigmaAlgebraFactory.h"
#include <stdexcept>

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

const Vector<Event>& SigmaAlgebra::getContainerOfEvents() const {
    return this->containerOfEvents;
}

void SigmaAlgebra::addEmptyEvent() {
    Event emptyEvent;
    emptyEvent.addElementaryEvent();
}

std::ostream& operator << (std::ostream& os, const SigmaAlgebra& sigmaAlgebra) {
    for (size_t i = 0; i < sigmaAlgebra.getContainerOfEvents().getSize(); i++) {
        os << sigmaAlgebra.getContainerOfEvents()[i];
    }
    
    return os;
}
