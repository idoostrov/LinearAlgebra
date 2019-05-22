//
// Created by ido_o on 22-May-19.
//

#ifndef LINEARALGEBRA_LISTVECTOR_H
#define LINEARALGEBRA_LISTVECTOR_H

#include <list>
#include <iostream>
#include "Vector.h"

using namespace std;



template <class T>
class List_Vector
{
private:
    int length;
    list<T> elements;
    mutable T scalar;
    mutable T norm_squared;
public:
    List_Vector<T>(const int length)
    {
        this->norm_squared = -1;//Unintialized
        this->length = length;
        this->scalar = 1;
        this->elements = list<T>();
    }
    List_Vector<T>(const Array_Vector<T>& vec)
    {
        this->norm_squared = vec.get_norm_squared();
        this->scalar = vec.get_scalar();
        this->length = vec.len();
        this->elements = vector<T>(elements);
    }
    Array_Vector<T>(const Array_Vector& other)
    {
        this->norm_squared = other.norm_squared;
        this->scalar = other.scalar;
        this->length = other.length;
        this->elements = vector<T>(other.elements);
    }

    int len() const
    {
        return this->length;
    }
    T operator[](const int index) const
    {
        return this->elements[index];
    }
    T& operator[](int index)
    {
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
    Array_Vector<T> operator+(const Array_Vector<T>& other)
    {
        if (this->length != other.length)
        {
            throw new exception;
        }
        Array_Vector<T> vec(this->length);
        for (int i = 0; i < this->length; i++)
        {
            vec.elements[i] = this->elements[i] * this->scalar + other.elements[i] * other.scalar;
        }
        return vec;
    }
    Array_Vector<T> operator-(const Array_Vector<T>& other)
    {
        if (this->length != other.length)
        {
            throw new exception;
        }
        Array_Vector<T> vec(this->length);
        for (int i = 0; i < this->length; i++)
        {
            vec.elements[i] = this->elements[i] * this->scalar - other.elements[i] * other.scalar;
        }
        return vec;
    }
    T operator*(const Array_Vector<T>& other)
    {
        int tmp;
        if (this->length != other.length)
        {
            cout << "What?";
            cin >> tmp;
            throw new exception;
        }
        int sum = 0;
        for (int i = 0; i < this->length; i++)
        {
            sum += this->elements[i] * other.elements[i];
        }
        return sum * this->scalar*other.scalar;
    }
    Array_Vector<T> operator*(const T scalar)
    {
        Array_Vector<T> vec(this->elements);
        vec.scalar = this->scalar*scalar;
        return vec;
    }
    T norm()
    {
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




#endif //LINEARALGEBRA_LISTVECTOR_H
