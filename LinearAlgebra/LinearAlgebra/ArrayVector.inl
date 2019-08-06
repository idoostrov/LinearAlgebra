//
// Created by talth on 06/08/2019.
//

#include "ArrayVector.h"

template<class T>
T Array_Vector<T>::operator[](const int index) const {
    return this->elements[index] * this->scalar;
}

template<class T>
int Array_Vector<T>::get_scalar() {
    return this->scalar;
}

template<class T>
int Array_Vector<T>::len() const {
    return this->length;
}

template<class T>
T Array_Vector<T>::get_norm_squared() {
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
Array_Vector<T> Array_Vector<T>::operator*(const T scalar) {
    Array_Vector<T> vec(this->elements);
    vec.scalar = this->scalar*scalar;
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

template<class T>
T Array_Vector<T>::operator*(const Array_Vector<T> &other) {
    int tmp;
    if (this->length != other.length)
    {
        cout << "What?";
        cin >> tmp;
        throw new exception;
    }
    T sum = 0;
    for (int i = 0; i < this->length; i++)
    {
        sum += this->elements[i] * other.elements[i];
    }
    return sum * this->scalar*other.scalar;
}

template<class T>
Array_Vector<T> Array_Vector<T>::operator-(const Array_Vector<T> &other) {
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

template<class T>
Array_Vector<T> Array_Vector<T>::operator+(const Array_Vector<T> &other) {
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

