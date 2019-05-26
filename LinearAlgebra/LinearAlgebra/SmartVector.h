//
// Created by ido_o on 22-May-19.
//

#ifndef LINEARALGEBRA_LISTVECTOR_H
#define LINEARALGEBRA_LISTVECTOR_H

#include <list>
#include <tuple>
#include <iostream>
#include <iterator>
#include "Vector.h"
#include "ListVector.h"

using namespace std;

template <class T>
class Smart_Vector<T>
{
private:
	int length;
	List_Vector<T> list;
	Array_Vector<T> arr;
	bool is_array;
	int non_zero_amount;
public:
	Smart_Vector<T>(const int length)
	{
		this->length = length;
		this->list = List_Vector<T>(length);
		this->is_array = false;
		this->non_zero_amount = 0;
	}
	Smart_Vector<T>(const Array_Vector<T>& vec)
	{
		this->length = vec.len();
		this->arr = Array_Vector<T>(vec);
		this->is_array = true;
		this->non_zero_amount = 0;
		for (int i = 0; i < this->length; i++)
		{
			if (vec[i] != 0)
			{
				this->non_zero_amount++;
			}
		}
	}

	int len() const
	{
		return this->length;
	}
	T operator[](const int index) const
	{
		if (is_array)
			return arr[index];
		else
			return list[index];
	}
	
	//////////////////////////////////////////////////Undone///////////////////////////////////
	T& operator[](int index)
	{
		if (is_array)
			return arr[index];
		else
			return list[index];
	}
	Smart_Vector<T> operator+(const Array_Vector<T>& other) const
	{
		if (is_array)
			return Smart_Vector<T>(this->arr + other);
		else
			return Smart_Vector<T>(this->list + other);
	}
	Smart_Vector<T> operator+(const List_Vector<T>& other) const
	{
		if (is_array)
			return Smart_Vector<T>(other + this->arr);
		else
			return Smart_Vector<T>(other + this->list);
	}
	Smart_Vector<T> operator-(const Array_Vector<T>& other) const
	{
		return this->operator+(other*(-1));
	}
	Smart_Vector<T> operator-(const List_Vector<T>& other) const
	{
		return this->operator+(other*(-1));
	}
	T operator*(const Array_Vector<T>& other) const
	{
		if (is_array)
			return this->arr * other;
		else
			return this->list * other;
	}
	T operator*(const List_Vector<T>& other) const
	{
		if (is_array)
			return other * this->arr;
		else
			return other * this->list;
	}
	Smart_Vector<T> operator*(const T scalar) const
	{
		if (is_array)
			return this->arr * scalar;
		else
			return this->list * scalar;
	}
	T get_norm_squared()
	{
		if (is_array)
			return this->arr.get_norm_squared();
		else
			return this->list.get_norm_squared();
	}

};

template <typename T>
ostream& operator<<(ostream& os, const List_Vector<T> v)
{
	const Array_Vector<T> tmp(v.len());
	os << (v.operator+(tmp));
	return os;
}




#endif //LINEARALGEBRA_LISTVECTOR_H
