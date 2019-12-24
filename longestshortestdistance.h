#ifndef LONGESTSHORTESTDISTANCE_H
#define LONGESTSHORTESTDISTANCE_H

#include "mydatabase.h"
#include <bits/stdc++.h>
#include <QSqlDatabase>
#include <QSqlQuery>

using namespace std;

class LongestShortestDistance: public MyDatabase
{
public:
    QSqlQuery query;
    LongestShortestDistance();
    string solve(const string &);
    virtual ~LongestShortestDistance(){}
};

#endif // LONGESTSHORTESTDISTANCE_H
