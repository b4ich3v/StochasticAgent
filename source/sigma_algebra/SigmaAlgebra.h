#include "source/events/set_of_elementary_events/omega/Omega.h"
#include "source/events/set_of_elementary_events/event/Event.h"


class SigmaAlgebra {
private:
    Vector<Event> containerOfEvents;
    BitSet idSetForAllSubsetsOfEvents;

    void addEmptyEvent();
    void addTheAddition();
    void addTheUnionOfAddition();
    void constructSigmaAlgebra(); 

public:
    SigmaAlgebra(const Omega& event);
};