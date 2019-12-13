#ifndef SHORTESTSUMMATIONDISTANCE_H
#define SHORTESTSUMMATIONDISTANCE_H

#include "mymath.h"

class ShortestSummationDistance : public MyMath
{
public:
    ShortestSummationDistance();
    string solve(const string &);
    double shortestDistance(vector<pair<int, int>> &);
private:
    vector<pair<int, int>> point;
};

#endif // SHORTESTSUMMATIONDISTANCE_H
