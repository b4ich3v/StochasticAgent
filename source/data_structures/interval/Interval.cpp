#include "Interval.h"
#include <algorithm>

Interval::Interval(uint32_t left, uint32_t right) {
    if (left > right) throw std::runtime_error("Right component must be greater than left one");
    this->setLeftComponent(left);
    this->setRightComponent(right);
}

Interval& Interval::operator |= (const Interval& other) {
    this->setLeftComponent(std::min(this->left, other.getLeftComponent()));
    this->setRightComponent(std::max(this->left, other.getRightComponent()));
    return *this;
}

Interval& Interval::operator &= (const Interval& other) {
    this->setLeftComponent(std::max(this->left, other.getLeftComponent()));
    this->setRightComponent(std::min(this->right, other.getRightComponent()));
    return *this;
}

bool Interval::isInInterval(uint32_t number) const {
    return number >= this->left && number <= this->right;
}

uint32_t Interval::getLeftComponent() const {
    return this->left;
}

uint32_t Interval::getRightComponent() const {
    return this->right;
}

Interval operator & (const Interval& left, const Interval& right) {
    Interval result = left;
    result &= right;
    return result;
}

Interval operator | (const Interval& left, const Interval& right) {
    Interval result = left;
    result |= right;
    return result;
}

void Interval::setLeftComponent(uint32_t left) {
    this->left = left;
}

void Interval::setRightComponent(uint32_t right) {
    this->right = right;
}