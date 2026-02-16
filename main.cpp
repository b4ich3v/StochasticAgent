#include "source/events/set_of_elementary_events/SetOfElementaryEvents.h"


int main() {
    ЕlementaryEvent e1("Event 1");
    ЕlementaryEvent e2("Event 2");
    ЕlementaryEvent e3("Event 3");
    ЕlementaryEvent e4("Event 4");

    SetOfElementaryEvents set;
    set.addEvent(e1);
    set.addEvent(e2);
    set.addEvent(e3);
    set.addEvent(e4);

    std::cout << set << std::endl;
    std::cout << set.isElementaryEventIn(e1);

    return 0;
}
