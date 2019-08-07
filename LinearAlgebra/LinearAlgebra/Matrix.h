#include "Vector.h"
#include <math.h>

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
	int getLength() const
	{
		return this->length;
	}
	int getWidth() const
	{
		return this->width;
	}

	///////////////////////////////////// LLL Miscellaneous ///////////////////////////////////
	void swap(int row1, int row2)
	{
		Array_Vector<T> temp = Array_Vector<T>(rows[row1]);
		rows[row1] = rows[row2];
		rows[row2] = temp;
	}
	T eliminate_col(int row, int col)
	{
		for (int i = row + 1; i < this->length; i++)
		{
			rows[i] = rows[i] * rows[row][col] - rows[row] * rows[i][col];
		}
		return T(pow(rows[row][col], this->length - row - 1));
	}
	T find_not_zero(int col, int start)
	{
		for (int i = start; i < this->length; i++)
		{
			if (this->rows[i][col] != 0)
			{
				return i;
			}
		}
		return -1;
	}
	T deter()
	{
		if (det_calculated)
		{
			return this->det;
		}
		this->det_calculated = true;
		if (this->length != this->width)
		{
			return 0;
		}
		Matrix<T> m(this);
		T denominator = 1;
		int cur_row;
		for (int i = 0; i < this->length; i++)
		{
			cur_row = m.find_not_zero(i, i);
			if (cur_row == -1)
			{
				this->det = 0;
				return 0;
			}
			m.swap(i, cur_row);
			denominator *= m.eliminate_col(i, i);
		}
		this->det = 1;
		for (int i = 0; i < this->length; i++)
		{
			this->det *= m.rows[i][i];
		}
		this->det = this->det / denominator;
		return this->det;

	}

	///////////////////////////////////// [] Operators ///////////////////////////////////
	Array_Vector<T>& operator[](int row)
	{
		if (row >= this->rows.size()) {
			throw "Error: index is too big\n";
		}
		this->det_calculated = false;
		return this->rows[row];
	}
	const Array_Vector<T>& operator[](int row) const
	{
		if (row >= this->rows.size()) {
			throw "Error: index is too big\n";
		}
		return this->rows[row];
	}

	///////////////////////////////////// + Operators ///////////////////////////////////
	Matrix<T> operator+(Matrix<T> other)
	{
		if ((this->length != other.length) || (this->width != other.width))
		{
			throw "Error: dimensions do not match\n";
		}
		Matrix<T> m(this->width, this->length);
		for (int i = 0; i < this->width; i++)
		{
			m[i] = (this->rows[i]) + (other[i]);
		}
		m.det_calculated = false;
		return m;
	}

	///////////////////////////////////// Comparison Operators ///////////////////////////////////
    bool operator==(const Matrix<T> other) const
    {
        if ((this->length != other.length) || (this->width != other.width))
        {
            return false;
        }
        for (int i = 0; i < this->width; ++i) {
                if(this->rows[i] != other.rows[i]){
                    return false;
            }
        }
        return true;
    }

	///////////////////////////////////// - Operators ///////////////////////////////////
	Matrix<T> operator-(Matrix<T> other)
	{
		if ((this->length != other.length) || (this->width != other.width))
		{
			throw "Error: dimensions do not match\n";
		}
		Matrix<T> m(this->width, this->length);
		for (int i = 0; i < this->width; i++)
		{
			m[i] = (this->rows[i]) - (other[i]);
		}
		m.det_calculated = false;
		return m;
	}

	///////////////////////////////////// * Operators ///////////////////////////////////
	///////////////////////////////////// * Operators ///////////////////////////////////
	Matrix<T> operator*(T scalar)
    {
	    Matrix<T> target(this);
        for (int i = 0; i < target.width; ++i) {
            target[i] = target[i] * scalar;
        }
        return target;
    }
    Matrix<T> StrssenAlgorithm(const Matrix<T>& other, bool is_first = 1)
    {
	    // last iteration
	    if(this->length == 1)
        {
	        Matrix<T> tmp(1);
	        tmp[0][0] = this->rows[0][0]*other[0][0];
	        return tmp;
        }
	    // if first iteration
	    if(is_first)
        {
            int newSize = pow(2,(ceil(log2(max(max(this->length, this->width), max(other.length, other.width))))));
            Matrix<T> A(newSize,newSize);
            Matrix<T> B(newSize,newSize);

            // initialize new matrix's
            for (int i = 0; i < this->width; ++i) {
                for (int j = 0; j < this->length; ++j) {
                    A[i][j] = this->rows[i][j];
                }
            }
            for (int i = 0; i < other.width; ++i) {
                for (int j = 0; j < other.length; ++j) {
                    B[i][j] = other[i][j];
                }
            }

            is_first = 0;
            A = A.StrssenAlgorithm(B, is_first);

            Matrix<T> sol(this->width, other.length);

            for (int i = 0; i < sol.width; ++i) {
                for (int j = 0; j < sol.length; ++j) {
                    sol[i][j] = A[i][j];
                }
            }

            return sol;
        }


        //strassen algorithem

        // initialize sub matrix's
        int sub_matrix_size = this->length / 2;
        Matrix<T> A11(sub_matrix_size);
        Matrix<T> A12(sub_matrix_size);
        Matrix<T> A21(sub_matrix_size);
        Matrix<T> A22(sub_matrix_size);
        Matrix<T> B11(sub_matrix_size);
        Matrix<T> B12(sub_matrix_size);
        Matrix<T> B21(sub_matrix_size);
        Matrix<T> B22(sub_matrix_size);

        for (int i = 0; i < this->length; ++i) {
            for (int j = 0; j < this->width; ++j) {
                if(i/sub_matrix_size == 0 && j/sub_matrix_size == 0)
                {
                    A11[i % sub_matrix_size][j % sub_matrix_size] = this->rows[i][j];
                    B11[i % sub_matrix_size][j % sub_matrix_size] = other[i][j];
                }
                if(i/sub_matrix_size == 0 && j/sub_matrix_size == 1)
                {
                    A12[i % sub_matrix_size][j % sub_matrix_size] = this->rows[i][j];
                    B12[i % sub_matrix_size][j % sub_matrix_size] = other[i][j];
                }
                if(i/sub_matrix_size == 1 && j/sub_matrix_size == 0)
                {
                    A21[i % sub_matrix_size][j % sub_matrix_size] = this->rows[i][j];
                    B21[i % sub_matrix_size][j % sub_matrix_size] = other[i][j];
                }
                if(i/sub_matrix_size == 1 && j/sub_matrix_size == 1)
                {
                    A22[i % sub_matrix_size][j % sub_matrix_size] = this->rows[i][j];
                    B22[i % sub_matrix_size][j % sub_matrix_size] = other[i][j];
                }
            }
        }

        Matrix<T> M1 = (A11 + A22).StrssenAlgorithm((B11 + B22), is_first);
        Matrix<T> M2 = (A21 + A22).StrssenAlgorithm(B11, is_first);
        Matrix<T> M3 = (A11).StrssenAlgorithm((B12 - B22), is_first);
        Matrix<T> M4 = (A22).StrssenAlgorithm((B21 - B11), is_first);
        Matrix<T> M5 = (A11 + A12).StrssenAlgorithm((B22), is_first);
        Matrix<T> M6 = (A21 - A11).StrssenAlgorithm((B11 + B12), is_first);
        Matrix<T> M7 = (A12 - A22).StrssenAlgorithm((B21 + B22), is_first);

        Matrix<T> C11(M1 + M4 - M5 + M7);
        Matrix<T> C12(M3 + M5);
        Matrix<T> C21(M2 + M4);
        Matrix<T> C22(M1 - M2 + M3 + M6);

        Matrix<T> res(this->length);

        for (int i = 0; i < this->length; ++i) {
            for(int j = 0; j < this->width; ++j){
                if(i/sub_matrix_size == 0 && j/sub_matrix_size == 0)
                {
                    res[i][j] = C11[i % sub_matrix_size][j % sub_matrix_size];
                }
                if(i/sub_matrix_size == 0 && j/sub_matrix_size == 1)
                {
                    res[i][j] = C12[i % sub_matrix_size][j % sub_matrix_size];
                }
                if(i/sub_matrix_size == 1 && j/sub_matrix_size == 0)
                {
                    res[i][j] = C21[i % sub_matrix_size][j % sub_matrix_size];
                }
                if(i/sub_matrix_size == 1 && j/sub_matrix_size == 1)
                {
                    res[i][j] = C22[i % sub_matrix_size][j % sub_matrix_size];
                }
            }
        }
        return res;
    }
	Matrix<T> operator*(const Matrix<T>& other)
	{
	    return this->StrssenAlgorithm(other);
		/*if (this->length != other.width)
		{
			throw "Error: dimensions do not match\n";
		}
		Matrix<T> temp = ~other;
		Matrix<T> m(this->width, other.length);

		for (int i = 0; i < this->width; i++)
			for (int j = 0; j < other.length; j++)
			{
				m[i][j] = this->rows[i] * temp[j];
			}
		if ((!this->det_calculated) || (!temp.det_calculated))
		{
			m.det_calculated = false;
		}
		else
		{
			m.det_calculated = true;
			m.det = this->det*temp.det;
		}
		return m;*/
	}

	///////////////////////////////////// Inverse Operator ///////////////////////////////////
	Matrix<T> operator~() const
	{
		Matrix<T> m(this->length, this->width);
		for (int i = 0; i < this->width; i++)
		{
			for (int j = 0; j < this->length; j++)
			{
				m[j][i] = this->rows[i][j];
			}
		}
		return m;
	}

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