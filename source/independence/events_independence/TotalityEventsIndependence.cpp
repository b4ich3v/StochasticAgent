#include "source/independence/events_independence/TotalityEventsIndependence.h"

bool TotalityEventsIndependence::operator () (const Vector<Event>& containerOfEvents) const {
    Event combinedEvent;

    for (size_t i = 0; i < containerOfEvents.getSize(); i++) {
        combinedEvent &= containerOfEvents[i];    
    }
    

}