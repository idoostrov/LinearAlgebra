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

using namespace std;

template <class T>
class Array_Vector;
template <class T>
class List_Vector
{
protected:
    int length{};
    list<tuple<int, T>> elements;
    mutable T norm_squared;
public:
	/////////////////////////////////////Constructors///////////////////////////////////
    explicit List_Vector<T>(const int length)
    {
        this->norm_squared = -1;//Unintialized
        this->length = length;
        this->elements = list<tuple<int, T>>();
    }
    explicit List_Vector<T>(const Array_Vector<T>& vec)
    {
        this->norm_squared = vec.get_norm_squared();
        this->length = vec.len();
        this->elements = list<tuple<int, T>>();
		for (int i = 0; i < this->length; i++)
		{
			if (vec[i] != 0)
			{
				elements.push_back(tuple<int, T>(i, vec[i]));
			}
		}
    }
    List_Vector<T>(List_Vector<T>& vec)
    {
        this->norm_squared = vec.norm_squared;
        this->length = vec.length;
        this->elements = list<tuple<int, T>>();
        typename std::list<tuple<int,T>>::const_iterator it;
        for (it = vec.elements.begin(); it != vec.elements.end(); ++it)
        {
            this->elements.push_back(make_tuple(get<0>(*it), get<1>(*it)));
        }
    }

	///////////////////////////////////// [] Operators ///////////////////////////////////
    T operator[](const int index) const
    {
        typename std::list<tuple<int,T>>::const_iterator it;
        for (it = elements.begin(); it != elements.end(); ++it)
		{
			if (get<0>(*it) == index)
				return get <1>(*it);
		}
		return 0;
    }
    T& operator[](int index)
    {
        this->norm_squared = -1;
		for (tuple<int , T> &tup : elements)
		{
			if (get<0>(tup) == index)
				return (get<1>(tup));
		}
		tuple<int, T> tmp(index, 0);
		this->elements.push_back(tmp);
        return (get<1>(tmp));
    }

	///////////////////////////////////// + Operators ///////////////////////////////////
	Array_Vector<T> operator+(const Array_Vector<T>& other) const
    {
        if (this->length != other.len())
        {
            throw new exception;
        }
		Array_Vector<T> vec(other);
        typename std::list<tuple<int,T>>::const_iterator it;
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
        iterator<int ,T> it;
		for (it = elements.begin(); it != elements.end(); ++it)
		{
			vec[get<0>(*it)] += get<1>(*it);
		}
		return vec;
	}

	///////////////////////////////////// - Operators ///////////////////////////////////
    Array_Vector<T> operator-(const Array_Vector<T>& other) const
    {
		return this->operator+(other*(-1));
    }
	List_Vector<T> operator-(const List_Vector<T>& other) const
	{
        if (this->length != other.length)
        {
            throw new exception;
        }
        List_Vector<T> vec(other);
        for (tuple<int, T> tup: elements)
        {
            vec[get<0>(tup)] = get<1>(tup) - vec[get<0>(tup)];
        }
        return vec;
	}

	///////////////////////////////////// * Operators ///////////////////////////////////
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
        iterator<int ,T> it;
		for (it = elements.begin(); it != elements.end(); ++it)
		{
			sum += get<1>(*it)*other[get<0>(*it)];
		}
        return sum;
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
		for (tuple<int, T> tup: elements)
		{
			sum += get<1>(tup)*other[get<0>(tup)];
		}
		return sum;
	}
    List_Vector<T> operator*(const T scalar) const
    {
        List_Vector<T> vec(this->length);
        for(tuple<int, T> tup : elements)
        {
            vec[get<0>(tup)] = get<1>(tup)*scalar;
        }
        return vec;
    }

	///////////////////////////////////// Miscellaneous ///////////////////////////////////
    T get_norm_squared() const
    {
        if (this->norm_squared >= 0)
        {
            return this->norm_squared;
        }
		this->norm_squared = this->operator*(*this);
		return this->norm_squared;
    }
	int len() const
	{
		return this->length;
	}
	int size() const
    {
	    return this->elements.size();
    }
	list<tuple<int, T>> get_elements() const
    {
	    return this->elements;
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
