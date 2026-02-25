#pragma once

#include "source/events/set_of_elementary_events/event/Event.h"


class Omega: public Event {
public:
    Omega() = default;
    explicit Omega(const Vector<ElementaryEvent>& elementaryEvents): Event(elementaryEvents) {}
};
