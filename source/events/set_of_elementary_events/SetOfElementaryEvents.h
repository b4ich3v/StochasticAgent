#include "BitSet.h"
#include "Vector.hpp"
#include "ЕlementaryEvent.h"

class SetOfElementaryEvents {
private:
    Vector<ЕlementaryEvent> events;
    BitSet idSet;

    void free();

public:
    SetOfElementaryEvents() = default;
    SetOfElementaryEvents(const Vector<ЕlementaryEvent>& events);

    const Vector<ЕlementaryEvent>& getEvents() const;
    void addEvent(const ЕlementaryEvent& event);
    void removeEvent(int32_t eventId);

    friend std::ostream& operator << (std::ostream& os, const SetOfElementaryEvents& event);
    friend std::istream& operator >> (std::istream& is, SetOfElementaryEvents& event);
};


