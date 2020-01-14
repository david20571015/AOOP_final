#ifndef SUMOFLARGEHEX_H
#define SUMOFLARGEHEX_H

#include "mymath.h"

class SumOfLargeHexadecimalIntegers : public MyMath
{
    stringstream ss;
public:
    SumOfLargeHexadecimalIntegers();
    string solve(const string &);
    inline short transtoint(const char &);
    inline char transtochar(const short &);
};

#endif // SUMOFLARGEHEX_H
