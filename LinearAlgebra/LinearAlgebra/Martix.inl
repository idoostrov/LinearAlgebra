#include "Matrix.h"

template <class T>
void threadFunk(const Matrix<T>& M, const Matrix<T>& A, const Matrix<T>& B)
{
    M = A.StrssenAlgorithm(B);
}

template <class T>
Matrix<T> Matrix<T>::DistrebutedStrssenAlgorithm(const Matrix<T>& other)
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


    //strassen algorithem

    // initialize sub matrix's
    int sub_matrix_size = newSize / 2;
    Matrix<T> A11(sub_matrix_size);
    Matrix<T> A12(sub_matrix_size);
    Matrix<T> A21(sub_matrix_size);
    Matrix<T> A22(sub_matrix_size);
    Matrix<T> B11(sub_matrix_size);
    Matrix<T> B12(sub_matrix_size);
    Matrix<T> B21(sub_matrix_size);
    Matrix<T> B22(sub_matrix_size);

    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            if(i/sub_matrix_size == 0 && j/sub_matrix_size == 0)
            {
                A11[i % sub_matrix_size][j % sub_matrix_size] = A[i][j];
                B11[i % sub_matrix_size][j % sub_matrix_size] = B[i][j];
            }
            if(i/sub_matrix_size == 0 && j/sub_matrix_size == 1)
            {
                A12[i % sub_matrix_size][j % sub_matrix_size] = A[i][j];
                B12[i % sub_matrix_size][j % sub_matrix_size] = B[i][j];
            }
            if(i/sub_matrix_size == 1 && j/sub_matrix_size == 0)
            {
                A21[i % sub_matrix_size][j % sub_matrix_size] = A[i][j];
                B21[i % sub_matrix_size][j % sub_matrix_size] = B[i][j];
            }
            if(i/sub_matrix_size == 1 && j/sub_matrix_size == 1)
            {
                A22[i % sub_matrix_size][j % sub_matrix_size] = A[i][j];
                B22[i % sub_matrix_size][j % sub_matrix_size] = B[i][j];
            }
        }
    }

    // thread creation and Stressen distribution


    Matrix<T> M1(sub_matrix_size);
    Matrix<T> M2(sub_matrix_size);
    Matrix<T> M3(sub_matrix_size);
    Matrix<T> M4(sub_matrix_size);
    Matrix<T> M5(sub_matrix_size);
    Matrix<T> M6(sub_matrix_size);
    Matrix<T> M7(sub_matrix_size);

    thread t1(threadFunk, ref(M1), ref(A11 + A22),ref(B11 + B22));
    thread t2(threadFunk, M2, (A21 + A22),B11);
    thread t3(threadFunk, M3, A11,(B12 - B22));
    thread t4(threadFunk, M4, A22,(B21 - B11));
    thread t5(threadFunk, M5, (A11 + A12),B22);
    thread t6(threadFunk, M6, (A21 - A11),(B11 + B12));
    thread t7(threadFunk, M7, (A12 - A22),(B21 + B22));

    Matrix<T> C11(M1 + M4 - M5 + M7);
    Matrix<T> C12(M3 + M5);
    Matrix<T> C21(M2 + M4);
    Matrix<T> C22(M1 - M2 + M3 + M6);

    Matrix<T> res(this->width, other.length);

    for (int i = 0; i < this->width; ++i) {
        for(int j = 0; j < other.length; ++j){
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

template<class T>
int Matrix<T>::getLength() const {
    return this->length;
}

template<class T>
Matrix<T> Matrix<T>::operator*(T scalar) {
    Matrix<T> target(this);
    for (int i = 0; i < target.width; ++i) {
        target[i] = target[i] * scalar;
    }
    return target;
}

template<class T>
Matrix<T> Matrix<T>::operator~() const {
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

template<class T>
T Matrix<T>::deter() {
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

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> other) {
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

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) {
    return this->DistrebutedStrssenAlgorithm(other);
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

template<class T>
int Matrix<T>::getWidth() const {
    return this->width;
}

template<class T>
bool Matrix<T>::operator==(const Matrix<T> other) const {
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

template<class T>
void Matrix<T>::swap(int row1, int row2) {
    Array_Vector<T> temp = Array_Vector<T>(rows[row1]);
    rows[row1] = rows[row2];
    rows[row2] = temp;
}

template<class T>
T Matrix<T>::eliminate_col(int row, int col) {
    for (int i = row + 1; i < this->length; i++)
    {
        rows[i] = rows[i] * rows[row][col] - rows[row] * rows[i][col];
    }
    return T(pow(rows[row][col], this->length - row - 1));
}

template<class T>
T Matrix<T>::find_not_zero(int col, int start) {
    for (int i = start; i < this->length; i++)
    {
        if (this->rows[i][col] != 0)
        {
            return i;
        }
    }
    return -1;
}

template<class T>
Array_Vector<T> &Matrix<T>::operator[](int row) {
    if (row >= this->rows.size()) {
        throw "Error: index is too big\n";
    }
    this->det_calculated = false;
    return this->rows[row];
}

template<class T>
const Array_Vector<T> &Matrix<T>::operator[](int row) const {
    if (row >= this->rows.size()) {
        throw "Error: index is too big\n";
    }
    return this->rows[row];
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> other) {
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

template<class T>
Matrix<T> Matrix<T>::StrssenAlgorithm(const Matrix<T> &other, bool is_first) {
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