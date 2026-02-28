#pragma once

#include "source/events/set_of_elementary_events/event/Event.h"
#include "source/functions/Function.hpp"


class EventsIndependence {
public:
    bool operator () (const Event& left, const Event& right, 
        Function<Event, double>* probabilityFunction) const;
};