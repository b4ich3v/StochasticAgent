#include "Event.h"

int32_t Event::idMask = 0;

Event::Event(const char* eventDescription) {
    this->setEventDescription(String(eventDescription));
    this->setId();
}

Event::Event(const String& eventDescription) {
    this->setEventDescription(eventDescription);
    this->setId();
}

void Event::setId() {
    this->realId = this->idMask;
    this->idMask += 1;
}

void Event::setEventDescription(const String& eventDescription) {
    this->eventDescription = eventDescription;
}

int32_t Event::getEventId() const {
    return this->realId;
}

const String &Event::getEventDescriptionn() const {
    return this->eventDescription;
}

std::istream& operator >> (std::istream& is, Event& event) {
    String str;
    is >> str;
    event = Event(str);
    return is;
}

std::ostream& operator << (std::ostream& os, const Event& event) {
    os << "Event id: " << event.getEventId() << "\n";
    os << "Event description: " << event.getEventDescriptionn() << "\n";
    return os;
}
