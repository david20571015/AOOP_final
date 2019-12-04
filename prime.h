#ifndef PRIME_H
#define PRIME_H

#include "mymath.h"

class Prime : public MyMath
{
public:
    Prime();
    string solve(string);
    inline int biggestPrime(const int &);
};

#endif // PRIME_H
