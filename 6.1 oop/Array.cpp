#include "Array.h"
#include <iostream>
#include <stdexcept>
#include <exception>

using namespace std;

Array::Array(const Array::size_type& n)
throw(bad_alloc, invalid_argument)
{
	FIRST = 0;
	COUNT = SIZE = n;
	elements = new value_type[SIZE];
	for (UINT i = 0; i < SIZE; i++)
	{
		elements[i] = 0;
	}
}

Array::Array(const iterator first, const iterator last)
throw(bad_alloc, invalid_argument)
{
	FIRST = 0;
	if (first <= last) {
		COUNT = SIZE = (last - first) + 1;
		elements = new value_type[SIZE];
		for (UINT i = 0; i < SIZE; ++i)
			elements[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}

Array::Array(const size_type first, const size_type last)
throw(bad_alloc, invalid_argument)
{
	if (first <= last) {
		FIRST = first;
		COUNT = SIZE = (last - first) + 1;
		elements = new value_type[SIZE];
		for (UINT i = 0; i < SIZE; ++i)
			elements[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}

Array::Array(const Array& t) throw(bad_alloc)
	: SIZE(t.SIZE), COUNT(t.COUNT), FIRST(t.FIRST), elements(new value_type[SIZE])
{
	for (UINT i = 0; i < SIZE; i++)
		elements[i] = t.elements[i];
}

Array& Array::operator = (const Array& x)
{
	Array tmp(x);
	swap(tmp);
	return *this;
}
Array::~Array()
{
	delete[]elements;
	elements = 0;
}

void Array::push_back(const value_type& v)
{
	if (COUNT == SIZE)			//array is full
		resize(SIZE * 2);		//resize array
	elements[COUNT++] = v;		//add element
}

void Array::pop_back()
{
	if (empty())
	{
		throw invalid_argument("!!!");
	}
	--COUNT;
}
Array::reference Array::operator[](size_type index) throw(out_of_range)
{
	if ((FIRST <= index) && (index < FIRST + SIZE))
		return elements[index - FIRST];
	else 
		throw out_of_range("inedx out of range!");
}
Array::const_reference Array::operator [] (size_type index) const throw(out_of_range)
{
	if ((FIRST <= index) && (index < FIRST +SIZE))
		return elements[index - FIRST];
	else
		throw out_of_range("index out of range!");
}

void Array::resize(size_type newsize) throw(bad_alloc)
{
	if (newsize > capacity())
	{
		value_type* data = new value_type[newsize];
		for (UINT i = 0; i < SIZE; i++)
			data[i] = elements[i];
		delete[]elements;
		elements = data;
		SIZE = newsize;
	}
}

void Array::swap(Array& other)
{
	std::swap(elements, other.elements);
	std::swap(SIZE, other.SIZE);
}

Array::size_type Array::capacity() const
{
	return SIZE;
}

Array::size_type Array::size() const
{
	return COUNT;
}

bool Array::empty() const
{
	return COUNT == 0;
}

void Array::assign(const value_type& x)
{
	for (UINT i = 0; i < SIZE; i++)
		elements[i] = x;
}

ostream& operator << (ostream& out, const Array& x)
{
	for (size_t j = 0; j < x.COUNT; j++)
	{
		out << x[j] << "\t  ";
	}
	out << endl;
	return out;
}

istream& operator >> (istream& in, Array& v)
{
	double x;

	for (size_t j = 0; j < v.COUNT; j++)
	{
		cout << "Enter element " << j + 1 << ": ";in >> x;
		v.elements[j] = x;
	}
	return in;
}

void Array::Task()
{
	value_type sumNegative = 0, sumAll = 0, average = 0;
	
	for (size_t i = 0; i <COUNT; i++)
	{
		if (elements[i] < 0)
		{
			sumNegative += elements[i];
		}
	}

	for (size_t i = 0; i < COUNT; i++)
	{
		elements[i] += sumNegative / 2;
	}
	
	for (size_t i = 0; i < COUNT;i++)
	{
		sumAll += elements[i];
	}

	average = sumAll / COUNT;
	
	if (COUNT == SIZE)
	{
		resize(SIZE + 2);
	}
	elements[COUNT++] = sumAll;
	elements[COUNT++] = average;
}