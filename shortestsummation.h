#ifndef SHORTESTSUMMATION_H
#define SHORTESTSUMMATION_H

#include"mymath.h"
#include"QDebug"

class shortestsummation:public MyMath
{
public:
    shortestsummation();
    string solve(string);
    double distance(int x,int y)
    {return sqrt(x*x+y*y);}
    double shortestDistance(vector<int> &,vector<int> &);
};

#endif // SHORTESTSUMMATION_H
