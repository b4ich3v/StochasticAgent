#pragma once

#include <iostream>


class Interval {
private:
    uint32_t left = 0;
    uint32_t right = 0;

    void setLeftComponent(uint32_t left);
    void setRightComponent(uint32_t right);

public:
    Interval() = default;
    Interval(uint32_t left, uint32_t right);
    Interval& operator |= (const Interval& other);
    Interval& operator &= (const Interval& other);

    bool isInInterval(uint32_t number) const;
    uint32_t getLeftComponent() const;
    uint32_t getRightComponent() const;
};

Interval operator | (const Interval& left, const Interval& right);
Interval operator & (const Interval& left, const Interval& right);