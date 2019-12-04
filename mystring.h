#ifndef MYSTRING_H
#define MYSTRING_H

#include "problemset.h"

class MyString : public ProblemSet
{
public:
    MyString();
    virtual ~MyString();
    virtual string solve(string) = 0;
};

#endif // MYSTRING_H
