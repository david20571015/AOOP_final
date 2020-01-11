#ifndef MYSTRING_H
#define MYSTRING_H

#include "problemset.h"

class MyString : public ProblemSet
{
public:
    MyString();
    virtual ~MyString();
    string solve(const string &) = 0;
    void preProcess(string &s)
    {
        unsigned long long punct_pos;
        while ((punct_pos = s.find_first_of(",.?!")) != string::npos)
            s.erase(s.begin() + punct_pos);
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    }
};

#endif // MYSTRING_H
