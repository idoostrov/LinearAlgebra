#include "Vector.h"
#include <math.h>

class Matrix
{
private:
	int width, length;
	mutable int rank;
	vector<Array_Vector> rows;
	mutable type det, scalar;
	mutable bool det_calculated;
public:
	void swap(int row1, int row2);
	int elliminate_col(int row, int col);
	int find_not_zero(int col, int start);
	Matrix(int width, int length);
	Matrix(Matrix& other);

	int getLength() const;
	int getWidth() const;

	type deter();
	Array_Vector& operator[](int row);
	Matrix operator+(Matrix& b);
	Matrix operator-(const Matrix& b);
	Matrix operator*(type scalar);
	Matrix operator*(Matrix& b);
	Matrix operator~();
	Matrix operator*();
};
ostream& operator<<(ostream& os, Matrix& p);