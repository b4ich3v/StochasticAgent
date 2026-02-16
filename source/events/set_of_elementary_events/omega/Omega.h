#pragma once

#include "../SetOfElementaryEvents.h"


class Omega: public SetOfElementaryEvents {
public:
    Omega() = default;
    Omega(const Vector<ElementaryEvent>& elementaryEvents)
        : SetOfElementaryEvents(elementaryEvents) {}
};
