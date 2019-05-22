#ifndef LLL_H
#define LLL_H

#include "Matrix.h"

template <typename T>
Matrix<T>& GramSchmidt(Matrix<T>& M);

template <typename T>
Matrix<T>& LLL(Matrix<T>& M, float delta);

#include "LLL.inl"

#endif//LLL_H