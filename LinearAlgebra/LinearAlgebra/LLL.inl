#include "LLL.h"
#include <math.h>
#include <gmp.h>
#include <gmpxx.h>

template <typename T>
Matrix<T> GramSchmidt(Matrix<T>& m)
{
    Matrix<T> M(m);
    for(int i=0; i<M.getWidth(); i++)
    {
        Array_Vector<T> v(M[i]);
        for(int j=0; j<i; j++)
        {
            v = v - (M[j] * (M[j]*M[i] / M[j].get_norm_squared()));
        }
        M[i] = v;
    }
    return M;
}

mpz_class mpz_floor(mpq_class mpq)
{
    mpz_class num, den;
    num = mpq.get_num();
    den = mpq.get_den();
    return num/den;
}

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
    while(k < M.getWidth())
    {
        for(int j = k-1; j>=0; j--)
        {
            if(abs((M[k]*ortho[j]))/ ortho[j].get_norm_squared() > 0.5)
            {
                M[k] = M[k] - M[j]*mpz_floor((M[k]*ortho[j])/ ortho[j].get_norm_squared());
                ortho = GramSchmidt(M);
            }
        }
        if(ortho[k].get_norm_squared() >= (delta - (M[k]*ortho[k-1]/ortho[k-1].get_norm_squared())*(M[k]*ortho[k-1]/ortho[k-1].get_norm_squared()))*(ortho[k-1].get_norm_squared()))
            k++;
        else
        {
            M.swap(k, k-1);
            ortho = GramSchmidt(M);
            k = max(k-1, 1);
        }
        
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

