#pragma once

#include "../SetOfElementaryEvents.h"


class Event: public SetOfElementaryEvents {
public:
    Event() = default;
    Event(const Vector<ElementaryEvent>& elementaryEvents)
        : SetOfElementaryEvents(elementaryEvents) {}
};
