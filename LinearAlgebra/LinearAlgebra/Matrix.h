#include "ArrayVector.h"
#include <math.h>
#include <thread>

#ifndef MATRIX_H
#define MATRIX_H

template <class T>
class Matrix
{
private:
	int width, length;
	mutable int rank;
	vector<Array_Vector<T>> rows;
	mutable T det;
	mutable bool det_calculated;
public:

	/////////////////////////////////////Constructors///////////////////////////////////
    Matrix<T>(int size)
    {
        this->width = size;
        this->length = size;
        this->rank = 0;
        this->det_calculated = true;
        this->det = 0;
        this->rows = vector<Array_Vector<T>>(size, Array_Vector<T>(size));
    }
	Matrix<T>(int width, int length)
	{
		this->width = width;
		this->length = length;
		this->rank = 0;
		this->det_calculated = true;
		this->det = 0;
		this->rows = vector<Array_Vector<T>>(width, Array_Vector<T>(length));
	}
	Matrix<T>(Matrix<T>& b)
	{
		this->width = b.width;
		this->length = b.length;
		this->rank = b.rank;
		this->det = b.det;
		this->det_calculated = b.det_calculated;
		this->rows = vector<Array_Vector<T>>(b.rows);
	}
	Matrix<T>(const Matrix<T>& b)
	{
		this->width = b.width;
		this->length = b.length;
		this->rank = b.rank;
		this->det = b.det;
		this->det_calculated = b.det_calculated;
		this->rows = vector<Array_Vector<T>>(b.rows);
	}
    Matrix<T>(const Matrix<T>* b)
    {
        this->width = b->width;
        this->length = b->length;
        this->rank = b->rank;
        this->det = b->det;
        this->det_calculated = b->det_calculated;
        this->rows = vector<Array_Vector<T>>(b->rows);
    }

	///////////////////////////////////// Miscellaneous ///////////////////////////////////
	int getLength() const;
	int getWidth() const;

	///////////////////////////////////// LLL Miscellaneous ///////////////////////////////////
	void swap(int row1, int row2);
	T eliminate_col(int row, int col);
	T find_not_zero(int col, int start);
	T deter();

	///////////////////////////////////// [] Operators ///////////////////////////////////
	Array_Vector<T>& operator[](int row);
	const Array_Vector<T>& operator[](int row) const;

	///////////////////////////////////// + Operators ///////////////////////////////////
	Matrix<T> operator+(Matrix<T> other);

	///////////////////////////////////// Comparison Operators ///////////////////////////////////
    bool operator==(const Matrix<T> other) const;

	///////////////////////////////////// - Operators ///////////////////////////////////
	Matrix<T> operator-(Matrix<T> other);

	///////////////////////////////////// * Operators ///////////////////////////////////
	///////////////////////////////////// * Operators ///////////////////////////////////
	Matrix<T> operator*(T scalar);
    Matrix<T> DistrebutedStrssenAlgorithm(const Matrix<T>& other);
    Matrix<T> StrssenAlgorithm(const Matrix<T>& other, bool is_first = 1);
	Matrix<T> operator*(const Matrix<T>& other);

	///////////////////////////////////// Inverse Operator ///////////////////////////////////
	Matrix<T> operator~() const;

	///////////////////////////////////// Assignment Operators ///////////////////////////////////
	/*void operator=(const Matrix<T> M)
	{
		this->det = M.det;
		this->det_calculated = M.det_calculated;
		this->length = M.length;
		this->width = M.width;
		this->rank = M.rank;
		this->rows = M.rows;
	}*/

};

template <typename T>
ostream& operator<<(ostream& os, const Matrix<T> m )
{
    os << "{";
    int length = m.getLength();
    int width = m.getWidth();
    if (width != 0)
    {
        if (length != 0)
        {
            os << m[0];
        }
    }
    for (int i = 1; i < width; i++)
    {
        os << m[i];
    }
    os << "}" << endl;
    return os;
}





#endif //MATRIX_H