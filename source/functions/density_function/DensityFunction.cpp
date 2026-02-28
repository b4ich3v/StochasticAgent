#include "source/functions/density_function/DensityFunction.h"

DensityFunction::DensityFunction():
    Function<double, double>(Domain<double>(), Interval(0.0, std::numeric_limits<double>::infinity())) {}

DensityFunction::DensityFunction(const Domain<double>& domain, const Range<double>& range):
    Function<double, double>(domain, range) {}