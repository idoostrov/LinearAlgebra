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
	Array_Vector<T>(const int length)
	{
		this->norm_squared = -1;//Unintialized
		this->length = length;
		this->scalar = 1;
		this->elements = vector<T>(length, 0);
	}
	Array_Vector<T>(const vector<T>& elements)
	{
		this->norm_squared = -1;//Unintialized
		this->scalar = 1;
		this->length = elements.size();
		this->elements = vector<T>(elements);
	}
	Array_Vector<T>(const Array_Vector& other)
	{
		this->norm_squared = other.norm_squared;
		this->scalar = other.scalar;
		this->length = other.length;
        this->elements = vector<T>(other.elements);
	}
    Array_Vector<T>(const List_Vector<T>& other)
    {
        this->norm_squared = other.norm_squared;
        this->scalar = other.scalar;
        this->length = other.length;
        this->elements = vector<T>(length, 0);
        iterator<int , T> it;
        for(it = other.begin(); it != other.end(); ++it)
        {
            elements[std::get<0>(*it)] = std::get<1>(*it);
        }
    }


	///////////////////////////////////// [] Operators ///////////////////////////////////
	T operator[](const int index) const;
	T& operator[](int index);

	///////////////////////////////////// + Operators ///////////////////////////////////
	Array_Vector<T> operator+(const Array_Vector<T>& other);

	///////////////////////////////////// - Operators ///////////////////////////////////
	Array_Vector<T> operator-(const Array_Vector<T>& other);

	///////////////////////////////////// * Operators ///////////////////////////////////
	T operator*(const Array_Vector<T>& other);
	Array_Vector<T> operator*(const T scalar);

	///////////////////////////////////// Comparison Operators ///////////////////////////////////
	bool operator==(const Array_Vector<T> other) const;
	bool operator!=(const Array_Vector<T> other) const;

	///////////////////////////////////// Miscellaneous ///////////////////////////////////
	T get_norm_squared();
	int len() const;
	int get_scalar();

};

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