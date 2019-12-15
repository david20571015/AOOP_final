#ifndef LONGESTCOMMONSUBSTRING_H
#define LONGESTCOMMONSUBSTRING_H

#include"mystring.h"

class LongestCommonSubstring : public MyString
{
public:
    LongestCommonSubstring();
    string solve(const string &);
    virtual ~LongestCommonSubstring(){}
};

#endif // LONGESTCOMMONSUBSTRING_H
