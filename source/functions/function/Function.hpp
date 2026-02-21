#pragma once

#include "../../data_structures/vector/Vector.hpp"

template <class T> using Domain = Vector<T>;
template <class T> using Range = Vector<T>;


template<class T, class U>
class Function {
private:
    Domain<T> domain;
    Range<U> range;

public:
    Function(const Domain<T>& domain, const Range<U>& range);

    virtual U operator () (const T& input) const = 0;
    virtual Function* clone() const = 0;
    virtual ~Function() = default;
};

template <class T, class U>
Function<T, U>::Function(const Domain<T>& domain, const Range<U>& range):
    domain(domain), range(range) {}