#ifndef MYOTHER_H
#define MYOTHER_H

#include"problemset.h"

class MyOther : public ProblemSet
{
public:
    MyOther();
    virtual ~MyOther();
    virtual string solve(string)=0;
};

#endif // MYOTHER_H
