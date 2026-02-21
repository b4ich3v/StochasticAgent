#pragma once

#include <iostream>


template <class T, class U>
class Pair {
private:
    T first {};
    U second {};

    void setFirstComponent(const T& first);
    void setSecondComponent(const U& second);

public:
    Pair() = default;
    Pair(const T& first, const U& second);

    const T& getFirstComponent() const;
    const U& getSecondComponent() const;
    bool operator == (const Pair<T, U>& other) const;
    bool operator >= (const Pair<T, U>& other) const;
    bool operator <= (const Pair<T, U>& other) const;

    template <class V, class M>
    friend std::istream& operator >> (std::istream& is, Pair<V, M>& pair);

    template <class V, class M>
    friend std::ostream& operator << (std::ostream& os, const Pair<V, M>& pair);
};

template <class T, class U>
bool operator != (const Pair<T, U>& first, const Pair<T, U>& second) {
    return !(first == second);
}

template <class T, class U>
bool operator > (const Pair<T, U>& first, const Pair<T, U>& second) {
    return !(first <= second);
}

template <class T, class U>
bool operator < (const Pair<T, U>& first, const Pair<T, U>& second) {
    return !(first >= second);
}

template <class T, class U>
bool Pair<T, U>::operator == (const Pair<T, U>& other) const {
    return first == other.first && second == other.second;
}

template <class T, class U>
bool Pair<T, U>::operator <= (const Pair<T, U>& other) const {
    if (first < other.first) return true;
    if (other.first < first) return false;
    return (second < other.second) || (second == other.second);
}

template <class T, class U>
bool Pair<T, U>::operator >= (const Pair<T, U>& other) const {
    return other <= *this;
}

template <class T, class U>
Pair<T, U>::Pair(const T& first, const U& second) {
    this->setFirstComponent(first);
    this->setSecondComponent(second);
}

template <class T, class U>
void Pair<T, U>::setFirstComponent(const T& first) {
    this->first = first;
}

template <class T, class U>
void Pair<T, U>::setSecondComponent(const U& second) {
    this->second = second;
}

template <class T, class U>
const T& Pair<T, U>::getFirstComponent() const {
    return this->first;
}

template <class T, class U>
const U& Pair<T, U>::getSecondComponent() const {
    return this->second;
}

template <class T, class U>
std::ostream& operator << (std::ostream& os, const Pair<T, U>& pair) {
    os << "{ " <<  pair.getFirstComponent() << ", " << pair.getSecondComponent() << " }";
    return os;
}

template <class T, class U>
std::istream& operator >> (std::istream& is, Pair<T, U>& pair) {
    T first;
    U second;
    is >> first >> second;
    pair = Pair<T, U>(first, second);
    return is;
}