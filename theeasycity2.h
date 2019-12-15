#ifndef TheEasyCity2_H
#define TheEasyCity2_H

#include"mydatabase.h"
#include<string>
#include<sstream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<iomanip>

using namespace std;

class TheEasyCity2:public MyDatabase
{

    stringstream ss;
    string t, t1,t2, t3, t4, t5, t6, st, lar = "lar";
    int n;

public:
    QSqlQuery query;
    TheEasyCity2();
    virtual ~TheEasyCity2();
    string solve(const string &);
};

#endif // TheEasyCity2_H
