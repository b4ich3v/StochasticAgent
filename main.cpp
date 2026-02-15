#include "source/events/set_of_elementary_events/SetOfElementaryEvents.h"


int main() {
    BitSet b;
    b.addNumber(-1);
    b.addNumber(1313);
    b.addNumber(1);
    b.addNumber(23);
    std::cout << b;

    return 0;
}
