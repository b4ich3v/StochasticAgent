#include "String.h"

String::String() {
    this->setSize(0);
    this->setCapacity(8);
    this->data = new char[this->getCapacity()] {};
}

String::String(const String& other) {
    copyFrom(other);
}

String::String(String&& other) noexcept {
    moveTo(std::move(other));
}

String::String(const char* data) {
    if (!data) {
        throw std::logic_error("Nullptr detected");
    }

    this->setSize(strlen(data));
    this->setCapacity(this->getCapacity() * 2);
    this->data = new char[this->getSize() + 1];
    strncpy(this->data, data, strlen(data));
}

String::String(size_t capacity) {
    this->setSize(0);
    this->setCapacity(capacity);
    this->data = new char[this->getCapacity()];
}

String& String::operator=(const String& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        free();
        moveTo(std::move(other));
    }
    return *this;
}

String& String::operator+=(const String& other) {
    size_t overallSize = this->getSize() + other.getSize() + 1;
    if (this->getCapacity() < overallSize) {
        this->resize(overallSize * 2);
    }

    strncat(this->data, other.getData(), other.getSize());
    return *this;
}

String& String::operator+=(String&& other) noexcept {
    size_t overallSize = this->getSize() + other.getSize() + 1;
    if (this->getCapacity() < overallSize) {
        this->resize(overallSize * 2);
    }

    strncat(this->data, other.getData(), other.getSize());
    this->data[this->getSize()] = '\0';
    return *this;
}

String::~String() {
    free();
}

void String::resize(size_t newCapacity) {
    if (newCapacity <= this->getCapacity()) {
        throw std::logic_error("NewCapacity must be greater");
    }

    char* newData = new char[newCapacity] {};
    this->setCapacity(newCapacity);
    strncpy(newData, data, this->getSize());
    newData[this->getSize()] = '\0';

    delete[] this->data;
    this->data = newData;
}

void String::copyFrom(const String& other) {
    this->data = new char[other.getCapacity()] {};
    this->setSize(other.getSize());
    this->setCapacity(other.getCapacity());

    strncpy(this->data, other.data, other.getSize());
    this->data[this->getSize()] = '\0';
}

void String::moveTo(String&& other) noexcept {
    this->data = other.data;
    this->setCapacity(other.getCapacity());
    this->setSize(other.getSize());

    other.data = nullptr;
    other.setSize(0);
    other.setCapacity(0);
}

void String::free() {
    delete[] this->data;
    this->data = nullptr;
    this->setSize(0);
    this->setCapacity(0);
}

void String::setSize(size_t newSize) {
    this->size = newSize;
}

void String::setCapacity(size_t newCapacity) {
    this->capacity = newCapacity;
}

size_t String::getCapacity() const {
    return this->capacity;
}

size_t String::getSize() const {
    return this->size;
}

const char* String::getData() const {
    return this->data;
}

char& String::operator[](size_t index) {
    if (index >= this->getSize()) {
        throw std::out_of_range("Index is out of range");
    }
    return this->data[index];
}

const char& String::operator[](size_t index) const {
    if (index >= this->getSize()) {
        throw std::out_of_range("Index is out of range");
    }
    return this->data[index];
}

std::ostream& operator << (std::ostream& os, const String& str) {
    os << str.getData();
    return os;
}

std::istream& operator >> (std::istream& is, String& str) {
    char buffer[1024] {};
    is.read((char*)buffer, sizeof(buffer));


    return is;
}
