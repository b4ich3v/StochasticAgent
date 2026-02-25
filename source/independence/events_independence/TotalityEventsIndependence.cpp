#include "source/independence/events_independence/TotalityEventsIndependence.h"
#include "source/functions/probability_function/ProbabilityFunction.h"

bool TotalityEventsIndependence::operator () (const Vector<Event>& containerOfEvents, 
    const SigmaAlgebra* sigmaAlgebra, ProbabilityFunctionFilter filter) const {
    Event combinedEvent = containerOfEvents[0];
    for (size_t i = 1; i < containerOfEvents.getSize(); i++) {
        combinedEvent &= containerOfEvents[i];
    }
    
    double productResult = ProbabilityFunction(sigmaAlgebra, filter).operator()(containerOfEvents[0]);;
    for (size_t i = 1; i < containerOfEvents.getSize(); i++) {
        productResult *= ProbabilityFunction(sigmaAlgebra, filter).operator()(containerOfEvents[i]);
    }

    return ProbabilityFunction(sigmaAlgebra, filter).operator()(combinedEvent) == productResult;
}