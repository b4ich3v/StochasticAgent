#include  "String.h"

class Event {
private:
    String eventDescription;
    int32_t realId = 0;
    static int32_t idMask;

    void setId();
    void setEventDescription(const String& eventDescription);

public:
    Event(const String& eventDescription);
    Event(const char* eventDescription);

    const String& getEventDescriptionn() const;
    int32_t getEventId() const;

    friend std::ofstream& operator << (std::ofstream& os, const Event& event);
    friend std::ifstream& operator >> (std::ifstream& is, Event& event);
};
