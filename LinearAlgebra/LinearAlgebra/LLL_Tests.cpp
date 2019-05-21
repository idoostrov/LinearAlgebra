#include "Matrix.h"
#include "LLL.h"

bool GramSchmidtTest()
{
    Matrix m(3, 3);

    m[0][0] = 1;
    m[0][1] = 1;
    m[0][2] = 1;

    m[1][0] = -1;
    m[1][1] = 0;
    m[1][2] = 2;

    m[2][0] = 3;
    m[2][1] = 5;
    m[2][2] = 6;

    GramSchmidt(m);
    cout << m;


}



int main()
{
    GramSchmidtTest();
    return 0;
}
