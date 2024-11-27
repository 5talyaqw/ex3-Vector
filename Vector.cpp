#include "Vector.h"
#include <iostream>

/*
* function initializes a vector with a specified initial capacity. 
* input: n - capacity
* output:none
*/
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
/*
* function freeing the allocated memory
* input: none
* output:none
*/
Vector::~Vector()
{
	delete[] _elements;
}

/*
* function returning the size
* input: none
* output: size variable
*/
int Vector::size() const
{
	return _size;
}

/*
* function returning the capacity
* input: none
* output:capacity variable
*/
int Vector::capacity() const
{
	return _capacity;
}

/*
* function returning the resize factor
* input: none
* output: _resizeFactor variable
*/
int Vector::resizeFactor() const
{
	return _resizeFactor;
}

/*
* function checking if elements is empty
* input: none
* output: true or false
*/
bool Vector::empty() const
{
	return _size == 0;
}

/*
* function to add an element at the end of the vector.
* input: val - value to be added to the vector
* output: none (the element is added to the vector)
*/
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
/*
* function to remove and return the last element of the vector.
* input: none
* output: the last element of the vector, or -1 if the vector is empty
*/
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
/*
 * Function to reserve memory for the vector if the requested size n is greater than the current capacity.
 * Input:
 * - n (int): The new desired capacity of the vector.
 * Output: None.
 */
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
/*
* Function to resize the vector.
* input:n- (int): The new size of the vector.
* output: none
*/
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
/*
 * Function to assign a value to all elements in the vector.
 * Input:
 * - val (const int): The value to assign to all elements.
 * Output: None.
 */
void Vector::assign(const int val)
{
	int i;
	for (i = 0; i < _size; ++i)
	{
		_elements[i] = val;
	}
}

/*
* Function to resize the vector and to put new value in it.
* input:n- (int): The new size of the vector.
* val - (const int&): The value to assign to any newly added elements.
* output: none
*/
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

/*
* function is copy Constructor
* input: other (const Vector&): The vector to copy from.
* output: none
*/
Vector::Vector(const Vector& other)
{
	*this = other;
}

/*
* function copies the values from another vector into this vector.
* input:- other (const Vector&): The vector to copy from. 
* output:  Vector&: A reference to this vector.
*/
Vector& Vector::operator=(const Vector& other)
{
	delete[] _elements;
	this->_capacity = other._capacity;
	this->_resizeFactor = other._resizeFactor;
	this->_size = other._size;
	this->_elements = new int[_capacity + _resizeFactor];
	for (int i = 0; i < _size; i++)
	{
		this->_elements[i] = other._elements[i];
	}
	return *this;
}

int& Vector::operator[](int n) const
{
	if (n < 0 || n >= _size)
	{
		std::cerr << "Index out of bounds. returning the first element." << std::endl;
		return _elements[0];
	}
	return _elements[n];
}

