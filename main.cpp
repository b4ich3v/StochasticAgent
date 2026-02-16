#include "source/sigma_algebra/SigmaAlgebra.h"


int main() {
    ElementaryEvent e1("Event1");
    ElementaryEvent e2("Event2");
    ElementaryEvent e3("Event3");
    ElementaryEvent e4("Event4");
    ElementaryEvent e5("Event5");
    Vector<ElementaryEvent> elementaryEvents;
    elementaryEvents.push_back(e1);
    elementaryEvents.push_back(e2);
    elementaryEvents.push_back(e3);
    elementaryEvents.push_back(e4);
    elementaryEvents.push_back(e5);

    Omega omega(elementaryEvents);
    std::cout << omega << std::endl;


    return 0;
}
