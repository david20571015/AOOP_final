#ifndef PROBLEMSET_H
#define PROBLEMSET_H

#include <bits/stdc++.h>
#include <QDebug>

using namespace std;

class ProblemSet
{
public:
    ProblemSet();
    virtual ~ProblemSet();
    virtual string solve(const string &) = 0;
};

#endif // PROBLEMSET_H
