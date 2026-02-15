#include "../../data_structures/bitset/BitSet.h"
#include "../../data_structures/vector/Vector.hpp"
#include "../еlementary_еvent/ЕlementaryEvent.h"


class SetOfElementaryEvents {
private:
    Vector<ЕlementaryEvent> events;
    BitSet idSet;

    void free();
    size_t findEventIndexById(int32_t id) const;

public:
    SetOfElementaryEvents() = default;
    SetOfElementaryEvents(const Vector<ЕlementaryEvent>& events);

    const Vector<ЕlementaryEvent>& getEvents() const;
    void addEvent(const ЕlementaryEvent& event);
    void removeEvent(int32_t eventId);
    void clean();

    friend std::ostream& operator << (std::ostream& os, const SetOfElementaryEvents& event);
    friend std::istream& operator >> (std::istream& is, SetOfElementaryEvents& event);
};


