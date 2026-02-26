#pragma once

#include "source/distributions/RandomVariable.hpp"
#include "source/distributions/continuous_distributions/ContinuousRandomVariableType.h"
#include "source/data_structures/interval/Interval.h"
#include "source/functions/function/Function.hpp"
#include "source/functions/density_function/uniform_density_function/UniformDensityFunction.h"
#include "source/data_structures/vector/Vector.hpp"


template <class T>
class ContinuousRandomVariable: public RandomVariable<Interval> {
protected:
    Vector<T> parameters;
    const Function<double, double>* densityFunction = nullptr;
    ContinuousRandomVariableType type = ContinuousRandomVariableType::None;

    void setType(ContinuousRandomVariableType type);
    void setParameters(const Vector<T>& inputParameters);
    void setDensityFunction();

    void free();
    void moveTo(ContinuousRandomVariable&& other) noexcept;
    void copyFrom(const ContinuousRandomVariable& other);

public:
    ContinuousRandomVariable(const Vector<T>& inputParams, ContinuousRandomVariableType type);
    ContinuousRandomVariable(const ContinuousRandomVariable& other);
    ContinuousRandomVariable(ContinuousRandomVariable&& other) noexcept;
    ContinuousRandomVariable& operator = (const ContinuousRandomVariable& other);
    ContinuousRandomVariable& operator = (ContinuousRandomVariable&& other) noexcept;
    ~ContinuousRandomVariable();

    const Vector<T>& getParameters() const;
    const Function<double, double>* getDensityFunction() const;
};

template <class T>
ContinuousRandomVariable<T>::ContinuousRandomVariable(const Vector<T>& inputParams, ContinuousRandomVariableType type) {
    this->setParameters(inputParams);
    this->setType(type);
    this->setDensityFunction();
}

template <class T>
ContinuousRandomVariable<T>::ContinuousRandomVariable(const ContinuousRandomVariable& other) {
    this->copyFrom(other);
}

template <class T>
ContinuousRandomVariable<T>::ContinuousRandomVariable(ContinuousRandomVariable&& other) noexcept {
    this->moveTo(std::move(other));
}

template <class T>
ContinuousRandomVariable<T>& ContinuousRandomVariable<T>::operator = (const ContinuousRandomVariable& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }

    return *this;
}

template <class T>
ContinuousRandomVariable<T>& ContinuousRandomVariable<T>::operator = (ContinuousRandomVariable&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }

    return *this;
}

template <class T>
ContinuousRandomVariable<T>::~ContinuousRandomVariable() {
    this->free();
}

template <class T>
void ContinuousRandomVariable<T>::free() {
    delete this->densityFunction;
    this->densityFunction = nullptr;
}

template <class T>
void ContinuousRandomVariable<T>::setType(ContinuousRandomVariableType type) {
    if (type == ContinuousRandomVariableType::None) throw std::runtime_error("Type must be different form None");
    this->type = type;
}

template <class T>
void ContinuousRandomVariable<T>::setDensityFunction() {
    switch (this->type) {
    case ContinuousRandomVariableType::Uniform: this->densityFunction = new UniformDensityFunction(this->parameters[0], this->parameters[1]); break;;
    default: throw std::runtime_error("Unsupported ContinuousRandomVariable");
    }
}

template <class T>
void ContinuousRandomVariable<T>::moveTo(ContinuousRandomVariable&& other) noexcept {
    this->densityFunction = other.densityFunction;
    other.densityFunction = nullptr;
}

template <class T>
void ContinuousRandomVariable<T>::copyFrom(const ContinuousRandomVariable& other) {
    this->type = other.type;
        switch (this->type) {
        case ContinuousRandomVariableType::Uniform: 
            this->densityFunction = new UniformDensityFunction(other.ggetParameters()[0], other.getParameters()[1]); 
            break;;
        default: 
            throw std::runtime_error("Unsupported ContinuousRandomVariable");
        }
}

template <class T>
void ContinuousRandomVariable<T>::setParameters(const Vector<T>& inputParameters) {
    if (this->type == ContinuousRandomVariableType::Uniform && (inputParameters.getSize() != 2 || inputParameters[0] > inputParameters[1])) {
        throw std::runtime_error("First parameter must be greater than second one");
    } 
    this->parameters = parameters;
}

template <class T>
const Vector<T>& ContinuousRandomVariable<T>::getParameters() const {
    return this->parameters;
}

template <class T>
const Function<double, double>* ContinuousRandomVariable<T>::getDensityFunction() const {
    return this->densityFunction;
}