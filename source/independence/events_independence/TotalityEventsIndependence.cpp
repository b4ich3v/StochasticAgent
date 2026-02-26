#include "source/independence/events_independence/TotalityEventsIndependence.h"
#include "source/functions/probability_function/ProbabilityFunction.h"

bool TotalityEventsIndependence::operator () (const Vector<Event>& containerOfEvents, 
    Function<Event, double>* probabilityFunction) const {
    Event combinedEvent = containerOfEvents[0];
    for (size_t i = 1; i < containerOfEvents.getSize(); i++) {
        combinedEvent &= containerOfEvents[i];
    }
    
    double productResult = probabilityFunction->operator()(containerOfEvents[0]);;
    for (size_t i = 1; i < containerOfEvents.getSize(); i++) {
        productResult *= probabilityFunction->operator()(containerOfEvents[i]);
    }

    return probabilityFunction->operator()(combinedEvent) == productResult;
}