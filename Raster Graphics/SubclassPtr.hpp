#pragma once

template <typename T>
class SubclassPtr
{
public:
	SubclassPtr() = default;
	SubclassPtr(T* ptr);
	SubclassPtr(const SubclassPtr<T>& other);
	SubclassPtr<T>& operator=(const SubclassPtr<T>& other);
	SubclassPtr(SubclassPtr<T>&& other) noexcept;
	SubclassPtr<T>& operator=(SubclassPtr<T>&& other) noexcept;
	~SubclassPtr();

	T& operator*();
	const T& operator*() const;
	T* operator->();
	const T* operator->() const;
private:
	T* ptr = nullptr;

	void free();
	void copyFrom(const SubclassPtr<T>& other);
	void moveFrom(SubclassPtr<T>&& other);
};

template<typename T>
SubclassPtr<T>::SubclassPtr(T* ptr)
{
	this->ptr = ptr;
}

template<typename T>
SubclassPtr<T>::SubclassPtr(const SubclassPtr<T>& other)
{
	copyFrom(other);
}

template<typename T>
SubclassPtr<T>& SubclassPtr<T>::operator=(const SubclassPtr<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
SubclassPtr<T>::SubclassPtr(SubclassPtr<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
SubclassPtr<T>& SubclassPtr<T>::operator=(SubclassPtr<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
SubclassPtr<T>::~SubclassPtr()
{
	free();
}

template<typename T>
T& SubclassPtr<T>::operator*()
{
	return *(this->ptr);
}

template<typename T>
const T& SubclassPtr<T>::operator*() const
{
	return *(this->ptr);
}

template<typename T>
T* SubclassPtr<T>::operator->()
{
	return this->ptr;
}

template<typename T>
const T* SubclassPtr<T>::operator->() const
{
	return this->ptr;
}

template<typename T>
void SubclassPtr<T>::free()
{
	delete this->ptr;
}

template<typename T>
void SubclassPtr<T>::copyFrom(const SubclassPtr<T>& other)
{
	this->ptr = other.ptr->clone();
}

template<typename T>
void SubclassPtr<T>::moveFrom(SubclassPtr<T>&& other)
{
	this->ptr = other.ptr;
	other.ptr = nullptr;
}