#include "Event.h"

bool operator == (const Event& left, const Event& right) {
    const auto& leftElements = left.getElementaryEvents();
    const auto& rightElements = right.getElementaryEvents();

    if (leftElements.getSize() != rightElements.getSize()) return false;
    const auto& rightIds = right.getIdSet();

    for (size_t i = 0; i < leftElements.getSize(); i++) {
        if (!rightIds.hasNumber(leftElements[i].getEventId())) return false;
    }
    return true;
}

bool operator != (const Event& left, const Event& right) {
    return !(left == right);
}