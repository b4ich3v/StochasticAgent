#pragma once

#include <iostream>


template <class T>
class HeterogeneousContainer {
private:
	T** data = nullptr;
	size_t size = 0;
	size_t capacity = 8;

	void resize(size_t newCapacity);
	void copyFrom(const HeterogeneousContainer& other);
	void moveTo(HeterogeneousContainer&& other);
    void free();

public:
	HeterogeneousContainer();
	HeterogeneousContainer(const HeterogeneousContainer<T>& other);
	HeterogeneousContainer(HeterogeneousContainer&& other) noexcept;
	HeterogeneousContainer& operator = (const HeterogeneousContainer& other);
	HeterogeneousContainer& operator = (HeterogeneousContainer&& other) noexcept;
	~HeterogeneousContainer();

	void addElement(const T& element);
	void addElement(const T* element);
    void addElement(T&& element);
	void removeElement(size_t index);

	size_t getSize() const;
    size_t getCapacity() const;

	T* operator [] (size_t index);
	const T* operator [] (size_t index) const;
};

template <class T>
HeterogeneousContainer<T>::HeterogeneousContainer() {
    this->capacity = 8;
    this->size = 0;
    this->data = new T*[this->capacity] {nullptr};
}

template <class T>
HeterogeneousContainer<T>::HeterogeneousContainer(const HeterogeneousContainer<T>& other) {
    this->copyFrom(other);
}

template <class T>
HeterogeneousContainer<T>::HeterogeneousContainer(HeterogeneousContainer&& other) noexcept {
    this->moveTo(std::move(other));
}

template <class T>
HeterogeneousContainer<T>& HeterogeneousContainer<T>::operator = (const HeterogeneousContainer& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }

    return *this;
}

template <class T>
HeterogeneousContainer<T>& HeterogeneousContainer<T>::operator = (HeterogeneousContainer&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }

    return *this;
}

template <class T>
HeterogeneousContainer<T>::~HeterogeneousContainer() {
    this->free();
}

template <class T>
void HeterogeneousContainer<T>::addElement(const T& element) {
    if (this->size == this->capacity) {
        this->resize(this->size * 2);
    }
    
    this->data[this->size] = new T(element);
    this->size += 1;
}

template <class T>
void HeterogeneousContainer<T>::addElement(T&& element) {
    if (this->size == this->capacity) {
        this->resize(this->size * 2);
    }
    
    this->data[this->size] = new T(std::move(element));
    this->size += 1;
}

template <class T>
void HeterogeneousContainer<T>::addElement(const T* element) {
    if (this->size == this->capacity) {
        this->resize(this->size * 2);
    }
    
    this->data[this->size] = new T(*element);
    this->size += 1;
}

template <class T>
void HeterogeneousContainer<T>::removeElement(size_t index) {
    if (index >= this->size) throw std::out_of_range("Index is out of range");
    delete this->data[index];

    for (size_t i = index; i < this->size - 1; i++) {
        this->data[i] = this->data[i + 1];
    }
    
    data[size - 1] = nullptr;
    this->size -= 1;
}

template <class T>
size_t HeterogeneousContainer<T>::getSize() const {
    return this->size;
}

template <class T>
size_t HeterogeneousContainer<T>::getCapacity() const {
    return this->capacity;
}

template <class T>
void HeterogeneousContainer<T>::resize(size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::logic_error("Newcapacity must be greater than old capacity");
    }

    T** newData = new T*[newCapacity] {nullptr};
    for (size_t i = 0; i < this->size; i++) {
        newData[i] = this->data[i];
        this->data[i] = nullptr;
    }
    
    delete[] this->data;
    this->data = newData;
    this->capacity = newCapacity;
}

template <class T>
void HeterogeneousContainer<T>::copyFrom(const HeterogeneousContainer& other) {
    this->data = new T*[other.capacity] {nullptr};
    this->size = other.size;
    this->capacity = other.capacity;

    for (size_t i = 0; i < this->size; i++) {
        this->data[i] = other.data[i]->clone();
    }
}

template <class T>
void HeterogeneousContainer<T>::moveTo(HeterogeneousContainer&& other) noexcept {
    this->data = other.data;
    this->size = other.size;
    this->capacity = other.capacity;

    other.data = nullptr;
    other.size= 0;
    other.capacity = 0;
}

template <class T>
void HeterogeneousContainer<T>::free() {
    for (size_t i = 0; i < this->size; i++) {
        delete this->data[i];
        this->data[i] = nullptr;
    }

    delete[] this->data;
    this->data = nullptr;
    this->size = 0;
    this->capacity = 0;
}

template <class T>
T* HeterogeneousContainer<T>::operator [] (size_t index) {
    if (index >= this->size) throw std::out_of_range("Index is out of range");
    return this->data[index];
}

template <class T>
const T* HeterogeneousContainer<T>::operator [] (size_t index) const {
    if (index >= this->size) throw std::out_of_range("Index is out of range");
    return this->data[index];
}