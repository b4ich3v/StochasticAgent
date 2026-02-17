#include "ЕlementaryEvent.h"

int32_t ElementaryEvent::idMask = 0;

ElementaryEvent::ElementaryEvent() {
    this->realId = -1;
    this->setEventDescription("Empty elementary event");
}

ElementaryEvent::ElementaryEvent(const char* eventDescription) {
    this->setEventDescription(String(eventDescription));
    this->setId();
}

ElementaryEvent::ElementaryEvent(const String& eventDescription) {
    this->setEventDescription(eventDescription);
    this->setId();
}

void ElementaryEvent::setId() {
    this->realId = this->idMask;
    this->idMask += 1;
}

void ElementaryEvent::setEventDescription(const String& eventDescription) {
    this->eventDescription = eventDescription;
}

int32_t ElementaryEvent::getEventId() const {
    return this->realId;
}

const String &ElementaryEvent::getEventDescriptionn() const {
    return this->eventDescription;
}

ElementaryEvent& ElementaryEvent::operator |= (const ElementaryEvent& other) {
    *this = ElementaryEvent(this->getEventDescriptionn() + String(" | ") + other.getEventDescriptionn());
    return *this;
}

ElementaryEvent operator | (const ElementaryEvent& left, const ElementaryEvent& right) {
    ElementaryEvent result = left;
    result |= right;
    return result;
}

std::istream& operator >> (std::istream& is, ElementaryEvent& event) {
    String str;
    is >> str;
    event = ElementaryEvent(str);
    return is;
}

std::ostream& operator << (std::ostream& os, const ElementaryEvent& event) {
    os << "{ [ Event id: " << event.getEventId() << " ], ";
    os << "[ Event description: " << event.getEventDescriptionn() << " ] }";
    return os;
}
