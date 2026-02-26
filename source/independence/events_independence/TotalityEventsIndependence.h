#pragma once

#include "source/data_structures/vector/Vector.hpp"
#include "source/events/set_of_elementary_events/event/Event.h"
#include "source/functions/function/Function.hpp"


class TotalityEventsIndependence {
public:
    bool operator () (const Vector<Event>& containerOfEvents, 
        Function<Event, double>* probabilityFunction) const;
};
