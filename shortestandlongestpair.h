#ifndef SHORTESTSUMMATION_H
#define SHORTESTSUMMATION_H

#include "mymath.h"

class ShortestAndLongestPair : public MyMath
{
public:
    ShortestAndLongestPair();
    string solve(const string &);
private:
    stringstream ss;
    double dx, dy, dz, dis;
    double x[10000],y[10000],z[10000];
};

#endif // SHORTESTSUMMATION_H
