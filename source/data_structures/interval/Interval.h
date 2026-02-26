#pragma once

#include <iostream>


class Interval {
private:
    double left = 0;
    double right = 0;

    void setLeftComponent(double left);
    void setRightComponent(double right);

public:
    Interval() = default;
    Interval(double left, double right);
    Interval& operator |= (const Interval& other);
    Interval& operator &= (const Interval& other);

    bool isInInterval(double number) const;
    double getLeftComponent() const;
    double getRightComponent() const;
};

Interval operator | (const Interval& left, const Interval& right);
Interval operator & (const Interval& left, const Interval& right);