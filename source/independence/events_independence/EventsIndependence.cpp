#include "source/independence/events_independence/EventsIndependence.h"
#include "source/functions/probability_function/ProbabilityFunction.h"

bool EventsIndependence::operator () (const Event& left, const Event& right, 
    Function<Event, double>* probabilityFunction) const {
    return probabilityFunction->operator()(left) * 
        probabilityFunction->operator()(right) == 
        probabilityFunction->operator()(left & right);
}
