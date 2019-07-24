//
// Created by ido_o on 23-Jul-19.
//

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <tuple>

using namespace std;

unsigned long p = 33083; //unknown
unsigned long q = 33637; //unknown
unsigned long e = 5; //known
unsigned long d = 445098461; //unknown
unsigned long N = p*q; //known
unsigned long phi = (p-1)*(q-1); //unknown

unsigned int k = 4; // length of the key in bytes
unsigned long B = ulong(1) << (8*(k-1)); // the approximate size of the key without the first byte

int NUMBER_OF_ORACLE_CALLS = -1;



// modpow's code credit: https://stackoverflow.com/questions/8496182/calculating-powa-b-mod-n
template <typename T>
T modpow(T base, T exp, T modulus) {
    base %= modulus;
    T result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}



int Manger_Oracle(unsigned long c)
{
    unsigned long res = modpow(c, d, N);
    return (res >> ((k-1)*8)) == 0;
}

unsigned long step1(unsigned long c) //returns f1 such that m*f1/2 is in the interval [B/2, B)
{
    unsigned long f1 = 2;
    while(Manger_Oracle((modpow(f1,e,N)*c)) && NUMBER_OF_ORACLE_CALLS--)
    {
        f1 *= 2;
    }
    return f1;
}

unsigned long step2(unsigned long c, unsigned long f1) // returns f2 such that f2*m is in the interval [n, n+B)
{
    unsigned long f2 = ((N+B)/B) * f1/2; // f2*m is in the interval [n/2, n+B)
    while(Manger_Oracle(((modpow(f2,e,N)*c))) == 0 && NUMBER_OF_ORACLE_CALLS--)
    {

        // if reached here, then f2*m is in the interval [n/2, n)

        f2 += f1/2; // the new f2 value is in the interval [n/2, n+B)
    }
    return f2;
}

tuple<unsigned long , unsigned long> step3(unsigned long c, unsigned long f2) // returns lower bound on m and f3 such that m*f3 is in a small range
{
    unsigned long m_min = N/f2;
    if(N % f2 != 0)
        m_min++;
    unsigned long m_max = (N+B) / f2;
    unsigned long f_tmp;
    unsigned long i;
    unsigned long f3;

    while(m_max - m_min >= 1 && NUMBER_OF_ORACLE_CALLS--)
    {
        f_tmp = 2*B / (m_max - m_min);
        i = (f_tmp * m_min) / N;

        //find f3 such that f3*m is in the interval [i*n, i*n+2B)
        f3 = (i*N) / m_min;
        if((i*N) % m_min != 0)
            f3 ++;

        if(Manger_Oracle(modpow(f3,e,N)*c)) //meaning f3*m is in [i*n, i*n+B)
        {
            m_max = (i*N+B) / f3;
        }
        else //meaning f3*m is in [i*n+B, i*n+2B)
        {
            m_min = (i * N + B) / f3;
            if ((i * N + B) % f3 != 0)
                m_min++;
        }
    }
    tuple<unsigned long, unsigned long> tup(m_min, f3);
    return tup;

}

tuple<unsigned long , unsigned long> MangerAttack(unsigned long c)
{
    NUMBER_OF_ORACLE_CALLS = -1;
    unsigned long f1 = step1(c);
    unsigned long f2 = step2(c, f1);
    return step3(c, f2);
}

int main()
{
    cout << get<0>(MangerAttack(modpow(ulong(900),e,N))) << std::endl;
}