#ifndef FINDFACTORIAL_H
#define FINDFACTORIAL_H

#include "mymath.h"

class FindFactorial : public MyMath
{
    stringstream ss;

public:
    FindFactorial();
    string solve(const string &);
};

#endif // FINDFACTORIAL_H
