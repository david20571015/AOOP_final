#ifndef FINDFACTORIAL_H
#define FINDFACTORIAL_H

#include "mymath.h"

class FindFactorial : public MyMath
{
public:
    FindFactorial();
    string solve(string);
    int numberOfPrime(long long int &);
    bool isPrime(const int &);
};

#endif // FINDFACTORIAL_H
