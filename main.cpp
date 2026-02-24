#include "source/sigma_algebra/SigmaAlgebra.h"
#include "source/sigma_algebra/sigma_algebra_factory/SigmaAlgebraFactory.h"
#include "source/distributions/discrete_distributions/binomial/Binomial.h"
#include "source/distributions/BernoulliSchemeRandomVariable.hpp"
#include <iostream>


int main() {
    BernoulliSchemeRandomVariable<uint32_t>* bin = new Binomial(2, 0.5);
    std::cout << bin->calculateProbability(2) << std::endl;

    delete bin;
    return 0;
}
