//
// Created by ido_o on 22-May-19.
//

#ifndef LINEARALGEBRA_LISTVECTOR_H
#define LINEARALGEBRA_LISTVECTOR_H

#include <list>
#include <tuple>
#include <iostream>
#include <iterator>
#include "ArrayVector.h"

using namespace std;

template <class T>
class List_Vector
{
private:
    int length{};
    list<tuple<int, T>> elements;
    mutable T scalar;
    mutable T norm_squared;
public:
	/////////////////////////////////////Constructors///////////////////////////////////
    explicit List_Vector<T>(const int length)
    {
        this->norm_squared = -1;//Unintialized
        this->length = length;
        this->scalar = 1;
        this->elements = list<tuple<int, T>>();
    }
    explicit List_Vector<T>(const Array_Vector<T>& vec)
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
    T operator[](const int index) const;
    T& operator[](int index);

	///////////////////////////////////// + Operators ///////////////////////////////////
	Array_Vector<T> operator+(const Array_Vector<T>& other) const;
	List_Vector<T> operator+(const List_Vector<T>& other) const;

	///////////////////////////////////// - Operators ///////////////////////////////////
    Array_Vector<T> operator-(const Array_Vector<T>& other) const;
	List_Vector<T> operator-(const List_Vector<T>& other) const;

	///////////////////////////////////// * Operators ///////////////////////////////////
    T operator*(const Array_Vector<T>& other) const;
	T operator*(const List_Vector<T>& other) const;
    List_Vector<T> operator*(const T scalar) const;

	///////////////////////////////////// Miscellaneous ///////////////////////////////////
    T get_norm_squared();
	int len() const;
	int size() const;
	iterator<int, T> begin() const;
    iterator<int, T> end() const;
};

template<class T>
T List_Vector<T>::operator[](const int index) const {
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



template<class T>
Array_Vector<T> List_Vector<T>::operator-(const Array_Vector<T> &other) const {
    return this->operator+(other*(-1));
}

template <typename T>
ostream& operator<<(ostream& os, const List_Vector<T> v)
{
    const Array_Vector<T> tmp(v.len());
	os << (v.operator+(tmp));
	return os;
}




#endif //LINEARALGEBRA_LISTVECTOR_H
