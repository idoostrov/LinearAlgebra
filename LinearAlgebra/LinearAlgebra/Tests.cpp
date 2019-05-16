#include "Matrix.h"
#include "LLL.h"


int main()
{
	int tmp;
    Matrix A(2, 3);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            A[i][j] = 2 * (i + 1) * (i + 1) + i * j + 3 * j;
        }
    }

    //cout << A << endl;

    Matrix B(3, 2);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            B[i][j] = 7*(i + 1) * (i + 1) - 5 * (i + 3) * (j + 1) + 8 * j;
        }
    }
    //cout << B ;

	Matrix m = A-(~B);
	cout << A;
	cout << B;
	cout << m;
	m = A * B;
	cout << m;
	cin >> tmp;

    return 0;
}

