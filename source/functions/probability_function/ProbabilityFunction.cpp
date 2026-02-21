#include <stdexcept>
#include "source/functions/probability_function/ProbabilityFunction.h"

Range<double> probabilityRange() {
    Range<double> result;
    result.push_back(0.0);
    result.push_back(1.0);
    return result;
}

ProbabilityFunction::ProbabilityFunction(const SigmaAlgebra* sigmaAlgebra, ProbabilityFunctionFilter filter)
    : Function<Event, double>(sigmaAlgebra ? sigmaAlgebra->getContainerOfEvents() : Domain<Event>(), probabilityRange()) {
    setSigmaAlgebraPointer(sigmaAlgebra);
    fillProbabilities(filter);
}

const SigmaAlgebra* ProbabilityFunction::getSigmaAlgebraPointer() const {
    return this->sigmaAlgebra;
}

const Vector<Pair<Event, double>>& ProbabilityFunction::getProbabilities() const {
    return this->probabilities;
}

double ProbabilityFunction::operator () (const Event& input) const {
    for (size_t i = 0; i < probabilities.getSize(); i++) {
        if (probabilities[i].getFirstComponent() == input) {
            return probabilities[i].getSecondComponent();
        }
    }
    throw std::logic_error("Event is not part of the sigma-algebra domain");
}

Function<Event, double>* ProbabilityFunction::clone() const {
    return new ProbabilityFunction(*this);
}

void ProbabilityFunction::setSigmaAlgebraPointer(const SigmaAlgebra* sigmaAlgebra) {
    if (sigmaAlgebra == nullptr) {
        throw std::logic_error("SigmaAlgebra pointer is null");
    }
    this->sigmaAlgebra = sigmaAlgebra;
}

void ProbabilityFunction::fillProbabilities(ProbabilityFunctionFilter filter) {
    if (filter == nullptr) {
        throw std::logic_error("ProbabilityFunctionFilter is nullptr");
    }

    const Vector<Event>& events = sigmaAlgebra->getContainerOfEvents();
    for (size_t i = 0; i < events.getSize(); i++) {
        double value = filter(events[i]);
        if (value < 0.0 || value > 1.0) {
            throw std::logic_error("Filter returned probability outside [0, 1]");
        }
        probabilities.push_back(Pair<Event, double>(events[i], value));
    }
}
