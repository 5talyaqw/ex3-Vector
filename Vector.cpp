#include "Vector.h"
#include <iostream>
// Constructor
Vector::Vector(int n)
{
	if (n < 2)
	{
		n = 2;
	}
	_capacity = n;
	_size = 0;
	_resizeFactor = n;
	_elements = new  int[_capacity];
}

Vector::~Vector()
{
	delete[] _elements;
}

int Vector::size() const
{
	return _size;
}

int Vector::capacity() const
{
	return _capacity;
}

int Vector::resizeFactor() const
{
	return _resizeFactor;
}

bool Vector::empty() const
{
	return _size == 0;
}

void Vector::push_back(const int& val)
{
    if (_size == _capacity)
    {
        int newCap = _capacity + _resizeFactor;

        int* newEle = new int[newCap];

        for (int i = 0; i < newCap; i++)
        {
            newEle[i] = _elements[i];
        }

        delete[] _elements;
		
        _elements = newEle;
        _capacity = newCap;  // Update the capacity to the new capacity
    }
	_elements[_size] = val;
	++_size;
}

int Vector::pop_back()
{
	if (_size == 0)
	{
		std::cout << "empty from pop: error vector" << std::endl;
		return -9999;
	}
	else
	{
		int value = _elements[_size - 1];
		--_size;
		return value;
	}
}

void Vector::reserve(const int n)
{
	if (n > _capacity)
	{
		int newCap = n + 2;  

		int* newEle = new int[newCap];

		for (int i = 0; i < _size; i++)
		{
			newEle[i] = _elements[i];
		}

		delete[] _elements;

		_elements = newEle;
		_capacity = newCap;
	}
}

void Vector::resize(const int n)
{
	int i;
	if (n <= _capacity)
	{
		_size = n;
	}
	else
	{
		reserve(n);
		_size = n;
	}
	for (i = 0; i < _size; ++i)
	{
		_elements[i] = 0;
	}
}

void Vector::assign(const int val)
{
	int i;
	for (i = 0; i < _size; ++i)
	{
		_elements[i] = val;
	}
}

void Vector::resize(const int n, const int& val)
{
	int i;
	if (n <= _size)
	{
		_size = n;
	}
	else
	{
		if (n > _capacity)
		{
			reserve(n); 
		}

		for (i = _size; i < n; ++i)
		{
			_elements[i] = val; 
		}

		_size = n;
	}
}


Vector::Vector(const Vector& other)
{

}

Vector& Vector::operator=(const Vector& other)
{
	// TODO: insert return statement here
}

int& Vector::operator[](int n) const
{
	// TODO: insert return statement here
}

Vector& Vector::operator+=(const Vector& other)
{
	// TODO: insert return statement here
}

Vector& Vector::operator-=(const Vector& other)
{
	// TODO: insert return statement here
}

Vector Vector::operator+(const Vector& other) const
{
	return Vector();
}

Vector Vector::operator-(const Vector& other) const
{
	return Vector();
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	// TODO: insert return statement here
}
