//
// Created by talth on 24/07/2019.
// Contains tests for the SmartVector class
//

#include "SmartVector.h"

#define LENGTH 20
using namespace std;

void test0()
{
    List_Vector<int> B(LENGTH);
    for (int i = 0; i < LENGTH; ++i)
    {
        B[i] = 1;
    }
    Smart_Vector<int> A(B);
    cout << "Sum Vector:"<< endl;
    cout << A << endl;
    cout << A*A << endl;
}

void smartTests()
{
    test0();
    return;
}