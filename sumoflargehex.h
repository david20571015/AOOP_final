#ifndef SUMOFLARGEHEX_H
#define SUMOFLARGEHEX_H

#include"mymath.h"

class SumOfLargeHex : public MyMath
{
public:
    SumOfLargeHex();
    string solve(string);
    int transtoint(char);
    char transtochar(int);
};

#endif // SUMOFLARGEHEX_H
