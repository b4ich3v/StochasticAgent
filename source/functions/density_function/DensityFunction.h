#pragma once

#include "source/functions/function/Function.hpp"
#include "source/data_structures/interval/Interval.h"
#include <limits>


class DensityFunction: public Function<double, double> {
protected:
    DensityFunction(): Function<double, double>(Domain<double>(), Interval(0.0, std::numeric_limits<double>::infinity())) {}
};