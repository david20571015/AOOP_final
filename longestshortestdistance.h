#ifndef LONGESTSHORTESTDISTANCE_H
#define LONGESTSHORTESTDISTANCE_H

#include "mydatabase.h"

using namespace std;

class LongestShortestDistance: public MyDatabase
{
public:
    LongestShortestDistance();
    string solve(const string &);
    virtual ~LongestShortestDistance(){}
};

#endif // LONGESTSHORTESTDISTANCE_H
