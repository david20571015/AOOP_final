#ifndef SYMMETRICPAIRS_H
#define SYMMETRICPAIRS_H

#include "mydatabase.h"
#include <bits/stdc++.h>
#include <QSqlDatabase>
#include <QSqlQuery>

using namespace std;

class SymmetricPairs: public MyDatabase
{
    string t1, t2, t3, od = "od";
    int n4;
    stringstream ss;
public:
    QSqlQuery query;
    SymmetricPairs();
    string solve(const string &);
    virtual ~SymmetricPairs(){}
};

#endif // SYMMETRICPAIRS_H
