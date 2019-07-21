//
// Created by talth on 19/06/2019.
//

#ifndef LINEARALGEBRA_ASSIGNMENTBUFFER_H
#define LINEARALGEBRA_ASSIGNMENTBUFFER_H

#include "Vector.h"
#include "ListVector.h"

template <class T>
class Assignment_Buffer {
    //this->arr, this->list, index, &this->non_zero_amount
private:
    int index;
    bool is_array, is_list;
    Array_Vector <T> arr;
    List_Vector <T> list;
    int *non_zero_amount;

public:
    Assignment_Buffer<T>(Array_Vector <T> arr, List_Vector <T> list, int index, &int non_zero_amount)
    {
        this->index = index;
        this->is_array = true;
        this->is_list = true;
        this->arr = arr;
        this->list = list;
        this->non_zero_amount = non_zero_amount;
    }

    Assignment_Buffer<T>(Array_Vector <T> arr, int index, &int non_zero_amount)
    {
        this->index = index;
        this->is_array = true;
        this->is_list = false;
        this->arr = arr;
        this->non_zero_amount = non_zero_amount;
    }

    Assignment_Buffer<T>(List_Vector <T> list, int index, &int non_zero_amount)
    {
        this->index = index;
        this->is_array = false;
        this->is_list = true;
        this->list = list;
        this->non_zero_amount = non_zero_amount;
    }

    operator=(T input) {
        if (is_array) {
            if (arr[index] != 0) {
                if (input != 0) {
                    arr[index] = input;
                    if (is_list) {
                        list[index] = input;
                        return;
                    }
                }
                *non_zero_amount--;
                arr[index] = input;
                if (is_list) {
                    list[index] = input;
                    return;
                }
            }
            if (input != 0) {
                *non_zero_amount++;
                arr[index] = input;
                if (is_list) {
                    list[index] = input;
                }
            }
        }
    };

};
#endif //LINEARALGEBRA_ASSIGNMENTBUFFER_H
