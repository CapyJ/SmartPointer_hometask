#pragma once
#include <iostream>

using namespace std;

template <typename T>
class SmartPtr {

public:

	SmartPtr(T* ptr);
	SmartPtr(const SmartPtr<T>& source);
	SmartPtr(SmartPtr && source);
	~SmartPtr();
	
	SmartPtr& operator=(const SmartPtr& source);
	SmartPtr& operator=(SmartPtr && source);
	T& operator*() const;
	T* operator->() const;

	SmartPtr& Swap(SmartPtr& source);

	int* count = nullptr;

private:

	T* ptr;

};

template <typename T>
class SmartPtr<T[]> {

public:

	SmartPtr(T* ptr);
	SmartPtr(const SmartPtr<T[]>& source);
	~SmartPtr();

	T& operator[](const int index);

	int* count = nullptr;

private:

	T* ptr;

};


template <typename T>
SmartPtr<T>::SmartPtr(T* ptr) : 
	ptr(ptr), count(new int(1))
{

	cout << "Constructor: " << this << endl;

}

template <typename T>
SmartPtr<T[]>::SmartPtr(T* ptr) :
	ptr(ptr), count(new int(1))
{

	cout << "Array Constructor: " << this << endl;

}

template <typename T>
SmartPtr<T>::SmartPtr(const SmartPtr<T>& source) :
	SmartPtr(source.ptr)
{
	count = source.count;
	++(*count);

	cout << "Copy constructor: " << this << endl;

}

template <typename T>
SmartPtr<T[]>::SmartPtr(const SmartPtr<T[]>& source) :
	SmartPtr(source.ptr)
{
	count = source.count;
	++(*count);

	cout << "Array Copy constructor: " << this << endl;

}

template <typename T>
SmartPtr<T>::SmartPtr(SmartPtr && source) :
	ptr(move(source.ptr)),
	count(move(source.count))
{
	source.ptr = nullptr;
	source.count = nullptr;
	cout << "Move constructor: " << this << endl;
}

template <typename T>
SmartPtr<T>::~SmartPtr() {

	if (count != nullptr && --(*count) == 0) {
		delete ptr;
		delete count;
		cout << "Destructor: " << this << endl;

	}

}

template <typename T>
SmartPtr<T[]>::~SmartPtr() {

	if (count != nullptr && --(*count) == 0) {
		delete[] ptr;
		delete count;
		cout << "Array Destructor: " << this << endl;
	}

}

template<typename T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr& source) {

	if (&source != this) {

		this->~SmartPtr();

		ptr = source.ptr;
		count = source.count;

		++(*count);

	}

	return *this;

}

template <typename T>
SmartPtr<T>& SmartPtr<T>::operator=(SmartPtr && source) {

	cout << "Move assignment operator: " << this << endl;

	return SmartPtr(move(source)).Swap(*this);

}

template <typename T>
T& SmartPtr<T>::operator*() const {

	return *this->ptr;

}

template <typename T>
T* SmartPtr<T>::operator->() const {

	return this->ptr;

}

template <typename T>
T& SmartPtr<T[]>::operator[](const int index) {

	return this->ptr[index];

}

template <typename T>
SmartPtr<T>& SmartPtr<T>::Swap(SmartPtr& source) {

	swap(ptr, source.ptr);
	swap(count, source.count);

}


