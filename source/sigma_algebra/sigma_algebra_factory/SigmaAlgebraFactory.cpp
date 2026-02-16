#include "SigmaAlgebraFactory.h"
#include "source/sigma_algebra/SigmaAlgebra.h"

SigmaAlgebra* SigmaAlgebraFactory::create(SigmaAlgebraPattern pattern, Omega* omega) {
    switch (pattern) {
    case SigmaAlgebraPattern::TRIVIAL: return new SigmaAlgebra(omega, SigmaAlgebraPattern::TRIVIAL);
    case SigmaAlgebraPattern::POWER_SET: return new SigmaAlgebra(omega, SigmaAlgebraPattern::POWER_SET);
    default: throw std::logic_error("Not supported sigma-algebra pattern for constructoring");
    }
}