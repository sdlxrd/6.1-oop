#pragma once
#include <iostream>

using namespace std;

class Array
{
public:
	typedef unsigned int UINT;
	typedef double value_type;
	typedef double* iterator;
	typedef const double* const_iterator;
	typedef double& reference;
	typedef const double& const_reference;
	typedef size_t size_type;
	
private:
	static  const size_type minsize = 10;	 // minimal size of array
	size_type SIZE;						     //	size of array
	size_type COUNT;			    		 // count of elements in array
	size_type FIRST;				    	 // index of first element in array			
	value_type* elements;					 // pointer to array of elements
	
public:
	// constructors, copy, destructor
	Array(const size_type& n = minsize)
		throw(bad_alloc, invalid_argument);
	
	Array(const Array&) throw(bad_alloc);
	
	Array(const iterator first, const iterator last) 
		throw(bad_alloc, invalid_argument);
	Array(const size_type first, const size_type last)
		throw(bad_alloc, invalid_argument);
	~Array();
	Array& operator =(const Array&);

	//iterators
	iterator begin() { return elements; }
	const_iterator begin() const { return elements; }
	iterator end() { return elements + COUNT; }
	const_iterator end() const { return elements + COUNT; }

	//sizes
	size_type size() const;				//actual size
	bool empty() const; 			    //is array full
	size_type capacity() const;			//maximal size
	void resize(const size_type)		//change size of array
		throw(bad_alloc);
	
	//access
	reference operator [](size_type) throw(out_of_range);
	const_reference operator[](size_type) const throw(out_of_range);

	reference front() { return elements[0]; }
	const_reference front() const { return elements[0]; }

	reference back() { return elements[size() - 1]; }
	const_reference back() const { return elements[size() - 1]; }

	//methods - modificators
	void push_back(const value_type&);      //add element at the end of array
	void pop_back();						//delete last element of the array
	void clear() { COUNT = 0; }				//clear array
	void swap(Array&);						//swap with other array
	void assign(const value_type&);			//fill array

	friend ostream& operator << (ostream&, const Array&);
	friend istream& operator >> (istream&, Array&);

	void Task();
};