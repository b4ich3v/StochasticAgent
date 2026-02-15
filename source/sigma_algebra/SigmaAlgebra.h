#include "source/events/set_of_elementary_events/omega/Omega.h"
#include "source/events/set_of_elementary_events/event/Event.h"
#include "source/sigma_algebra/SigmaAlgebraPattern.h"


class SigmaAlgebra {
private:
    Vector<Event> containerOfEvents;
    SigmaAlgebraPattern pattern;
    // to be done: implement different consructing patterns for sigma-algebra

    void addEmptyEvent();
    void addTheAddition();
    void addTheUnionOfAddition();
    void constructSigmaAlgebra(); 

public:
    SigmaAlgebra(const Omega& event, SigmaAlgebraPattern pattern);
};