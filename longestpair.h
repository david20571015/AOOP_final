#ifndef LONGESTPAIR_H
#define LONGESTPAIR_H

#include"mymath.h"

class LongestPair : public MyMath
{
public:
    LongestPair();
    string solve(string);
    double distSqrt(double x,double y,double z)
    {
        return x*x+y*y+z*z;
    }
};

#endif // LONGESTPAIR_H
