#include "SigmaAlgebra.h"

SigmaAlgebra::SigmaAlgebra(const Event& event) {
    this->constructSigmaAlgebra();
}

void SigmaAlgebra::constructSigmaAlgebra() {
    this->addEmptyEvent();
    this->addTheAddition();
    this->addTheUnionOfAddition();
}

void SigmaAlgebra::addEmptyEvent() {
    this->idSetForAllSubsetsOfEvents.addNumber(-1);
}