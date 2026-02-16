#include "source/sigma_algebra/SigmaAlgebra.h"
#include "source/sigma_algebra/sigma_algebra_factory/SigmaAlgebraFactory.h"


int main() {
    ElementaryEvent e1("Event1");
    ElementaryEvent e2("Event2");
    ElementaryEvent e3("Event3");
    Vector<ElementaryEvent> elementaryEvents;
    elementaryEvents.push_back(e1);
    elementaryEvents.push_back(e2);
    elementaryEvents.push_back(e3);
    Omega omega(elementaryEvents);


    SigmaAlgebraAbstractFactory* sigmaFactory = new SigmaAlgebraFactory();
    SigmaAlgebra* sigma = sigmaFactory->create(SigmaAlgebraPattern::POWER_SET, &omega);
    Vector<Event> events = sigma->getContainerOfEvents();
    std::cout << events;

    return 0;
}
