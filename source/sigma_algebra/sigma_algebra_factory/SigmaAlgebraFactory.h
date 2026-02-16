#pragma once

#include "SigmaAlgebraAbstractFactory.h"


class SigmaAlgebraFactory: public SigmaAlgebraAbstractFactory {
public:
    SigmaAlgebra* create(SigmaAlgebraPattern pattern, Omega* omega) override;
};
