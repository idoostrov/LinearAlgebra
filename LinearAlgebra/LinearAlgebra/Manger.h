//
// Created by talth on 08/08/2019.
//

#ifndef LINEARALGEBRA_MANGER_H
#define LINEARALGEBRA_MANGER_H

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <tuple>
#include <thread>
#include <vector>
#include "Matrix.h"
#include "LLL.h"
#include <gmp.h>
#include <gmpxx.h>
#include <time.h>

///////////////////////////Main Functions/////////////////////////////
tuple<mpz_class , mpz_class> MangerAttack(mpz_class c, int number_of_oracle_calls, int seed);
mpz_class ParallelizedMangerAttack(int thread_count, int oracle_calls, mpz_class cipher);
void mangerTests();

///////////////////////////Side Channel Functions/////////////////////////
mpz_class modInverse(mpz_class a, mpz_class m);
mpz_class modpow(mpz_class base, mpz_class exp, mpz_class modulus);
int Manger_Oracle(mpz_class c);
mpz_class blinding(mpz_class c, int& number_of_oracle_calls, int seed);
mpz_class step1(mpz_class c, int& number_of_oracle_calls);
mpz_class step2(mpz_class c, mpz_class f1, int& number_of_oracle_calls);
mpz_class step3(mpz_class c, mpz_class f2, int& number_of_oracle_calls);
void ThreadHandle(int oracle_calls, mpz_class cipher, int i, Matrix<mpz_class>& m);

#endif //LINEARALGEBRA_MANGER_H
