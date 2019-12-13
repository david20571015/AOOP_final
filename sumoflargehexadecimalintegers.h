#ifndef SUMOFLARGEHEX_H
#define SUMOFLARGEHEX_H

#include "mymath.h"

class SumOfLargeHexadecimalIntegers : public MyMath
{
public:
    SumOfLargeHexadecimalIntegers();
    string solve(string);
    int transtoint(char);
    char transtochar(int);
};

#endif // SUMOFLARGEHEX_H
