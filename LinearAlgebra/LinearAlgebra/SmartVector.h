//
// Created by ido_o on 22-May-19.
//

#ifndef LINEARALGEBRA_SMARTVECTOR_H
#define LINEARALGEBRA_SMARTVECTOR_H

#include <list>
#include <tuple>
#include <iostream>
#include <iterator>
#include "AssignmentBuffer.h"
#include "ListVector.h"
#include "Vector.h"

#define LOW_BOUND 5
#define HIGH_BOUND 10

using namespace std;

template <class T>
class Smart_Vector
{
private:
	int length;
	List_Vector<T> list;
	Array_Vector<T> arr;
	bool is_array;
	bool is_list;
	int non_zero_amount;
public:
	/////////////////////////////////////Constructors///////////////////////////////////

	/**
	 * Default constructor, initialize smart as empty list vector
	 * @param length
	 */
	Smart_Vector<T>(int length)
	{
		this->length = length;
		this->list = List_Vector<T>(length);
		this->is_array = false;
		this->is_list = true;
		this->non_zero_amount = 0;
	}

	/**
	 * Constructor that recieves array vector and update the parameters and the type accordingly
	 * @param vec
	 */
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
		if(this->non_zero_amount < LOW_BOUND)
        {
		    this->list = List_Vector<T>(vec);
		    this->is_list = true;
        }
		else
        {
		    this->is_list = false;
        }
	}

    /**
     * Constructor that recieves list vector and update the parameters and the type accordingly
     * @param vec
     */
	Smart_Vector<T>(const List_Vector<T>& vec)
	{
		this->length = vec.len();
		this->is_list = false;
		this->is_array = false;
		this->non_zero_amount = vec.size();
		if(this->non_zero_amount < HIGH_BOUND)
        {
		    this->is_list = true;
		    this->list = List_Vector<T>(vec);
		    cout << this->list;
        }
		if(this->non_zero_amount > LOW_BOUND)
        {
		    this->is_array = true;
		    this->arr = Array_Vector<T>(vec);
		    cout << this->arr;
        }
	}

	/**
	 * Copy constructor that copy an existing smart vector
	 * @param vec
	 */
	Smart_Vector<T>(const Smart_Vector<T>& vec)
    {
	    this->length = vec.length;
	    this->is_array = vec.is_array;
	    this->is_list = vec.is_list;
	    this->non_zero_amount = vec.non_zero_amount;
	    if(this->is_array)
        {
	        this->arr = Array_Vector<T>(vec.arr);
        }
	    if(this->is_list)
        {
	        this->list = List_Vector<T>(vec.list);
        }
    }

	///////////////////////////////////// [] Operators ///////////////////////////////////
	/**
	 * Get function
	 * @param index
	 * @return the value at the specific index
	 */
	T operator[](const int index) const
	{
		if (is_array)
			return arr[index];
		else
			return list[index];
	}

	//////////////////////////////////////////////////Assignment Operators///////////////////////////////////
	/**
	 * This operator is designed to return a temporary assignment buffer in order to compute non_zero_amount change.
	 * @param index
	 * @return
	 */
	Assignment_Buffer<T>& operator[](int index)
	{
	    if(is_array)
        {
	        if(is_list)
            {
	            return Assignment_Buffer<T>(this->arr, this->list, index, &this->non_zero_amount);
            }
            return Assignment_Buffer<T>(this->arr, index, &this->non_zero_amount);
        }
        return Assignment_Buffer<T>(this->list, index, &this->non_zero_amount);
	}

	///////////////////////////////////// + Operators ///////////////////////////////////
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

	///////////////////////////////////// - Operators///////////////////////////////////
	Smart_Vector<T> operator-(const Array_Vector<T>& other) const
	{
		return this->operator+(other*(-1));
	}
	Smart_Vector<T> operator-(const List_Vector<T>& other) const
	{
		return this->operator+(other*(-1));
	}

	///////////////////////////////////// * Operators ///////////////////////////////////
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
	T operator*(const Smart_Vector<T>& other) const
    {
	    if(is_array)
	        return other*this->arr;
        else
            return other*this->list;
    }

	///////////////////////////////////// Miscellaneous ///////////////////////////////////
    int len() const
    {
        return this->length;
    }

	T get_norm_squared() const
	{
		if (is_list)
			return this->list.get_norm_squared();
		else
			return this->arr.get_norm_squared();
	}

};

template <typename T>
ostream& operator<<(ostream& os, const Smart_Vector<T> v)
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

#endif //LINEARALGEBRA_LISTVECTOR_H
