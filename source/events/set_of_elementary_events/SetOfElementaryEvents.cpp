#include "SetOfElementaryEvents.h"

SetOfElementaryEvents::SetOfElementaryEvents() {
    this->resetToNeutral();
}

SetOfElementaryEvents::SetOfElementaryEvents(const Vector<ElementaryEvent>& elementaryEvents) {
    this->resetToNeutral();

    for (size_t i = 0; i < elementaryEvents.getSize(); i++) {
        this->addElementaryEvent(elementaryEvents[i]);
    }
}

void SetOfElementaryEvents::addElementaryEvent(const ElementaryEvent& event) {
    if (this->idSet.hasNumber(event.getEventId())) return;
    this->idSet.addNumber(event.getEventId());
    this->elementaryEvents.push_back(event);
}

bool SetOfElementaryEvents::isElementaryEventIn(const ElementaryEvent& event) const {
    return this->idSet.hasNumber(event.getEventId());
}

void SetOfElementaryEvents::free() {
    resetToNeutral();
}

void SetOfElementaryEvents::clean() {
    free();
}

void SetOfElementaryEvents::resetToNeutral() {
    this->elementaryEvents = Vector<ElementaryEvent>();
    this->idSet = BitSet();
}

size_t SetOfElementaryEvents::findEventIndexById(int32_t id) const {
    for (size_t i = 0; i < this->elementaryEvents.getSize(); i++) {
        if (this->elementaryEvents[i].getEventId() == id) {
            return i;
        }
    }

    return this->elementaryEvents.getSize();
}

void SetOfElementaryEvents::removeEvent(int32_t eventId) {
    size_t index = this->findEventIndexById(eventId);
    if (index == this->elementaryEvents.getSize()) return;
    this->idSet.removeNumber(eventId);
    this->elementaryEvents.remove_at(index);
}

const BitSet& SetOfElementaryEvents::getIdSet() const {
    return this->idSet;
}

const Vector<ElementaryEvent>& SetOfElementaryEvents::getElementaryEvents() const {
    return this->elementaryEvents;
}

SetOfElementaryEvents& SetOfElementaryEvents::operator |= (const SetOfElementaryEvents& other) {
    for (size_t i = 0; i < other.getElementaryEvents().getSize(); i++) {
        addElementaryEvent(other.getElementaryEvents()[i]);
    }

    return *this;
}

SetOfElementaryEvents operator | (const SetOfElementaryEvents& left, const SetOfElementaryEvents& right) {
    SetOfElementaryEvents result = left;
    result |= right;
    
    return result;
}

std::ostream& operator << (std::ostream& os, const SetOfElementaryEvents& setOfElementaryEvents) {
    if (setOfElementaryEvents.getElementaryEvents().getSize() == 0) {
        os << "{ [ Event id: -1 ], [ Event description: Empty event ] }" << std::endl;
        return os;
    }

    for (size_t i = 0; i < setOfElementaryEvents.getElementaryEvents().getSize(); i++) {
        const auto& current = setOfElementaryEvents.getElementaryEvents()[i];
        if (setOfElementaryEvents.idSet.hasNumber(current.getEventId())) {
            os << current << std::endl;
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
