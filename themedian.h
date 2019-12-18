#ifndef THEMEDIAN_H
#define THEMEDIAN_H

#include "mydatabase.h"
#include "mydatabase.h"
#include <bits/stdc++.h>
#include <QSqlDatabase>
#include <QSqlQuery>

using namespace std;

class TheMedian: public MyDatabase
{
    stringstream ss;
    string t3, t4, t5, st, asc = "asc";
    int t1, t2;

public:
    QSqlQuery query;
    TheMedian();
    string solve(const string &);
    virtual ~TheMedian(){}
};

#endif // THEMEDIAN_H
