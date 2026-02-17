#pragma once

#include "../../data_structures/string/String.h"

class ElementaryEvent {
private:
    String eventDescription;
    int32_t realId = 0;
    static int32_t idMask;

    void setId();
    void setEventDescription(const String& eventDescription);

public:
    ElementaryEvent();
    ElementaryEvent(const String& eventDescription);
    ElementaryEvent(const char* eventDescription);

    const String& getEventDescriptionn() const;
    int32_t getEventId() const;

    friend std::ostream& operator << (std::ostream& os, const ElementaryEvent& event);
    friend std::istream& operator >> (std::istream& is, ElementaryEvent& event);
};
