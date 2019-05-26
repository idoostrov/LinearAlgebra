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
	
	////////Done only till this place//////////////////////////////////////////////////////
	T& operator[](int index)
	{
		if (is_array)
			return arr[index];
		else
			return list[index];
	}
	Array_Vector<T> operator+(const Array_Vector<T>& other) const
	{
		if (this->length != other.len())
		{
			throw new exception;
		}
		Array_Vector<T> vec(other);
		list<tuple<int, T>>::iterator it;
		for (it = elements.begin(); it != elements.end(); ++it)
		{
			vec[get<0>(*it)] += get<1>(*it)*this->scalar;
		}
		return vec;
	}
	List_Vector<T> operator+(const List_Vector<T>& other) const
	{
		if (this->length != other.length)
		{
			throw new exception;
		}
		List_Vector<T> vec(other);
		iterator<int, T> it;
		for (it = elements.begin(); it != elements.end(); ++it)
		{
			vec[get<0>(*it)] += get<1>(*it)*this->scalar;
		}
		return vec;
	}
	Array_Vector<T> operator-(const Array_Vector<T>& other) const
	{
		return this->operator+(other*(-1));
	}
	List_Vector<T> operator-(const List_Vector<T>& other) const
	{
		return this->operator+(other*(-1));
	}
	T operator*(const Array_Vector<T>& other) const
	{
		int tmp;
		if (this->length != other.len())
		{
			cout << "What?";
			cin >> tmp;
			throw new exception;
		}
		int sum = 0;
		iterator<int, T> it;
		for (it = elements.begin(); it != elements.end(); ++it)
		{
			sum += get<1>(*it)*other[get<0>(*it)];
		}
		return sum * this->scalar;
	}
	T operator*(const List_Vector<T>& other) const
	{
		int tmp;
		if (this->length != other.length)
		{
			cout << "What?";
			cin >> tmp;
			throw new exception;
		}
		int sum = 0;
		iterator<int, T> it;
		for (it = elements.begin(); it != elements.end(); ++it)
		{
			sum += get<1>(*it)*other[get<0>(*it)];
		}
		return sum * this->scalar;
	}
	List_Vector<T> operator*(const T scalar) const
	{
		List_Vector<T> vec(this->elements);
		vec.scalar = this->scalar*scalar;
		return vec;
	}
	T get_norm_squared()
	{
		if (this->norm_squared >= 0)
		{
			return this->norm_squared * this->scalar*this->scalar;
		}
		this->norm_squared = this->operator*(this);
		return this->norm_squared;
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
