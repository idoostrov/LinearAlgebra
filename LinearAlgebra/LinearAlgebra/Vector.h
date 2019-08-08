#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>
#include <math.h>
#include <tuple>


#define MAX_ERROR 0.001

/////////////////Forward declarations///////////////////////////
template <class T>
class List_Vector;

using namespace std;

template <class T>
class Array_Vector
{
private:
	int length;
	vector<T> elements;
	mutable T scalar;
	mutable T norm_squared;
public:
    
	/////////////////////////////////////Constructors///////////////////////////////////
	Array_Vector<T>()
    {

    }
	/**
	 * Constructor for an empty vector with the specified length
	 * @param length
	 */
	Array_Vector<T>(const int length)
	{
		this->norm_squared = -1;//Unintialized
		this->length = length;
		this->scalar = 1;
		this->elements = vector<T>(length, 0);
	}
	/**
	 * Constructor that makes our version of vector from a given std::vector
	 * @param elements
	 */
	Array_Vector<T>(const vector<T>& elements)
	{
		this->norm_squared = -1;//Unintialized
		this->scalar = 1;
		this->length = elements.size();
		this->elements = vector<T>(elements);
	}
	/**
	 * copy constructor from array vector
	 * @param other
	 */
	Array_Vector<T>(const Array_Vector& other)
	{
		this->norm_squared = other.norm_squared;
		this->scalar = other.scalar;
		this->length = other.length;
        this->elements = vector<T>(other.elements);
	}
	/**
	 * copy constructor from list vector
	 * @param other
	 */
    Array_Vector<T>(const List_Vector<T>& other)
    {
        this->norm_squared = other.get_norm_squared();
        this->scalar = 1;
        this->length = other.len();
        this->elements = vector<T>(length, 0);
        for(auto const& tup : other.get_elements())
        {
            elements[tup.first] = tup.second;
        }
    }


	///////////////////////////////////// [] Operators ///////////////////////////////////
	/**
	 * Getter function
	 * @param index
	 * @return the specified value
	 */
	T operator[](const int index) const;
	/**
	 * Assignment function
	 * @param index
	 * @return
	 */
	T& operator[](int index);

	///////////////////////////////////// + Operators ///////////////////////////////////
	Array_Vector<T> operator+(const Array_Vector<T>& other) const;

	///////////////////////////////////// - Operators ///////////////////////////////////
	Array_Vector<T> operator-(const Array_Vector<T>& other) const;

	///////////////////////////////////// * Operators ///////////////////////////////////
	/**
	 * Inner multiplication
	 * @param other
	 * @return
	 */
	T operator*(const Array_Vector<T>& other) const;
	/**
	 * Scalar multiplication
	 * @param scalar
	 * @return
	 */
	Array_Vector<T> operator*(const T scalar) const;

	///////////////////////////////////// Comparison Operators ///////////////////////////////////
	bool operator==(const Array_Vector<T> other) const;
	bool operator!=(const Array_Vector<T> other) const;

	///////////////////////////////////// Miscellaneous ///////////////////////////////////
	/**
	 * Calculates the vectors norm squared(using inner multiplication)
	 * @return
	 */
	T get_norm_squared() const;
	/**
	 * @return the vector length
	 */
	int len() const;
	/**
	 * @return the vector scalar
	 */
	int get_scalar() const;

};

template<class T>
T Array_Vector<T>::operator[](const int index) const {
    return this->elements[index] * this->scalar;
}

template<class T>
int Array_Vector<T>::get_scalar() const {
    return this->scalar;
}

template<class T>
int Array_Vector<T>::len() const {
    return this->length;
}

template<class T>
T Array_Vector<T>::get_norm_squared() const {
    if (this->norm_squared >= 0)
    {
        return this->norm_squared * this->scalar*this->scalar;
    }
    this->norm_squared = 0;
    for (int i = 0; i < length; i++)
    {
        this->norm_squared += this->elements[i] * this->elements[i];
    }
    return this->norm_squared * this->scalar*this->scalar;
}

template<class T>
bool Array_Vector<T>::operator!=(const Array_Vector<T> other) const {
    return !(this->operator==(other));
}

template<class T>
bool Array_Vector<T>::operator==(const Array_Vector<T> other) const {
    if(this->length != other.length)
        return false;
    for (int i = 0; i < this->length; ++i) {
        if(abs(this->elements[i] - other[i]) > MAX_ERROR)
            return false;
    }
    return true;
}

template<class T>
Array_Vector<T> Array_Vector<T>::operator*(const T scalar) const {
    Array_Vector<T> vec(this->elements);
    vec.scalar = this->scalar*scalar;
    return vec;
}

template<class T>
T Array_Vector<T>::operator*(const Array_Vector<T> &other) const {
    int tmp;
    if (this->length != other.length)
    {
        throw "Not suitable dimensions in Array_Vector<T>::operator*";
    }
    T sum = 0;
    for (int i = 0; i < this->length; i++)
    {
        sum += this->elements[i] * other.elements[i];
    }
    return sum * this->scalar*other.scalar;
}

template<class T>
Array_Vector<T> Array_Vector<T>::operator-(const Array_Vector<T> &other) const {
    if (this->length != other.length)
    {
        throw "Not suitable dimensions in Array_Vector<T>::operator-";
    }
    Array_Vector<T> vec(this->length);
    for (int i = 0; i < this->length; i++)
    {
        vec.elements[i] = this->elements[i] * this->scalar - other.elements[i] * other.scalar;
    }
    return vec;
}

template<class T>
Array_Vector<T> Array_Vector<T>::operator+(const Array_Vector<T> &other) const {
    if (this->length != other.length)
    {
        throw "Not suitable dimensions in Array_Vector<T>::operator+";
    }
    Array_Vector<T> vec(this->length);
    for (int i = 0; i < this->length; i++)
    {
        vec.elements[i] = this->elements[i] * this->scalar + other.elements[i] * other.scalar;
    }
    return vec;
}

template<class T>
T &Array_Vector<T>::operator[](int index) {
    this->norm_squared = -1;
    if (this->scalar != 1)
    {
        for (int i = 0; i < length; i++)
        {
            this->elements[i] *= this->scalar;
        }
        this->scalar = 1;
    }
    return this->elements[index];
}

/**
 * Printing operator of the array vector
 * @tparam T
 * @param os
 * @param v
 * @return
 */
template <typename T>
ostream& operator<<(ostream& os, const Array_Vector<T> v)
{
    os << "[";
    int length = v.len();
    if (length != 0)
    {
        os << v[0];
    }
    for (int i = 1; i < length; i++)
    {
        os << ", ";
        os << v[i];
    }
    os << "]\n";
    return os;
}

#endif//VECTOR_H