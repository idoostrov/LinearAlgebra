#ifndef LLL_H
#define LLL_H

#include "Matrix.h"

Matrix& GramSchmidt(Matrix& M);
Matrix& LLL(Matrix& M, float delta);

#endif//LLL_H