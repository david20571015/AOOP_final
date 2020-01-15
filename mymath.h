#ifndef MYMATH_H
#define MYMATH_H

#include "problemset.h"

class MyMath : public ProblemSet
{
public:
    MyMath();
    virtual ~MyMath();
    string solve(const string &) = 0;
    bool isPrime(const int &);
};

#endif // MYMATH_H
