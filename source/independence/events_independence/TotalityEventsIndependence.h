#pragma once

#include "source/data_structures/vector/Vector.hpp"
#include "source/events/set_of_elementary_events/event/Event.h"


class TotalityEventsIndependence {
public:
    bool operator () (const Vector<Event>& containerOfEvents, 
        const SigmaAlgebra* sigmaAlgebra, ProbabilityFunctionFilter filter) const;
};
