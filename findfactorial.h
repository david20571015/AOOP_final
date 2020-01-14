#ifndef FINDFACTORIAL_H
#define FINDFACTORIAL_H

#include "mymath.h"

class FindFactorial : public MyMath
{
    stringstream ss;
public:
    FindFactorial();
    string solve(const string &);
    int numberOfPrime(long long int &);
};

#endif // FINDFACTORIAL_H
