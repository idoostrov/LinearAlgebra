#include "Matrix.h"

bool Test1() // checking matrix multiplication
{
    Matrix<int> A(2, 3);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            A[i][j] = 2 * (i + 1) * (i + 1) + i * j + 3 * j;
        }
    }

    Matrix<int> B(3, 2);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            B[i][j] = 7*(i + 1) * (i + 1) - 5 * (i + 3) * (j + 1) + 8 * j;
        }
    }

    Matrix<int> m = A * B;
    Matrix<int> result(2,2);
    result[0][0]=328;
    result[0][1]=118;
    result[1][0]=640;
    result[1][1]=168;
    return m==result;
}

int Test2() //checking Transpose function
{
    Matrix<int> m(3, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    m[2][0] = 5;
    m[2][1] = 6;

    Matrix<int> n = ~m;

    return n.getWidth()==2 && n.getLength()==3 && n[0][0] == 1 && n[0][1] == 3 && n[0][2] == 5 && n[1][0] == 2 && n[1][1] == 4 && n[1][2] == 6;

}

int Test3() //checking inverse and addition functions
{
    Matrix<int> m(2, 2);
    m[0] = vector<int>(2, 3);
    m[1][0] = 4;
    m[1][1] = -3;
    Matrix<int> n(m);
    n = n + (~m)*3;
    Matrix<int> a = m*n;
    return m.deter() == -21 && n.deter() == -339 && a.deter()== (21*339);
}

int Test4()//checking swap function
{
    Matrix<int> m(3, 3);
    for(int i=0; i < 3; i++)
    {
        for(int j=0; j < 3; j++)
        {
            m[i][j] = i;
        }
    }
    m.swap(0,1);
    for(int i=0; i < 2; i++)
    {
        for(int j=0; j < 3; j++)
        {
            if(m[i][j] != 1-i)
                return false;
        }
    }
    for(int j=0; j < 3; j++)
        if(m[2][j] != 2)
            return false;
    return true;
}
bool Test5()//Another checking of multiplication function
{
    Matrix<int> A(2), B(2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            A[i][j] = B[i][j] = (i==j?1:0);

        }

    }
    Matrix<int> C = A*B;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if(C[i][j] != A[i][j])
                return false;

        }

    }
    return true;
}




void matrixTests()
{
    bool flag = true;

    if(!Test1())
    {
        flag = false;
        cout << "failed on matrix test 1" << endl;
    }
    if(!Test2())
    {
        flag = false;
        cout << "failed on matrix test 2" << endl;
    }

    if(!Test3())
    {
        flag = false;
        cout << "failed on test matrix 3" << endl;
    }
    if(!Test4())
    {
        flag = false;
        cout << "failed on test matrix 4" << endl;
    }
    if(!Test5())
    {
        flag = false;
        cout << "failed on test matrix 5" << endl;
    }

    if(flag)
        cout << "success in matrix tester!" << endl;
    return;
}

