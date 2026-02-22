#pragma once

#include <iostream>
#include <cstdint>
#include <stdexcept>
#include <utility>
#include "source/data_structures/combinatorics/k_selection/KSelectionPattern.h"

namespace HelperFunctions {
    uint32_t binomial(uint32_t n, uint32_t k);
    uint32_t permutation(uint32_t n, uint32_t k);
    uint32_t power(uint32_t n, uint32_t k);
    double power(double n, uint32_t k);
}


class KSelection {
private:
    KSelectionPattern buildingPattern = KSelectionPattern::None;
    uint32_t n = 0, k = 0;
    bool orderMatters = false;
    bool allowRepetition = false;

    void applyPattern(KSelectionPattern buildingPattern);
    void validate() const;

    void setN(uint32_t n);
    void setK(uint32_t k);
    void setKSelectionPattern(KSelectionPattern buildingPattern);

public:
    KSelection(KSelectionPattern buildingPattern, uint32_t n, uint32_t k);

    uint32_t generateCount() const;
    uint32_t getN() const;
    uint32_t getK() const;
    bool getOrderMatters() const;
    bool getAllowRepetition() const;
    KSelectionPattern getBuildingPattern() const;
};
