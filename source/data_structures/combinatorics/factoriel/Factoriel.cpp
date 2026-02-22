#include "source/data_structures/combinatorics/factoriel/Factoriel.h"

size_t Factoriel::operator () (size_t number) const {
    if (number == 1 || number == 0) return 1;
    return this->operator()(number - 1);
}