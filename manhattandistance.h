#ifndef MANHATTANDISTANCE_H
#define MANHATTANDISTANCE_H

#include "mydatabase.h"
#include <bits/stdc++.h>
#include <QSqlDatabase>
#include <QSqlQuery>

using namespace std;

class ManhattanDistance : public MyDatabase
{
    stringstream ss;
    string t3, t4, st;
    int t1, t2;

public:
    QSqlQuery query;
    ManhattanDistance();
    string solve(const string &);
    virtual ~ManhattanDistance() {}
};

#endif // MANHATTANDISTANCE_H
