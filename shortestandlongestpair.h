#ifndef SHORTESTSUMMATION_H
#define SHORTESTSUMMATION_H

#include "mymath.h"

class ShortestAndLongestPair : public MyMath
{
public:
    ShortestAndLongestPair();
    string solve(string);
    double distance(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return sqrt((p1.first - p2.first) * (p1.first - p2.first)
                    + (p1.second - p2.second) * (p1.second - p2.second));
    }
    double shortestDistance(vector<pair<int, int>> &);
private:
    vector<pair<int, int>> point;
    double dist;
    bool label[20];
    int count;
};

#endif // SHORTESTSUMMATION_H
