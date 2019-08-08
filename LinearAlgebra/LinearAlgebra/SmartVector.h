//
// Created by ido_o on 22-May-19.
//

#ifndef LINEARALGEBRA_SMARTVECTOR_H
#define LINEARALGEBRA_SMARTVECTOR_H

#include <list>
#include <tuple>
#include <iostream>
#include <iterator>
//#include "AssignmentBuffer.h"
#include "ListVector.h"
#include "Vector.h"

#define LOW_BOUND 5
#define HIGH_BOUND 10

using namespace std;
/**
 *
 * Assuming List&Array vectors handle unsuitable dimensions, and thus, leave them to throw the exception
 */
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
	int set_count;
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
		this->set_count = 0;
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
        this->set_count = 0;
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
    Smart_Vector<T>(const vector<T>& vec)
    {
        this->length = vec.size();
        this->arr = Array_Vector<T>(vec);
        this->is_array = true;
        this->non_zero_amount = 0;
        this->set_count = 0;
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
        this->set_count = 0;
		if(this->non_zero_amount < HIGH_BOUND)
        {
		    this->is_list = true;
		    this->list = List_Vector<T>(vec);
        }
		if(this->non_zero_amount > LOW_BOUND)
        {
		    this->is_array = true;
		    this->arr = Array_Vector<T>(vec);
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
        this->set_count = vec.set_count;
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
        if(index >= len() || index < 0)
        {
            throw "Index out of range in Smart_Vector<T>::operator[]"
        }
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
	T& operator[](int index)
	{
        if(index >= len() || index < 0)
        {
            throw "Index out of range in Smart_Vector<T>::operator[]"
        }
        /////////////set_count handling////////////////////
	    if(is_list)
        {
	        if(set_count == HIGH_BOUND)
            {
	            for(auto const& val: list.get_elements())
                {
	                if(val.second == 0)
                    {
	                    list.get_elements().erase(val.first);
                    }
                }
	            non_zero_amount = list.size();
	            if(non_zero_amount > HIGH_BOUND)
                {
	                if(!is_array)
                    {
	                    is_array = true;
	                    arr = Array_Vector<T>(list);
                    }
	                is_list = false;
                }
	            set_count = 0;
            }
        } else
        {
	        if(set_count == length)
            {
	            non_zero_amount = 0;
                for (int i = 0; i < length; ++i) {
                    if(arr[i] != 0)
                        non_zero_amount++;
                }
                if(non_zero_amount < LOW_BOUND) {
                    if (!is_list) {
                        is_list = true;
                        list = List_Vector<T>(arr);
                    }
                    is_array = false;
                }
                set_count = 0;
            }
        }
	    ////////////assignment//////////////////
	    set_count++;
	    if(is_array)
        {
	        return arr[index];
        } else
            return list[index];
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
    Smart_Vector<T> operator+(const Smart_Vector<T>& other) const
    {
        if (is_array)
            return Smart_Vector<T>(other + this->arr);
        else
            return Smart_Vector<T>(other + this->list);
    }

	///////////////////////////////////// - Operators///////////////////////////////////
	Smart_Vector<T> operator-(const Array_Vector<T>& other) const
	{
		return this->operator+(other*(T)(-1));
	}
	Smart_Vector<T> operator-(const List_Vector<T>& other) const
	{
		return this->operator+(other*(T)(-1));
	}
    Smart_Vector<T> operator-(const Smart_Vector<T>& other) const
    {
        if (is_array)
            return Smart_Vector<T>(other - this->arr);
        else
            return Smart_Vector<T>(other - this->list);
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
    ///////////////////////////////////// Comparison Operators /////////////////////////////
    bool operator==(const Smart_Vector<T> other) const
    {
	    if(this->len() != other.len())
	        return false;
	    if(this->is_list)
        {
            for (int i = 0; i < this->len(); ++i) {
                if(abs(this->list[i] - other[i]) > MAX_ERROR)
                    return false;
            }
        } else {
            for (int i = 0; i < this->len(); ++i) {
                if (abs(this->arr[i] - other[i]) > MAX_ERROR)
                    return false;
            }
        }
        return true;
    }
    bool operator!=(const Smart_Vector<T> other) const
    {
        return !(this->operator==(other));
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
