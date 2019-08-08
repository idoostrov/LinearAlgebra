//
// Created by talth on 31/07/2019.
//

#include "Tests.h"

int main()
{
    try {
        vectorTests();
        matrixTests();
        lllTests();
        mangerTests();
    }
    catch(string msg)
    {
        cout << "Error: " << msg << endl;
        cout << "Quiting program due to unexpected error" << endl;
        return 1;
    }
    return 0;
}
