#pragma once
#include <iostream>

template<typename T>
class Vector
{
public:
    void pushBack(const T& element);
    void pushBack(T&& element);
    void popBack();

    size_t getSize() const;
    bool contains(const T& element) const;
    bool isEmpty() const;

    const T& getAtIndex(size_t index) const;
    T& getAtIndex(size_t index);
    const T& operator[](size_t index) const;
    T& operator[](size_t index);

    Vector();
    Vector(size_t capacity);
    Vector(const Vector& other);
    Vector<T>& operator=(const Vector<T>& other);
    Vector(Vector&& other) noexcept;
    Vector<T>& operator=(Vector<T>&& other) noexcept;
    ~Vector();
private:
    T* data = nullptr;
    size_t capacity = 0;
    size_t size = 0;
    void resize(size_t newCapacity);

    void free();
    void copyFrom(const Vector<T>& other);
    void moveFrom(Vector<T>&& other);
};

static size_t closestPowerOfTwo(size_t n)
{
    n--;

    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;

    return n + 1;
};

template<typename T>
void Vector<T>::pushBack(const T& element)
{
    if (this->size >= this->capacity)
        resize(this->capacity * 2);

    this->data[this->size++] = element;
}

template<typename T>
void Vector<T>::pushBack(T&& element)
{
    if (this->size >= this->capacity)
        resize(this->capacity * 2);

    this->data[this->size++] = std::move(element);
}

template<typename T>
void Vector<T>::popBack()
{
    if (size)
        size--;
    else
        throw std::length_error("Already empty!");

    if (size * 4 <= capacity && capacity > 1)
        resize(capacity / 2);
}

template<typename T>
size_t Vector<T>::getSize() const
{
    return this->size;
}

template<typename T>
bool Vector<T>::contains(const T& element) const
{
    for (size_t i = 0; i < this->size; i++)
    {
        if (this->data[i] == element)
            return true;
    }
    return false;
}

template<typename T>
bool Vector<T>::isEmpty() const
{
    return this->size == 0;
}

template<typename T>
const T& Vector<T>::getAtIndex(size_t index) const
{
    if (index >= this->size)
        throw std::out_of_range("Index out of range!");
    return this->data[index];
}

template<typename T>
T& Vector<T>::getAtIndex(size_t index)
{
    if (index >= this->size)
        throw std::out_of_range("Index out of range!");
    return this->data[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const
{
    return this->data[index];
}

template<typename T>
T& Vector<T>::operator[](size_t index)
{
    return this->data[index];
}

template<typename T>
Vector<T>::Vector() : Vector(8)
{
}

template<typename T>
Vector<T>::Vector(size_t capacity)
{
    this->size = 0;
    this->capacity = closestPowerOfTwo(capacity);
    this->data = new T[this->capacity];
}

template<typename T>
Vector<T>::Vector(const Vector& other)
{
    copyFrom(other);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);

    }
    return *this;
}

template<typename T>
Vector<T>::Vector(Vector&& other) noexcept
{
    moveFrom(std::move(other));
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

template<typename T>
Vector<T>::~Vector()
{
    free();
}

template<typename T>
void Vector<T>::resize(size_t newCapacity)
{
    T* temp = this->data;
    this->data = new T[newCapacity];

    for (size_t i = 0; i < this->size; i++)
        this->data[i] = temp[i];

    this->capacity = newCapacity;
    delete[] temp;
}

template<typename T>
void Vector<T>::free()
{
    delete[] this->data;
}

template<typename T>
void Vector<T>::copyFrom(const Vector& other)
{
    this->data = new T[other.capacity];
    for (size_t i = 0; i < other.size; i++)
        this->data[i] = other.data[i];
    this->capacity = other.capacity;
    this->size = other.size;
}

template<typename T>
void Vector<T>::moveFrom(Vector&& other)
{
    this->data = other.data;
    this->capacity = other.capacity;
    this->size = other.size;
    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
}
