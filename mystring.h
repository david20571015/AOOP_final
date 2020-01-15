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
        for (string::iterator i = s.begin(); i != s.end(); i++)
                (*i) = toupper(*i);
    }
};

#endif // MYSTRING_H
