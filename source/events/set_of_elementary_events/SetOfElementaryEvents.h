#pragma once

#include "../../data_structures/bitset/BitSet.h"
#include "../../data_structures/vector/Vector.hpp"
#include "../еlementary_еvent/ЕlementaryEvent.h"


class SetOfElementaryEvents {
private:
    Vector<ElementaryEvent> events;
    BitSet idSet;

    void free();
    size_t findEventIndexById(int32_t id) const;

public:
    SetOfElementaryEvents() = default;
    SetOfElementaryEvents(const Vector<ElementaryEvent>& events);

    const Vector<ElementaryEvent>& getEvents() const;
    const BitSet& getIdSet() const;

    void addElementaryEvent(const ElementaryEvent& event);
    void removeEvent(int32_t eventId);
    bool isElementaryEventIn(const ElementaryEvent& event) const;
    void clean();

    friend std::ostream& operator << (std::ostream& os, const SetOfElementaryEvents& event);
    friend std::istream& operator >> (std::istream& is, SetOfElementaryEvents& event);
};

