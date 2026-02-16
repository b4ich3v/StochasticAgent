#include "source/events/set_of_elementary_events/omega/Omega.h"
#include "source/events/set_of_elementary_events/event/Event.h"
#include "source/sigma_algebra/SigmaAlgebraPattern.h"
#include "source/sigma_algebra/sigma_algebra_factory/SigmaAlgebraAbstractFactory.h"


class SigmaAlgebra {
private:
    Omega* omega = nullptr;
    SigmaAlgebraPattern pattern = SigmaAlgebraPattern::NONE;

    void addEmptyEvent();
    void addTheAddition();
    void addTheUnionOfAddition();
    
    void setOmegaRef(Omega* omega);
    void setSigmaAlgebraPattern(SigmaAlgebraPattern pattern);

public:
    SigmaAlgebra(Omega* omega, SigmaAlgebraPattern pattern);
    const Vector<Event> getContainerOfEvents() const;
    
    friend std::ostream& operator << (std::ostream& os, const SigmaAlgebra& sigmaAlgebra);
    friend std::istream& operator >> (std::istream& is, SigmaAlgebra& sigmaAlgebra);
};