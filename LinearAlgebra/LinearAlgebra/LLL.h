
#ifndef LLL_H
#define LLL_H

#include "Matrix.h"
#include <gmp.h>
#include <gmpxx.h>
#include <math.h>


/*
template <typename T>
Matrix<T> GramSchmidt(Matrix<T>& M);

Matrix<mpz_class>& LLL(Matrix<mpz_class>& mat, float delta);
*/

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
mpz_class mpz_round(mpq_class mpq);

/**
 * Preforms LLL Algorithm
 * recives a matrix mat and return a matrix thet its rows are the shortest vetors in the lattice of the original rows
 * @param mat
 * @param delta
 * @return a matrix that its rows are redced vetors in the lattice of the original rows
 */
Matrix<mpz_class>& LLL(Matrix<mpz_class>& mat, float delta);


#endif //LLL_H
