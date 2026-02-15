#include "source/events/set_of_elementary_events/Event.h"


class SigmaAlgebra {
private:
    Vector<Event> containerOfEvents;
    BitSet idSetForAllSubsetsOfEvents;

    void addEmptyEvent();
    void addTheAddition();
    void addTheUnionOfAddition();
    void constructSigmaAlgebra(); 

public:
    SigmaAlgebra(const Event& event);
};