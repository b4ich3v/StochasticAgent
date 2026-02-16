#include "SetOfElementaryEvents.h"

SetOfElementaryEvents::SetOfElementaryEvents(const Vector<ElementaryEvent>& events): events(events) {
    for (size_t i = 0; i < this->events.getSize(); i++) {
        uint32_t currentId = this->events[i].getEventId();
        this->idSet.addNumber(currentId);
    }
}

void SetOfElementaryEvents::addElementaryEvent(const ElementaryEvent& event) {
    if (this->idSet.hasNumber(event.getEventId())) return;
    this->idSet.addNumber(event.getEventId());
    this->events.push_back(event);
}

bool SetOfElementaryEvents::isElementaryEventIn(const ElementaryEvent& event) const {
    return this->idSet.hasNumber(event.getEventId());
}

void SetOfElementaryEvents::free() {
    while (this->events.getSize() > 0) {
        this->events.pop();
    }
    this->idSet &= BitSet();
}

void SetOfElementaryEvents::clean() {
    free();
}

size_t SetOfElementaryEvents::findEventIndexById(int32_t id) const {
    for (size_t i = 0; i < this->events.getSize(); i++) {
        if (this->events[i].getEventId() == id) {
            return i;
        }
    }

    return -1;
}

void SetOfElementaryEvents::removeEvent(int32_t eventId) {
    this->idSet.removeNumber(eventId);
    this->events.remove_at(this->findEventIndexById(eventId));
}

const BitSet& SetOfElementaryEvents::getIdSet() const {
    return this->idSet;
}

const Vector<ElementaryEvent>& SetOfElementaryEvents::getEvents() const {
    return this->events;
}

std::ostream& operator << (std::ostream& os, const SetOfElementaryEvents& setOfElementaryEvents) {
    for (size_t i = 0; i < setOfElementaryEvents.getEvents().getSize(); i++) {
        if (setOfElementaryEvents.idSet.hasNumber(setOfElementaryEvents.getEvents()[i].getEventId())) {
            os << setOfElementaryEvents.getEvents()[i] << std::endl;
        }
    }

    return os;
}

std::istream& operator >> (std::istream& is, SetOfElementaryEvents& setOfElementaryEvents) {
    setOfElementaryEvents.free();
    String currentDescription;
    uint32_t countOfEvents;
    is >> countOfEvents;

    for (size_t i = 0; i < countOfEvents; i++) {
        is >> currentDescription;
        ElementaryEvent currentEvent = ElementaryEvent(currentDescription);
        setOfElementaryEvents.addElementaryEvent(currentEvent);
    }

    return is;
}
