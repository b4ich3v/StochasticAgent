#pragma once


enum class TypeOfRandomVariable {
    NONE = 1 << 0,
    DISCRETE = 1 << 1,
    CONTINUOUS = 1 << 2
};