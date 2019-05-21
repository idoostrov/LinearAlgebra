#include "Vector.h"
#include <math.h>

#ifndef MATRIX_H
#define MATRIX_H

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
	int eliminate_col(int row, int col);
	int find_not_zero(int col, int start);
	Matrix(int width, int length);
	Matrix(Matrix& other);
	Matrix(const Matrix& other);

	int getLength() const;
	int getWidth() const;

	type deter();
	Array_Vector& operator[](int row);
	const Array_Vector& operator[](int row) const;
	Matrix operator+(Matrix b);
    void operator=(const Matrix M);
	Matrix operator-(Matrix b);
	Matrix operator*(type scalar);
	Matrix operator*(const Matrix& b);
	Matrix operator~() const;
    bool operator==(const Matrix other) const;
};
ostream& operator<<(ostream& os, const Matrix& p);

#endif //MATRIX_H