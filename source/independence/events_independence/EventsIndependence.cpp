#include "source/independence/events_independence/EventsIndependence.h"
#include "source/functions/probability_function/ProbabilityFunction.h"
#include "source/Constants.h"
#include <cmath>
#include <stdexcept>

bool EventsIndependence::operator () (const Event& left, const Event& right, 
    Function<Event, double>* probabilityFunction) const {
    if (!probabilityFunction) throw std::logic_error("Probability function pointer is null");

    double pLeft = probabilityFunction->operator()(left);
    double pRight = probabilityFunction->operator()(right);
    double pIntersection = probabilityFunction->operator()(left & right);

    return std::fabs(pLeft * pRight - pIntersection) <= EPS;
}
