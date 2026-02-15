#include <cstring>
#include <iostream>


class String {
private:
    char* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void resize(size_t newCapacity);
    void copyFrom(const String& other);
    void moveTo(String&& other) noexcept;
    void free();

    void setSize(size_t newSize);
    void setCapacity(size_t newCapacity);

public:
    String();
    String(const char* data);
    String(const String& other);
    String(size_t capacity);
    String(String&& other) noexcept;
    String& operator = (const String& other);
    String& operator = (String&& other) noexcept;
    String& operator += (const String& other);
    ~String();

    size_t getSize() const;
    size_t getCapacity() const;
    const char* getData() const;

    char& operator [] (size_t index);
    const char& operator [] (size_t index) const;

    friend std::ostream& operator << (std::ostream& os, const String& str);
    friend std::istream& operator >> (std::istream& is, String& str);
};

String operator + (const String& str1, const String& str2);
