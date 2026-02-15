#include "SigmaAlgebra.h"

SigmaAlgebra::SigmaAlgebra(const Omega& event, SigmaAlgebraPattern pattern) {
    this->constructSigmaAlgebra();
}

void SigmaAlgebra::constructSigmaAlgebra() {
    this->addEmptyEvent();
    this->addTheAddition();
    this->addTheUnionOfAddition();
}