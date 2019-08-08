//
// Created by ido_o on 22-May-19.
//

#ifndef LINEARALGEBRA_LISTVECTOR_H
#define LINEARALGEBRA_LISTVECTOR_H

#include <list>
#include <tuple>
#include <iostream>
#include <iterator>
#include <map>
#include "Vector.h"

using namespace std;

template <class T>
class Array_Vector;
template <class T>
class List_Vector
{
private:
    int length;
    map<int, T> elements;
    mutable T norm_squared;
public:
	/////////////////////////////////////Constructors///////////////////////////////////
	List_Vector<T>()
    {
	    this->norm_squared = -1;
	    this->length = 0;
	    this->elements = map<int, T>();
    }
	List_Vector<T>(const int length)
    {
        this->norm_squared = -1;//Unintialized
        this->length = length;
        this->elements = map<int, T>();
    }
    List_Vector<T>(const Array_Vector<T>& vec)
    {
        this->norm_squared = vec.get_norm_squared();
        this->length = vec.len();
        this->elements = map<int, T>();
		for (int i = 0; i < this->length; i++)
		{
			if (vec[i] != 0)
			{
				elements[i] = vec[i];
			}
		}
    }
    List_Vector<T>(List_Vector<T>& vec)
    {
        this->norm_squared = vec.norm_squared;
        this->length = vec.length;
        this->elements = map<int, T>();
        for(auto const& val: vec.get_elements())
        {
            this->elements[val.first] = val.second;
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
    T get_norm_squared() const;
    /**
     * return the length of the vector, i.e the max length of the map
     * @return
     */
	int len() const;
	/**
	 * return the size of the map
	 * @return
	 */
	int size() const;
	map<int, T> get_elements() const;
};

template<class T>
T List_Vector<T>::operator[](const int index) const {
    if(index >= len() || index < 0)
    {
        throw "Index out of range in List_Vector<T>::operator[]";
    }
    if(elements.find(index) != elements.end())
    {
        return elements.at(index);
    }
    return 0;
}

template<class T>
map<int, T> List_Vector<T>::get_elements() const {
    return this->elements;
}

template<class T>
int List_Vector<T>::size() const {
    return this->elements.size();
}

template<class T>
int List_Vector<T>::len() const {
    return this->length;
}

template<class T>
T List_Vector<T>::get_norm_squared() const {
    if (this->norm_squared >= 0)
    {
        return this->norm_squared;
    }
    this->norm_squared = this->operator*(*this);
    return this->norm_squared;
}

template<class T>
List_Vector<T> List_Vector<T>::operator*(const T scalar) const {
    List_Vector<T> vec(this->length);
    for(auto const& val: this->elements)
    {
        vec[val.first] = val.second*scalar;
    }
    return vec;
}

template<class T>
T List_Vector<T>::operator*(const List_Vector<T> &other) const {
    int tmp;
    if (this->length != other.length)
    {
        throw "Not suitable dimensions in List_Vector<T>::operator*";
    }
    T sum = 0;
    for(auto const& val: this->elements)
    {
        sum += val.second*other[val.first];
    }
    return sum;
}

template<class T>
T List_Vector<T>::operator*(const Array_Vector<T> &other) const {
    int tmp;
    if (this->length != other.len())
    {
        throw "Not suitable dimensions in List_Vector<T>::operator*";
    }
    T sum = 0;
    for(auto const& val: this->elements)
    {
        sum += val.second*other[val.first];
    }
    return sum;
}

template<class T>
List_Vector<T> List_Vector<T>::operator-(const List_Vector<T> &other) const {
    if (this->length != other.length)
    {
        throw "Not suitable dimensions in List_Vector<T>::operator-";
    }
    List_Vector<T> vec(*this);
    for(auto const& val: other.get_elements())
    {
        vec[val.first] -= val.second;
    }
    return vec;
}

template<class T>
Array_Vector<T> List_Vector<T>::operator-(const Array_Vector<T> &other) const {
    return this->operator+(other*(-1));
}

template<class T>
List_Vector<T> List_Vector<T>::operator+(const List_Vector<T> &other) const {
    if (this->length != other.length)
    {
        throw "Not suitable dimensions in List_Vector<T>::operator+";
    }
    List_Vector<T> vec(other);
    for(auto const& val: this->elements)
    {
        vec[val.first] += val.second;
    }
    return vec;
}

template<class T>
Array_Vector<T> List_Vector<T>::operator+(const Array_Vector<T> &other) const {
    if (this->length != other.len())
    {
        throw "Not suitable dimensions in List_Vector<T>::operator+";
    }
    Array_Vector<T> vec(other);
    for(auto const& val: this->elements)
    {
        vec[val.first] += val.second;
    }
    return vec;
}

template<class T>
T &List_Vector<T>::operator[](int index) {
    if(index >= len() || index < 0)
    {
        throw "Index out of range in List_Vector<T>::operator[]";
    }
    this->norm_squared = -1;
    if(elements.find(index) != elements.end())
    {
        return elements[index];
    }
    elements[index] = 0;
    return elements[index];
}

template <typename T>
ostream& operator<<(ostream& os, const List_Vector<T> v)
{
    const Array_Vector<T> tmp(v.len());
	os << (v.operator+(tmp));
	return os;
}




#endif //LINEARALGEBRA_LISTVECTOR_H
