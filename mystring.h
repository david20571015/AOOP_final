#ifndef MYSTRING_H
#define MYSTRING_H

#include "problemset.h"

class MyString : public ProblemSet
{
public:
    MyString();
    virtual ~MyString();
    string solve(const string &) = 0;
};

#endif // MYSTRING_H
