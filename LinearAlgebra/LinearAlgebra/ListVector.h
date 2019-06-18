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
class List_Vector
{
private:
    int length;
    list<tuple<int, T>> elements;
    mutable T scalar;
    mutable T norm_squared;
public:
	/////////////////////////////////////Constructors///////////////////////////////////
    List_Vector<T>(const int length)
    {
        this->norm_squared = -1;//Unintialized
        this->length = length;
        this->scalar = 1;
        this->elements = list<tuple<int, T>>();
    }
    List_Vector<T>(const Array_Vector<T>& vec)
    {
        this->norm_squared = vec.get_norm_squared();
        this->scalar = vec.get_scalar();
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

	///////////////////////////////////// [] Operators ///////////////////////////////////
    T operator[](const int index) const
    {
        iterator<int ,T> it;
		for (it = elements.begin(); it != elements.end(); ++it)
		{
			if (get<0>(*it) > index)
				break;
			if (get<0>(*it) == index)
				return get <1>(*it);
		}
		return 0;
    }
    T& operator[](int index)
    {
        this->norm_squared = -1;
        iterator<int ,T> it;
        if (this->scalar != 1)
        {
            for (it = elements.begin(); it != elements.end(); ++it)
            {
                this->elements[get<0>(*it)] *= this->scalar;
            }
            this->scalar = 1;
        }
		for (it = elements.begin(); it != elements.end(); ++it)
		{
			if (get<0>(*it) > index)
				break;
			if (get<0>(*it) == index)
				return get<1>(*it);
		}
		tuple<int, T> tmp(index, 0);
		this->elements.insert(it, tmp);
        return get<1>(tmp);
    }

	///////////////////////////////////// + Operators ///////////////////////////////////
    Array_Vector<T> operator+(const Array_Vector<T>& other) const
    {
        if (this->length != other.len())
        {
            throw new exception;
        }
		Array_Vector<T> vec(other);
        list<tuple<int, T>>:: iterator it;
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
			vec[get<0>(*it)] += get<1>(*it)*this->scalar;
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
		return this->operator+(other*(-1));
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
        iterator<int ,T> it;
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

	///////////////////////////////////// Miscellaneous ///////////////////////////////////
    T get_norm_squared()
    {
        if (this->norm_squared >= 0)
        {
            return this->norm_squared * this->scalar*this->scalar;
        }
		this->norm_squared = this->operator*(this);
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
	iterator<int, T> begin() const
    {
	    return elements.begin();
    }
    iterator<int, T> end() const
    {
	    return elements.end();
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
