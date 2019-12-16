#ifndef THEEASYCITY1_H
#define THEEASYCITY1_H

#include "mydatabase.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <string>
#include <sstream>

using namespace std;

class TheEasyCity1: public MyDatabase
{
    stringstream ss;
    string st, t1, t2, t3, t4, t5, t6, t7, ev = "ev", even = "even", asc = "asc";

public:
    QSqlQuery query;
    TheEasyCity1();
    string solve(const string &);
    virtual ~TheEasyCity1(){}
};

#endif // THEEASYCITY1_H
