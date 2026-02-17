#include "SetOfElementaryEvents.h"

SetOfElementaryEvents::SetOfElementaryEvents() {
    this->idSet.addNumber(-1);
    this->events.push_back(ElementaryEvent());
}

SetOfElementaryEvents::SetOfElementaryEvents(const Vector<ElementaryEvent>& elementaryEvents): events(elementaryEvents) {
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
    this->events = Vector<ElementaryEvent>();
    this->idSet = BitSet();
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

    return this->events.getSize();
}

void SetOfElementaryEvents::removeEvent(int32_t eventId) {
    size_t idx = this->findEventIndexById(eventId);
    if (idx == this->events.getSize()) return;
    this->idSet.removeNumber(eventId);
    this->events.remove_at(idx);
}

const BitSet& SetOfElementaryEvents::getIdSet() const {
    return this->idSet;
}

const Vector<ElementaryEvent>& SetOfElementaryEvents::getElementaryEvents() const {
    return this->events;
}

std::ostream& operator << (std::ostream& os, const SetOfElementaryEvents& setOfElementaryEvents) {
    for (size_t i = 0; i < setOfElementaryEvents.getElementaryEvents().getSize(); i++) {
        if (setOfElementaryEvents.idSet.hasNumber(setOfElementaryEvents.getElementaryEvents()[i].getEventId())) {
            os << setOfElementaryEvents.getElementaryEvents()[i] << std::endl;
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
