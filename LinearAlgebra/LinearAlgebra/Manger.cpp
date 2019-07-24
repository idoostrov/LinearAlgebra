//
// Created by ido_o on 23-Jul-19.
//

#include <stdlib.h>
#include <iostream>

unsigned long p = 33083;
unsigned long q = 33637;
unsigned long e = 5;
unsigned long d = 445098461; //YEAHHHHH!!!!!1111
unsigned long N = p*q;
unsigned long phi = (p-1)*(q-1);

//code credit: https://stackoverflow.com/questions/8496182/calculating-powa-b-mod-n
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
    long res = modpow(c, d, N);
    return (res >> 40) == 0;
}

int main()
{
    std::cout << (d*e)%phi << std::endl;
    std::cout << modpow(ulong(5), ulong(6), ulong(23)) << std::endl;
    std::cout << modpow(ulong(10),d*e,N) << std::endl;
    std::cout << modpow(modpow(ulong(10),d,N),e,N) << std::endl;
    std::cout << Manger_Oracle(modpow(ulong(10),e,N)) << std::endl;

    return 0;
}