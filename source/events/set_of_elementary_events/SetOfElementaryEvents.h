#pragma once

#include "../../data_structures/bitset/BitSet.h"
#include "../../data_structures/vector/Vector.hpp"
#include "../elementary_event/ElementaryEvent.h"


class SetOfElementaryEvents {
private:
    Vector<ElementaryEvent> elementaryEvents;
    BitSet idSet;

    void free();
    void resetToNeutral();
    size_t findEventIndexById(int32_t id) const;

public:
    SetOfElementaryEvents();
    SetOfElementaryEvents(const Vector<ElementaryEvent>& elementaryEvents);
    SetOfElementaryEvents& operator |= (const SetOfElementaryEvents& other);

    const Vector<ElementaryEvent>& getElementaryEvents() const;
    const BitSet& getIdSet() const;

    void addElementaryEvent(const ElementaryEvent& event);
    void removeEvent(int32_t eventId);
    bool isElementaryEventIn(const ElementaryEvent& event) const;
    void clean();

    friend std::ostream& operator << (std::ostream& os, const SetOfElementaryEvents& event);
    friend std::istream& operator >> (std::istream& is, SetOfElementaryEvents& event);
};

SetOfElementaryEvents operator | (const SetOfElementaryEvents& left, const SetOfElementaryEvents& right);
