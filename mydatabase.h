#ifndef MYDATABASE_H
#define MYDATABASE_H
#include"problemset.h"

class MyDatabase:public ProblemSet
{
public:
    MyDatabase();
    virtual ~MyDatabase(){}
    string solve(const string &)=0;
};

#endif // MYDATABASE_H
