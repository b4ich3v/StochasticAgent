#include "source/data_structures/combinatorics/k_selection/KSelection.h"
#include "source/data_structures/combinatorics/factoriel/Factoriel.h"

KSelection::KSelection(KSelectionPattern buildingPattern, uint32_t n, uint32_t k) {
    this->setN(n);
    this->setK(k);
    this->applyPattern(buildingPattern);
    this->validate();
}

void KSelection::applyPattern(KSelectionPattern buildingPattern) {
    this->setKSelectionPattern(buildingPattern);
    switch (buildingPattern) {
        case KSelectionPattern::Combination: orderMatters = false; allowRepetition = false; break;
        case KSelectionPattern::CombinationWithRepetition: orderMatters = false; allowRepetition = true; break;
        case KSelectionPattern::Variation: orderMatters = true;  allowRepetition = false; break;
        case KSelectionPattern::VariationWithRepetition: orderMatters = true;  allowRepetition = true; break;
        case KSelectionPattern::Permutation: orderMatters = true;  allowRepetition = false; k = n; break;
        default: throw std::invalid_argument("Unsupported KSelectionPattern");
    }
}

uint32_t KSelection::generateCount() const {
    this->validate();
    switch (this->buildingPattern) {
        case KSelectionPattern::Combination: return binomial(this->n, this->k);
        case KSelectionPattern::CombinationWithRepetition: return binomial(this->n + this->k - 1, this->k);
        case KSelectionPattern::Variation: return permutation(this->n, this->k);
        case KSelectionPattern::VariationWithRepetition: return power(this->n, this->k);
        case KSelectionPattern::Permutation: return permutation(this->n, this->n);
        default: throw std::logic_error("Unsupported pattern");
    }
}

void KSelection::validate() const {
    if (!allowRepetition && k > n) throw std::invalid_argument("k > n is not valid");
}

void KSelection::setN(uint32_t n) {
    this->n = n;
}

void KSelection::setK(uint32_t k) {
    this->k = k;
}

void KSelection::setKSelectionPattern(KSelectionPattern buildingPattern) {
    this->buildingPattern = buildingPattern;
}

uint32_t KSelection::getN() const {
    return this->n;
}

uint32_t KSelection::getK() const {
    return this->k;
}

bool KSelection::getOrderMatters() const {
    return this->orderMatters;
}

bool KSelection::getAllowRepetition() const {
    return this->allowRepetition;
}

KSelectionPattern KSelection::getBuildingPattern() const {
    return this->buildingPattern;
}

uint32_t KSelection::binomial(uint32_t n, uint32_t k) {
    return (uint32_t)(Factoriel()(n) / (Factoriel()(n - k) * Factoriel()(k)));
}

uint32_t KSelection::permutation(uint32_t n, uint32_t k) {
    return (uint32_t)(Factoriel()(n) / Factoriel()(n - k));
}

uint32_t KSelection::power(uint32_t n, uint32_t k) {
    uint32_t result = 1;
    for (uint32_t i = 0; i < k; i++) {
        result *= n;
    }
    return result;
}
