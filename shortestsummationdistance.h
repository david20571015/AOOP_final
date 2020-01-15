#ifndef SHORTESTSUMMATIONDISTANCE_H
#define SHORTESTSUMMATIONDISTANCE_H

#include "mymath.h"

class ShortestSummationDistance : public MyMath
{
public:
    ShortestSummationDistance();
    string solve(const string &);

private:
    stringstream ss;
    int x[100],y[100];
};

#endif // SHORTESTSUMMATIONDISTANCE_H
