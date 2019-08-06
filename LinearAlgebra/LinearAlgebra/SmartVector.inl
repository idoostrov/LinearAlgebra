template<class T>
Assignment_Buffer<T> &Smart_Vector<T>::operator[](int index) {
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

template<class T>
T Smart_Vector<T>::get_norm_squared() {
    if (is_list)
        return this->list.get_norm_squared();
    else
        return this->arr.get_norm_squared();
}

template<class T>
int Smart_Vector<T>::len() const {
    return this->length;
}

template<class T>
T Smart_Vector<T>::operator*(const Array_Vector<T> &other) const {
    if (is_array)
        return this->arr * other;
    else
        return this->list * other;
}

template<class T>
Smart_Vector<T> Smart_Vector<T>::operator-(const List_Vector<T> &other) const {
    return this->operator+(other*(-1));
}

template<class T>
Smart_Vector<T> Smart_Vector<T>::operator*(const T scalar) const {
    if (is_array)
        return this->arr * scalar;
    else
        return this->list * scalar;
}

template<class T>
T Smart_Vector<T>::operator*(const List_Vector<T> &other) const {
    if (is_array)
        return other * this->arr;
    else
        return other * this->list;
}

template<class T>
Smart_Vector<T> Smart_Vector<T>::operator+(const List_Vector<T> &other) const {
    if (is_array)
        return Smart_Vector<T>(other + this->arr);
    else
        return Smart_Vector<T>(other + this->list);
}

template<class T>
Smart_Vector<T> Smart_Vector<T>::operator+(const Array_Vector<T> &other) const {
    if (is_array)
        return Smart_Vector<T>(this->arr + other);
    else
        return Smart_Vector<T>(this->list + other);
}

template<class T>
T Smart_Vector<T>::operator[](const int index) const {
    if (is_array)
        return arr[index];
    else
        return list[index];
}

template<class T>
Smart_Vector<T> Smart_Vector<T>::operator-(const Array_Vector<T> &other) const {
    return this->operator+(other*(-1));
}