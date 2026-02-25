#include "source/independence/events_independence/EventsIndependence.h"
#include "source/functions/probability_function/ProbabilityFunction.h"

bool EventsIndependence::operator () (const Event& left, const Event& right, 
    const SigmaAlgebra* sigmaAlgebra, ProbabilityFunctionFilter filter) const {
    return ProbabilityFunction(sigmaAlgebra, filter).operator()(left) == 
        ProbabilityFunction(sigmaAlgebra, filter).operator()(right);
}
