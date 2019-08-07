#include "LLL.h"

/**
 * preforms the Gram shmidt Algorithm
 * recives a matrix m and returns a new matrix thet the rows are orthogonal and in the span of the original rows
 * @tparam T
 * @param m
 * @return a new matrix thet the rows are orthogonal and in the span of the original rows
 */
template <typename T>
Matrix<T> GramSchmidt(Matrix<T>& m)
{
    Matrix<T> M(m);
    for(int i=0; i<M.getWidth(); i++)
    {
        Array_Vector<T> v(M[i]);
        for(int j=0; j<i; j++)
        {
            if(M[j].get_norm_squared() != 0)
                v = v - (M[j] * (M[j]*M[i] / M[j].get_norm_squared()));
        }
        M[i] = v;
    }
    return M;
}

/**
 * recived a number mpq
 * @param mpq
 * @return rowndws up the number
 */
mpz_class mpz_round(mpq_class mpq)
{
    mpz_class num, den, tmp;
    num = mpq.get_num();
    den = mpq.get_den();
    tmp = num/den;
    if(mpq > tmp)
    {
        if(mpq - tmp < 0.5)
            return tmp;
        else
            return tmp + 1;
    }
    else
    {
        if(tmp - mpq < 0.5)
            return tmp;
        return tmp - 1;
    }
}

/**
 * Preforms LLL Algorithm
 * recives a matrix mat and return a matrix thet its rows are the shortest vetors in the lattice of the original rows
 * @param mat
 * @param delta
 * @return a matrix that its rows are redced vetors in the lattice of the original rows
 */
Matrix<mpz_class>& LLL(Matrix<mpz_class>& mat, float delta)
{
    Matrix<mpq_class> M(mat.getWidth(), mat.getLength());
    for (int i = 0; i < mat.getWidth(); ++i)
    {
        for (int j = 0; j < mat.getLength(); ++j)
        {
            M[i][j] = mat[i][j];
        }
    }

    Matrix<mpq_class> ortho(M);
    ortho = GramSchmidt(ortho);

    int k = 1;
    while(k < M.getWidth()) {
        for (int j = k - 1; j >= 0; j--) {
            if (ortho[j].get_norm_squared() != 0) {
                if (abs((M[k] * ortho[j])) / ortho[j].get_norm_squared() > 0.5) {
                    M[k] = M[k] - M[j] * mpz_round((M[k] * ortho[j]) / ortho[j].get_norm_squared());
                    //M[k] = M[k] - M[j]*((M[k]*ortho[j])/ ortho[j].get_norm_squared());
                    ortho = GramSchmidt(M);
                }
            }
        }
        if (ortho[k - 1].get_norm_squared() != 0)
        {
            if (ortho[k].get_norm_squared() >= (delta - (M[k] * ortho[k - 1] / ortho[k - 1].get_norm_squared()) *
                                                        (M[k] * ortho[k - 1] / ortho[k - 1].get_norm_squared())) *
                                               (ortho[k - 1].get_norm_squared()))
                k++;
            else {
                M.swap(k, k - 1);
                ortho = GramSchmidt(M);
                k = max(k - 1, 1);
            }
        } else
            k++;

    }
    for (int i = 0; i < mat.getWidth(); ++i)
    {
        for (int j = 0; j < mat.getLength(); ++j)
        {
            mat[i][j] = M[i][j];
        }
    }
    return mat;
    
}

