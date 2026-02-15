#include "source/events/set_of_elementary_events/SetOfElementaryEvents.h"


int main() {
    ЕlementaryEvent e1(String("Event1"));
    ЕlementaryEvent e2(String("Event2"));
    ЕlementaryEvent e3(String("Event3"));
    Vector<ЕlementaryEvent> arr;
    arr.push_back(e1);
    arr.push_back(e2);
    arr.push_back(e3);

    SetOfElementaryEvents set(arr);
    set.removeEvent(1);
    std::cout << set << std::endl;

    BitSet bitSet = set.getIdSet();
    std::cout << bitSet;
    

    return 0;
}
