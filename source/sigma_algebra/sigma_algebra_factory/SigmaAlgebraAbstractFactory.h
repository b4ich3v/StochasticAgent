#include "../SigmaAlgebraPattern.h"


class SigmaAlgebraAbstractFactory {
public:
    virtual SigmaAlgebra* create(SigmaAlgebraPattern pattern, Omega* omega) = 0;
    virtual ~SigmaAlgebraAbstractFactory() = default;
};