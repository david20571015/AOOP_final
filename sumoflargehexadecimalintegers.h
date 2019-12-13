#ifndef SUMOFLARGEHEX_H
#define SUMOFLARGEHEX_H

#include "mymath.h"

class SumOfLargeHexadecimalIntegers : public MyMath
{
public:
    SumOfLargeHexadecimalIntegers();
    string solve(const string &);
    inline int transtoint(char);
    inline char transtochar(int);
};

#endif // SUMOFLARGEHEX_H
