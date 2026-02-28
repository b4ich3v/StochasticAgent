#pragma once

#include "source/functions/function/Function.hpp"
#include "source/data_structures/interval/Interval.h"
#include <limits>


class DensityFunction: public Function<double, double> {
protected:
    DensityFunction();
    DensityFunction(const Domain<double>& domain, const Range<double>& range);
};