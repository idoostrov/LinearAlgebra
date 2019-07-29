#ifndef LLL_H
#define LLL_H

#include "Matrix.h"
#include <gmp.h>
#include <gmpxx.h>
#include <math.h>


template <typename T>
Matrix<T> GramSchmidt(Matrix<T>& M);

Matrix<mpz_class>& LLL(Matrix<mpz_class>& mat, float delta);

#include "LLL.inl"

#endif//LLL_H