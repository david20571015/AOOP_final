#ifndef MYOTHER_H
#define MYOTHER_H

#include "problemset.h"

class MyOther : public ProblemSet
{
public:
    MyOther();
    virtual ~MyOther();
    string solve(const string &) = 0;
};

#endif // MYOTHER_H
