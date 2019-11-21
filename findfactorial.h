#ifndef FINDFACTORIAL_H
#define FINDFACTORIAL_H

#include"mymath.h"

class findfactorial : public MyMath
{
public:
    findfactorial();
    string solve(string);
    int numberOfPrime(long long int &);
    bool isPrime(const int &);
};

#endif // FINDFACTORIAL_H
