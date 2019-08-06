#include "ListVector.h"

template<class T>
T &List_Vector<T>::operator[](int index) {
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
    return ref(get<1>(tmp));
}

template<class T>
int List_Vector<T>::size() const {
    return this->elements.size();
}

template<class T>
iterator<int, T> List_Vector<T>::begin() const {
    return elements.begin();
}

template<class T>
iterator<int, T> List_Vector<T>::end() const {
    return elements.end();
}

template<class T>
int List_Vector<T>::len() const {
    return this->length;
}

template<class T>
List_Vector<T> List_Vector<T>::operator*(const T scalar) const {
    List_Vector<T> vec(this->elements);
    vec.scalar = this->scalar*scalar;
    return vec;
}

template<class T>
T List_Vector<T>::get_norm_squared() {
    if (this->norm_squared >= 0)
    {
        return this->norm_squared * this->scalar*this->scalar;
    }
    this->norm_squared = this->operator*(this);
    return this->norm_squared;
}

template<class T>
T List_Vector<T>::operator*(const List_Vector<T> &other) const {
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

template<class T>
Array_Vector<T> List_Vector<T>::operator+(const Array_Vector<T> &other) const {
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

template<class T>
T List_Vector<T>::operator*(const Array_Vector<T> &other) const {
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

template<class T>
List_Vector<T> List_Vector<T>::operator-(const List_Vector<T> &other) const {
    return this->operator+(other*(-1));
}

template<class T>
List_Vector<T> List_Vector<T>::operator+(const List_Vector<T> &other) const {
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