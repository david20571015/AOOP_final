#ifndef MYTREE_H
#define MYTREE_H

#include "problemset.h"

class MyTree : public ProblemSet
{
public:
    MyTree();
    virtual ~MyTree();
    string solve(const string &) = 0;
};

#endif // MYTREE_H
