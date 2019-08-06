//
// Created by talth on 06/08/2019.
//

#include "Vector.h"
#include "ListVector.h"

bool arrayVectorTests()
{
    Array_Vector<int> vec(5);
    vec[2] = 3;
    Array_Vector<int> other(vec);
    other[0] = 13;
    vec = vec*6;
    other = other*6-vec;
    if(other*vec != 0)
    {
        cout << "Failed on Array_Vector Test: " << endl;
        return false;
    }
    return true;
}

/*bool listVectorTests()
{
    List_Vector<int> vec(5);
    vec[2] = 3;
    List_Vector<int> other(vec);
    vec[0] = 13;
    vec = vec*6;
    other = other*6-vec;
    if(other*vec != 0)
    {
        cout << "Failed on List_Vector Test!" << endl;
        return false;
    }
    return true;
}*/

void vectorTests()
{
    if(arrayVectorTests() /*&& listVectorTests()*/)
    {
        cout << "Success on vectorTests!" << endl;
    }
}