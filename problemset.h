#ifndef PROBLEMSET_H
#define PROBLEMSET_H

#include<string>

using namespace std;

class ProblemSet
{
public:
    ProblemSet();
    virtual ~ProblemSet();
    virtual string solve(string s);
};

#endif // PROBLEMSET_H
