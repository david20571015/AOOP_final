#ifndef LARGEFACTORIAL_H
#define LARGEFACTORIAL_H

#include "mymath.h"

class LargeFactorial : public MyMath
{
    stringstream ss;
public:
    LargeFactorial();
    string solve(const string &);
};

#endif // LARGEFACTORIAL_H
