#include "ЕlementaryEvent.h"

int32_t ЕlementaryEvent::idMask = 0;

ЕlementaryEvent::ЕlementaryEvent(const char* eventDescription) {
    this->setEventDescription(String(eventDescription));
    this->setId();
}

ЕlementaryEvent::ЕlementaryEvent(const String& eventDescription) {
    this->setEventDescription(eventDescription);
    this->setId();
}

void ЕlementaryEvent::setId() {
    this->realId = this->idMask;
    this->idMask += 1;
}

void ЕlementaryEvent::setEventDescription(const String& eventDescription) {
    this->eventDescription = eventDescription;
}

int32_t ЕlementaryEvent::getEventId() const {
    return this->realId;
}

const String &ЕlementaryEvent::getEventDescriptionn() const {
    return this->eventDescription;
}

std::istream& operator >> (std::istream& is, ЕlementaryEvent& event) {
    String str;
    is >> str;
    event = ЕlementaryEvent(str);
    return is;
}

std::ostream& operator << (std::ostream& os, const ЕlementaryEvent& event) {
    os << "Event id: " << event.getEventId() << "\n";
    os << "Event description: " << event.getEventDescriptionn();
    return os;
}
