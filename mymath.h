#ifndef MYMATH_H
#define MYMATH_H

#include "problemset.h"

class MyMath : public ProblemSet
{
public:
    MyMath();
    virtual ~MyMath();
    string solve(const string &) = 0;
    bool isPrime(const int &n)
    {
        if ((n & 1) == 0 && n != 2)
            return false;
        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0)
                return false;
        return true;
    }
};

#endif // MYMATH_H
