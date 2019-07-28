//
// Created by ido_o on 23-Jul-19.
//

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

using namespace std;

// modInverse code credit: https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
mpz_class modInverse(mpz_class a, mpz_class m)
{
    mpz_class m0 = m;
    mpz_class y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        // q is quotient
        mpz_class q = a / m;
        mpz_class t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

mpz_class p = 1000000002217; //unknown
mpz_class q = 999999995207; //unknown
mpz_class N = p*q; //known
mpz_class phi = (p-1)*(q-1); //unknown
mpz_class e = 65537; //known
mpz_class d = modInverse(e,phi); //unknown

unsigned int k = 10; // length of the key in bytes
mpz_class B = mpz_class(1) << (8*(k-1)); // the approximate size of the key without the first byte


// modpow's code credit: https://stackoverflow.com/questions/8496182/calculating-powa-b-mod-n
mpz_class modpow(mpz_class base, mpz_class exp, mpz_class modulus) {
    base %= modulus;
    mpz_class result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}



int Manger_Oracle(mpz_class c)
{
    mpz_class res = modpow(c, d, N);
    return (res >> ((k-1)*8)) == 0;
}

mpz_class step1(mpz_class c, int& number_of_oracle_calls) //returns f1 such that m*f1/2 is in the interval [B/2, B)
{
    mpz_class f1 = rand() % N;
    while(Manger_Oracle((modpow(f1,e,N)*c)) && number_of_oracle_calls--)
    {
        f1 *= 2;
        //f1 = rand() % N;
    }
    return f1;
}

mpz_class step2(mpz_class c, mpz_class f1, int& number_of_oracle_calls) // returns f2 such that f2*m is in the interval [N, N+B)
{
    mpz_class f2 = ((N+B)/B) * f1/2; // f2*m is in the interval [N/2, N+B)
    while(Manger_Oracle(((modpow(f2,e,N)*c))) == 0 && number_of_oracle_calls--)
    {

        // if reached here, then f2*m is in the interval [N/2, N)

        f2 += f1/2; // the new f2 value is in the interval [N/2, n+B)
    }
    return f2;
}

tuple<mpz_class , mpz_class> step3(mpz_class c, mpz_class f2, int& number_of_oracle_calls) // returns lower bound on m and f3 such that m*f3 is in a small range
{
    mpz_class m_min = N/f2;
    if(N % f2 != 0)
        m_min++;
    mpz_class m_max = (N+B) / f2;
    mpz_class f_tmp;
    mpz_class i;
    mpz_class f3;

    while(m_max - m_min >= 1 && number_of_oracle_calls--)
    {
        f_tmp = 2*B / (m_max - m_min);
        i = (f_tmp * m_min) / N;

        //find f3 such that f3*m is in the interval [i*N, i*N+2B)
        f3 = (i*N) / m_min;
        if((i*N) % m_min != 0)
            f3 ++;

        if(Manger_Oracle(modpow(f3,e,N)*c)) //meaning f3*m is in [i*N, i*N+B)
        {
            m_max = (i*N+B) / f3;
        }
        else // f3*m is in [i*N+B, i*N+2B)
        {
            m_min = (i * N + B) / f3;
            if ((i * N + B) % f3 != 0)
                m_min++;
        }
    }
    tuple<mpz_class, mpz_class> tup(m_min, f3);
    return tup;

}

tuple<mpz_class , mpz_class> MangerAttack(mpz_class c, int number_of_oracle_calls)
{
    int copy_number_of_oracle_calls = number_of_oracle_calls;
    mpz_class f1 = step1(c, ref(copy_number_of_oracle_calls));
    mpz_class f2 = step2(c, f1, ref(copy_number_of_oracle_calls));
    return step3(c, f2, ref(copy_number_of_oracle_calls));
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void ThreadHandle(int oracle_calls, mpz_class cipher, int i, Matrix<mpz_class>& m)
{
    srand(time(0) + i);
    tuple<mpz_class, mpz_class> tup = MangerAttack(cipher, oracle_calls);
    mpz_class a = get<0>(tup);
    mpz_class s = get<1>(tup);

    m[0][i] = s;
    m[i+1][i] = N;
    m[m.getLength()-1][i] = a;
}

mpz_class ParallelizedMangerAttack(int thread_count, int oracle_calls, mpz_class cipher)
{
    Matrix<mpz_class> matrix(thread_count + 2, thread_count + 2);
    vector<thread> threads(thread_count);
    for (int i = 0; i < thread_count; ++i)
    {
        threads[i] = thread(ThreadHandle, oracle_calls, cipher, i, ref(matrix));
    }
    for (int i = 0; i < thread_count; ++i)
    {
        threads[i].join();
    }
    mpz_class s1 = matrix[0][0] ;
    mpz_class a1 = matrix[0][thread_count + 1];

    //matrix = matrix * thread_count;
    matrix[thread_count + 1][thread_count] = N*(thread_count - 1) / thread_count;

    cout << matrix;

    matrix = LLL(matrix, 0.75);
    cout << matrix;

    mpz_class r1 = matrix[1][0];
    return ((r1+a1)*modInverse(s1, N)) % N;
}


int main()
{
    mpz_class a = ParallelizedMangerAttack(3, 60, modpow(mpz_class(1000932335), e,N));
    //mpz_class m = 1000932335;
    //cout << get<0>(MangerAttack(modpow(m,e,N), 76)) << endl;
    cout << a << endl;
    return 0;
}
