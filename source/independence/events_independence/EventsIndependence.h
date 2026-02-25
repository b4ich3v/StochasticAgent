#pragma once

#include "source/events/set_of_elementary_events/event/Event.h"


class EventsIndependence {
public:
    bool operator () (const Event& left, const Event& right, 
        const SigmaAlgebra* sigmaAlgebra, ProbabilityFunctionFilter filter) const;
};