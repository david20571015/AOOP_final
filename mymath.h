#ifndef MYMATH_H
#define MYMATH_H

#include "problemset.h"

class MyMath : public ProblemSet
{
public:
    MyMath();
    virtual ~MyMath();
    string solve(string) = 0;

    template <class T>
    inline vector<T> stringToVector(const string &);

    template <class T>
    inline string vectorToString(const vector<T> &);

    bool isPrime(const int &);
    inline unsigned long long int pow_mod(const int &, const int &, const int &);
};

#endif // MYMATH_H
