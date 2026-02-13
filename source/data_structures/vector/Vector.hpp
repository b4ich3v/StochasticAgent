#include <iostream>


template <class T>
class Vector {
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void resize(size_t newCapacity);
    void copyFrom(const Vector& other);
    void moveTo(Vector&& other) noexcept;
    void free();

    void setSize(size_t newSize);
    void setCapacity(size_t newCapacity);

public:
    Vector();
    Vector(const Vector& other);
    Vector(size_t capacity);
    Vector(Vector&& other) noexcept;
    Vector& operator = (const Vector& other);
    Vector& operator = (Vector&& other) noexcept;
    ~Vector();

    void push(const T& element);
    void push(T&& element);
    void pop();

    size_t getSize() const;
    size_t getCapacity() const;

    T& operator [] (size_t index);
    const T& operator [] (size_t index) const;

    template <class U>
    friend std::ostream& operator << (std::ostream& os, const Vector<U>& vector);

    template <class U>
    friend std::istream& operator >> (std::istream& is, Vector<U>& vector);
};


template<class T>
Vector<T>::Vector() {
    this->setCapacity(8);
    this->setSize(0);
    this->data = new T[this->capacity] {};
}

template<class T>
Vector<T>::Vector(const Vector &other) {
    copyFrom(other);
}

template<class T>
Vector<T>::Vector(size_t capacity) {
    this->setCapacity(capacity);
    this->setSize(0);
    this->data = new T[this->getCapacity()] {};
}

template<class T>
Vector<T>::Vector(Vector &&other) noexcept {
    moveTo(std::move(other));
}

template<class T>
Vector<T> &Vector<T>::operator=(const Vector &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

template<class T>
Vector<T> &Vector<T>::operator=(Vector &&other) noexcept {
    if (this != &other) {
        free();
        moveTo(std::move(other));
    }
    return *this;
}

template <class T>
Vector<T>::~Vector() {
    free();
}

template<class T>
void Vector<T>::resize(size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::runtime_error("NewCapacity must be greater");
    }

    T* newData = new T[newCapacity] {};
    this->setCapacity(newCapacity);

    for (int i = 0; i < this->size; i++) {
        newData[i] = this->data[i];
    }
}

template<class T>
void Vector<T>::copyFrom(const Vector &other) {
    this->data = new T[other.getCapacity()] {};
    this->setSize(other.getSize());
    this->setCapacity(other.getCapacity());

    for (int i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
    }
}

template<class T>
void Vector<T>::moveTo(Vector &&other) noexcept {
    this->data = other.data;
    this->setSize(other.getSize());
    this->setCapacity(other.getCapacity());

    other.data = nullptr;
    other.setCapacity(0);
    other.setSize(0);
}

template<class T>
void Vector<T>::free() {
    delete[] this->data;
    this->data = nullptr;
    this->setSize(0);
    this->setCapacity(0);
}

template<class T>
void Vector<T>::setSize(size_t newSize) {
    this->size = newSize;
}

template<class T>
void Vector<T>::setCapacity(size_t newCapacity) {
    this->capacity = newCapacity;
}

template<class T>
void Vector<T>::push(const T &element) {
    if (this->getSize() == this->getCapacity()) {
        this->resize(getCapacity() * 2);
    }
    this->data[this->getSize()] = element;
    this->setSize(this->getSize() + 1);
}

template<class T>
void Vector<T>::push(T &&element) {
    if (this->getSize() == this->getCapacity()) {
        this->resize(getCapacity() * 2);
    }
    this->data[this->getSize()] = std::move(element);
    this->setSize(this->getSize() + 1);
}

template<class T>
void Vector<T>::pop() {
    if (this->getSize() == 0) {
        throw std::logic_error("Thera are not any elements in the vector");
    }
    this->setSize(this->getSize() - 1);
}

template<class T>
size_t Vector<T>::getCapacity() const {
    return this->capacity;
}

template<class T>
size_t Vector<T>::getSize() const {
    return this->size;
}

template<class T>
T &Vector<T>::operator[](size_t index) {
    if (index > this->getSize()) {
        throw std::logic_error("Out of range");
    }
    return this->data[index];
}

template<class T>
const T &Vector<T>::operator[](size_t index) const {
    if (index > this->getSize()) {
        throw std::logic_error("Out of range");
    }
    return this->data[index];
}

template <class T>
std::ostream& operator << (std::ostream& os, const Vector<T>& vector) {
    size_t sizeOfVector = vector.getSize();

    for (int i = 0; i < (int)sizeOfVector; ++i) {
        os << vector[i];
        if (i != sizeOfVector - 1) os << " ";
    }

    return os;
}

template <class T>
std::istream& operator >> (std::istream& is, Vector<T>& vector) {
    size_t sizeOfVector = 0;
    size_t capacityOfVector = 0;
    is >> sizeOfVector;
    capacityOfVector = sizeOfVector * 2;

    vector.free();
    vector.data = new T[capacityOfVector] {};
    vector.setSize(sizeOfVector);
    vector.setCapacity(capacityOfVector);
    for (int i = 0; i < sizeOfVector; i++) {
        is >> vector.data[i];
    }

    return is;
}
