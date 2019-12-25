#ifndef MYSTRING_H
#define MYSTRING_H

#include "problemset.h"

class MyString : public ProblemSet
{
public:
    MyString();
    virtual ~MyString();
    string solve(const string &) = 0;
    string preProcess(const string &s)
    {
        string tmp = s;
        int punct_pos;
        while ((punct_pos = tmp.find_first_of(",.?!")) != string::npos)
            tmp.erase(tmp.begin() + punct_pos);
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
        return tmp;
    }
};

#endif // MYSTRING_H
