#include "SetOfElementaryEvents.h"

SetOfElementaryEvents::SetOfElementaryEvents(const Vector<Event>& events) {
    this->events = events;
}

void SetOfElementaryEvents::addEvent(const Event& event) {
    if (this->idSet.hasNumber(event.getEventId())) return;
    this->idSet.addNumber(event.getEventId());
    this->events.push(event);
}

void SetOfElementaryEvents::free() {
    while (this->events.getSize() > 0) {
        this->events.pop();
    }
    this->idSet &= BitSet();
}

void SetOfElementaryEvents::removeEvent(int32_t eventId) {
    this->idSet.removeNumber(eventId);
}

const Vector<Event>& SetOfElementaryEvents::getEvents() const {
    return this->events;
}

std::ostream& operator << (std::ostream& os, const SetOfElementaryEvents& setOfElementaryEvents) {
    for (int i = 0; i < setOfElementaryEvents.getEvents().getSize(); i++) os << setOfElementaryEvents.getEvents()[i];
    return os;
}

std::istream& operator >> (std::istream& is, SetOfElementaryEvents& setOfElementaryEvents) {
    setOfElementaryEvents.free();
    String currentDescription;
    uint32_t countOfEvents;
    is >> countOfEvents;

    for (int i = 0; i < countOfEvents; i++) {
        is >> currentDescription;
        Event currentEvent = Event(currentDescription);
        setOfElementaryEvents.addEvent(currentEvent);
    }

    return is;
}
