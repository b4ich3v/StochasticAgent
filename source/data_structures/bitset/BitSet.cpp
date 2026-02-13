#include "BitSet.h"

BitSet::BitSet() {
    this->setCountOfBuckets(8);
    this->data = new uint8_t[this->getCountOfBuckets()];
    for (size_t i = 0; i < this->getCountOfBuckets(); i++) this->data[i] = 0;
    this->setMaxTolerance(-1);
}

BitSet::BitSet(BitSet&& other) noexcept {
    moveTo(std::move(other));
}

BitSet::BitSet(const BitSet& other) {
    copyFrom(other);
}

BitSet::BitSet(size_t maxNumber) {
    this->setCountOfBuckets(this->getBucketIndex(maxNumber));
    this->setMaxTolerance(maxNumber);
    this->data = new uint8_t[this->getBucketIndex(maxNumber) + 1];
    for (size_t i = 0; i < this->getCountOfBuckets(); i++) this->data[i] = 0;
}

BitSet& BitSet::operator = (const BitSet& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

BitSet& BitSet::operator = (BitSet&& other) noexcept {
    if (this != &other) {
        free();
        moveTo(std::move(other));
    }
    return *this;
}

BitSet::~BitSet() {
    free();
}

void BitSet::free() {
    delete[] this->data;
    this->data = nullptr;
    this->setMaxTolerance(-1);
    this->setCountOfBuckets(0);
}

void BitSet::resize(size_t newCountOfBuckets) {
    if (newCountOfBuckets < this->getCountOfBuckets()) {
        throw std::logic_error("New count of buckets must be greater");
    }

    uint8_t* newData = new uint8_t[newCountOfBuckets] {};

    for (size_t i = 0; i < this->getCountOfBuckets(); i++) {
        newData[i] = this->data[i];
    }

    this->setCountOfBuckets(newCountOfBuckets);
    delete[] this->data;
    this->data = newData;
}

void BitSet::copyFrom(const BitSet& other) {
    this->data = new uint8_t[other.getCountOfBuckets()];
    this->setCountOfBuckets(other.getCountOfBuckets());
    this->setMaxTolerance(other.getTolerance());

    for (size_t i = 0; i < this->getCountOfBuckets(); i++) {
        this->data[i] = other.data[i];
    }
}

void BitSet::moveTo(BitSet&& other) noexcept {
    this->data = other.data;
    this->setCountOfBuckets(other.getCountOfBuckets());
    this->setMaxTolerance(other.getTolerance());

    other.data = nullptr;
    other.setCountOfBuckets(0);
    other.setMaxTolerance(-1);
}

size_t BitSet::getBucketIndex(int32_t number) const {
    return number / 8;
}

size_t BitSet::getIndexInCurrentBucket(int32_t number) const {
    return number % 8;
}

void BitSet::setCountOfBuckets(size_t countOfBuckets) {
    this->countOfBuckets = countOfBuckets;
}

size_t BitSet::getCountOfBuckets() const {
    return this->countOfBuckets;
}

void BitSet::setMaxTolerance(int32_t maxTolerance) {
    this->maxTolerance = maxTolerance;
}

bool BitSet::isOverTolerance(int32_t number) const {
    return number > this->getTolerance();
}

void BitSet::addNumber(int32_t number) {
    if ((this->getTolerance() != -1 && this->getTolerance() < number) || number < 0)  {
        throw std::logic_error("The number is over the tolerance or it is negative");
    } else if (this->getTolerance() == -1 && this->getBucketIndex(number) >= this->getCountOfBuckets()) {
        this->resize(this->getBucketIndex(number) + 1);
    }

    if (this->hasNumber(number)) return;
    size_t indexInBucket = this->getIndexInCurrentBucket(number);
    size_t bucketIndex = this->getBucketIndex(number);
    this->data[bucketIndex] |= (1 << indexInBucket);
}

void BitSet::removeNumber(int32_t number) {
    if (!this->hasNumber(number)) return;
    size_t indexInBucket = this->getIndexInCurrentBucket(number);
    size_t bucketIndex = this->getBucketIndex(number);
    this->data[bucketIndex] &= (~(1 << indexInBucket));
}

BitSet& BitSet::operator &= (const BitSet& other) {
    BitSet result;
    size_t countOfBucketsOther = other.getCountOfBuckets();

    for (size_t i = 0; i < std::min(countOfBucketsOther, this->getCountOfBuckets()) * 8; i++) {
        if (this->hasNumber((int32_t)i) && other.hasNumber((int32_t)i)) {
            result.addNumber((int32_t)i);
        }
    }

    *this = result;
    return *this;
}

BitSet& BitSet::operator |= (const BitSet& other) {
    BitSet result = *this;

    for (size_t i = 0; i < other.getCountOfBuckets() * 8; i++) {
        if (other.hasNumber((int32_t)i)) {
            result.addNumber((int32_t)i);
        }
    }

    *this = result;
    return *this;
}

BitSet& BitSet::operator %= (const BitSet& other) {
    BitSet result;

    for (size_t i = 0; i < this->getCountOfBuckets() * 8; i++) {
        if (this->hasNumber((int32_t)i) && !other.hasNumber((int32_t)i)) {
            result.addNumber((int32_t)i);
        }
    }

    *this = result;
    return *this;
}

std::ostream& operator << (std::ostream& os, const BitSet& bitSet) {
    os << "{ ";

    for (size_t i = 0; i < bitSet.getCountOfBuckets() * 8; i++) {
        if (bitSet.hasNumber((int32_t)i)) {
            os << i << " ";
        }
    }

    os << "}";
    return os;
}

std::istream& operator >> (std::istream& is, BitSet& bitSet) {
    size_t countOfNumbers = 0;
    int32_t currentNumber = 0;
    BitSet result;
    is >> countOfNumbers;

    for (size_t i = 0; i < countOfNumbers; i++) {
        is >> currentNumber;
        result.addNumber(currentNumber);
    }

    bitSet = result;
    return is;
}

int32_t BitSet::getTolerance() const {
    return this->maxTolerance;
}

bool BitSet::hasNumber(int32_t number) const {
    if (number < 0) {
        throw std::logic_error("Negative number");
    } else if (this->getBucketIndex(number) + 1 > this->getCountOfBuckets()) {
        return false;
    }

    size_t indexInBucket = this->getIndexInCurrentBucket(number);
    size_t bucketIndex = this->getBucketIndex(number);
    return (this->data[bucketIndex] & (1 << indexInBucket)) != 0;
}

BitSet operator & (const BitSet& bitSet1, const BitSet& bitSet2) {
    BitSet result = bitSet1;
    result &= bitSet2;
    return result;
}

BitSet operator | (const BitSet& bitSet1, const BitSet& bitSet2) {
    BitSet result = bitSet1;
    result |= bitSet2;
    return result;
}
