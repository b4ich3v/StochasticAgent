#pragma once

enum class KSelectionPattern {
    None,
    Combination, CombinationWithRepetition,
    Variation, VariationWithRepetition,
    Permutation, PermutationWithRepetition,
    CircularPermutation, CombinationFromMultiset, PermutationFromMultiset, Derangement
};