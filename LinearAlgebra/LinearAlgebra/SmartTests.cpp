//
// Created by talth on 24/07/2019.
// Contains tests for the SmartVector class
//

#include "SmartVector.h"

#define LENGTH 20
using namespace std;

void test0()
{
    Smart_Vector<int> A(LENGTH);
    cout << "Initialize Vector:" << endl;
    cout << A << endl;
    for (int i = 0; i < LENGTH; ++i)
    {
        A[i] = 1;
    }
    cout << "Sum Vector:"<< endl;
    cout << A << endl;
}

void smartTests()
{
    test0();
    return;
}