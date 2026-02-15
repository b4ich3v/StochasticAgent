#include "source/events/set_of_elementary_events/SetOfElementaryEvents.h"


class SigmaAlgebra {
private:
    Vector<SetOfElementaryEvents> containerOfEvents;

    void addEmptyEvent();
    void addTheAddition();
    void addTheUnionOfAddition();
    void constructSigmaAlgebra(); 

public:
    SigmaAlgebra(const SetOfElementaryEvents& setOfEvents);
};