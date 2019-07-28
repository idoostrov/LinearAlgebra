#include "Matrix.h"
#include "LLL.h"
#include "ListVector.h"

bool GramSchmidtTest()
{
    List_Vector<int> L(12);
    Matrix<double> m(3, 3);

    m[0][0] = 1;
    m[0][1] = 1;
    m[0][2] = 1;

    m[1][0] = -1;
    m[1][1] = 0;
    m[1][2] = 2;

    m[2][0] = 3;
    m[2][1] = 5;
    m[2][2] = 6;

    m = GramSchmidt(m);
    Matrix<double> result(3,3);

    result[0][0] = 1;
    result[0][1] = 1;
    result[0][2] = 1;

    result[1][0] = -4.0/3;
    result[1][1] = -1.0/3;
    result[1][2] = 5.0/3;

    result[2][0] = -3.0/7;
    result[2][1] = 9.0/14;
    result[2][2] = -3.0/14;

    return m == result;
}

bool LLLTest()
{
    Matrix<int> m(3, 3);

    m[0][0] = 1;
    m[0][1] = 1;
    m[0][2] = 1;

    m[1][0] = -1;
    m[1][1] = 0;
    m[1][2] = 2;

    m[2][0] = 3;
    m[2][1] = 5;
    m[2][2] = 6;

    Matrix<int> result(3,3);

    result[0][0] = 0;
    result[0][1] = 1;
    result[0][2] = 0;

    result[1][0] = 1;
    result[1][1] = 0;
    result[1][2] = 1;

    result[2][0] = -1;
    result[2][1] = 0;
    result[2][2] = 2;

    cout << LLL(m,0.75) ;

    return result == LLL(m, 0.75);

}

/*
int main()
{
    bool flag = true;
    if(!GramSchmidtTest())
    {
        flag = false;
        cout << "failed on GramSchmidtTest()" << endl;
    }
    if(!LLLTest())
    {
        flag = false;
        cout << "failed on LLLTest" << endl;
    }
    if(flag)
        cout << "success in LLL tester!" << endl;
    return 0;
}
*/