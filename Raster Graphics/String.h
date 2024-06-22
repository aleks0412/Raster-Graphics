#pragma once
#include <iostream>

class String 
{
public:
    String();
    String(const char* data);
    String(const String& other);
    String(String&& other) noexcept;
    String& operator=(const String& other); 
    String& operator=(String&& other) noexcept;
    ~String();

    size_t getSize() const;
    size_t getCapacity() const;

    const char* c_str() const;

    String& operator+=(const String& other);
    friend String operator+(const String& lhs, const String& rhs);

    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    friend std::ostream& operator<<(std::ostream& os, const String& obj);
    friend std::istream& operator>>(std::istream& is, String& ref);

    friend bool operator==(const String& lhs, const String& rhs);
    friend bool operator!=(const String& lhs, const String& rhs);
    friend bool operator<(const String& lhs, const String& rhs);
    friend bool operator<=(const String& lhs, const String& rhs);
    friend bool operator>(const String& lhs, const String& rhs);
    friend bool operator>=(const String& lhs, const String& rhs);

    String subStr(size_t begin, size_t howMany) const;

private:
    explicit String(size_t capacity);
    void resize(unsigned newAllocatedDataSize);

    void free();
    void copyFrom(const String& other);

    void moveFrom(String&& other);

    char* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
};