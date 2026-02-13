#include "BitSet.h"
#include "Vector.hpp"
#include "Event.h"

class SetOfElementaryEvents {
private:
    Vector<Event> events;
    BitSet idSet;

    void free();

public:
    SetOfElementaryEvents() = default;
    SetOfElementaryEvents(const Vector<Event>& events);

    const Vector<Event>& getEvents() const;
    void addEvent(const Event& event);
    void removeEvent(int32_t eventId);

    friend std::ostream& operator << (std::ostream& os, const SetOfElementaryEvents& event);
    friend std::istream& operator >> (std::istream& is, SetOfElementaryEvents& event);
};


