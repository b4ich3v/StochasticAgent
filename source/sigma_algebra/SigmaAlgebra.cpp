#include "SigmaAlgebra.h"

SigmaAlgebra::SigmaAlgebra(const SetOfElementaryEvents& events) {
    this->constructSigmaAlgebra();
}

void SigmaAlgebra::constructSigmaAlgebra() {
    this->addEmptyEvent();
    this->addTheAddition();
    this->addTheUnionOfAddition();
}

void SigmaAlgebra::addEmptyEvent() {
    
}