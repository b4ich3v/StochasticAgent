#include "source/data_structures/vector/Vector.hpp"
#include "source/events/еlementary_еvent/ЕlementaryEvent.h"


int main() {
    ЕlementaryEvent e1(String("Event1"));
    ЕlementaryEvent e2(String("Event2"));
    ЕlementaryEvent e3(String("Event3"));
    Vector<ЕlementaryEvent> arr;
    arr.push_back(e1);
    arr.push_back(e2);
    arr.push_back(e3);
    // arr.remove_at(0);
    // arr.remove_at(0);

    std::cout << arr << std::endl;

    return 0;
}
