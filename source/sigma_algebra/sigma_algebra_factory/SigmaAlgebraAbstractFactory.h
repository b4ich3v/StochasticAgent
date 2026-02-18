#pragma once

#include "../SigmaAlgebraPattern.h"

class SigmaAlgebra;
class Omega;


class SigmaAlgebraAbstractFactory {
public:
    virtual SigmaAlgebra* create(SigmaAlgebraPattern pattern, Omega* omega) const = 0;
    virtual ~SigmaAlgebraAbstractFactory() = default;
};
