#ifndef SHORTESTSUMMATION_H
#define SHORTESTSUMMATION_H

#include "mymath.h"

struct Point{
    double x,y,z;
};

class ShortestAndLongestPair : public MyMath
{
public:
    ShortestAndLongestPair();
    string solve(const string &);
    double sqrtOfDis(const Point &p1,const Point &p2)
    {
        return (p1.x-p2.x)*(p1.x-p2.x)+ (p1.y-p2.y)*(p1.y-p2.y)+ (p1.z-p2.z)*(p1.z-p2.z);
    }
private:

};

#endif // SHORTESTSUMMATION_H
