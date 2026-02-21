#pragma once

class Function {
public:
    virtual double operator()(double x) const = 0;
    virtual Function* clone() const = 0;
    virtual ~Function() = default;
};