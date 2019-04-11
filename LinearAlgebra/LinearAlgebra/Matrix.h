#include "Vector.h"
#include <math.h>

class Matrix
{
private:
	int width, length, rank;
	vector<Array_Vector> rows;
	type det, scalar;
	bool det_calculated;
	void swap(int row1, int row2);
	int elliminate_col(int row, int col);
	int find_not_zero(int col, int start);
public:
	Matrix(int width, int length);
	Matrix(Matrix& other);

	int len() const;
	int wid() const;

	type deter();
	Array_Vector& operator[](int row);
	Matrix operator+(Matrix& b);
	Matrix operator-(Matrix& b);
	Matrix operator*(type scalar);
	Matrix operator*(Matrix& b);
	Matrix operator~();
	Matrix operator*();
};
ostream& operator<<(ostream& os, Matrix& p);