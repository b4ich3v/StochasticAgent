#include  "String.h"

class ЕlementaryEvent {
private:
    String eventDescription;
    int32_t realId = 0;
    static int32_t idMask;

    void setId();
    void setEventDescription(const String& eventDescription);

public:
    ЕlementaryEvent() = default;
    ЕlementaryEvent(const String& eventDescription);
    ЕlementaryEvent(const char* eventDescription);

    const String& getEventDescriptionn() const;
    int32_t getEventId() const;

    friend std::ostream& operator << (std::ostream& os, const ЕlementaryEvent& event);
    friend std::istream& operator >> (std::istream& is, ЕlementaryEvent& event);
};
