#include "String.h"
#pragma warning (disable : 4996)

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

String::String() : String("")
{
}

String::String(const char* data)
{
	this->size = strlen(data);
	this->capacity = closestPowerOfTwo(this->size + 1);
	this->data = new char[this->capacity];
	std::strcpy(this->data, data);
}

String::String(const String& other)
{
	copyFrom(other);
}

String::String(String&& other) noexcept
{
	moveFrom(std::move(other));
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

String& String::operator=(String&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

String::~String()
{
	free();
}

size_t String::getSize() const
{
	return this->size;
}

size_t String::getCapacity() const
{
	return this->capacity;
}

const char* String::c_str() const
{
	return this->data;
}

String& String::operator+=(const String& other)
{
	if (this->size + other.size + 1 > this->capacity)
		resize(closestPowerOfTwo(this->size + other.size + 1));

	strncat(this->data, other.data, other.size);

	this->size = getSize() + other.getSize();
	return *this;
}

char& String::operator[](size_t index)
{
	return this->data[index];
}

const char& String::operator[](size_t index) const
{
	return this->data[index];
}

String String::subStr(size_t begin, size_t howMany) const
{
	if (begin + howMany > getSize())
		throw std::length_error("Error, Substr out of range");

	String result(howMany + 1);
	strncat(result.data, this->data + begin, howMany);
	return result;
}

String::String(size_t capacity)
{
	this->capacity = closestPowerOfTwo(capacity);
	this->data = new char[this->capacity];
	this->size = 0;
	this->data[0] = '\0';
}

void String::resize(unsigned newCapacity)
{
	char* newData = new char[newCapacity];
	std::strcpy(newData, this->data);
	delete[] this->data;
	this->data = newData;
	this->capacity = newCapacity;
}

void String::free()
{
	delete[] this->data;
	this->data = nullptr;
	this->size = 0;
	this->capacity = 0;
}

void String::copyFrom(const String& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->data = new char[this->capacity];
	std::strcpy(this->data, other.data);
}

void String::moveFrom(String&& other)
{
	this->data = other.data;
	this->capacity = other.capacity;
	this->size = other.size;
	other.data = nullptr;
	other.capacity = 0;
	other.size = 0;
}

String operator+(const String& lhs, const String& rhs)
{
	String result(lhs.size + rhs.size + 1);
	result += lhs;
	result += rhs;
	return result;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	os << obj.data;
	return os;
}

std::istream& operator>>(std::istream& is, String& ref)
{
	char buffer[1024];
	is >> buffer;
	ref = String(buffer);
	return is;
}

bool operator==(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) == 0;
}

bool operator!=(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) != 0;
}

bool operator<(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) < 0;
}

bool operator<=(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) <= 0;
}

bool operator>(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) > 0;
}

bool operator>=(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) >= 0;
}
