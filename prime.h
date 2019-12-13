#ifndef PRIME_H
#define PRIME_H

#include "mymath.h"

class Prime : public MyMath
{
public:
    Prime();
    string solve(const string &);
    inline int biggestPrime(const int &);
};

#endif // PRIME_H
