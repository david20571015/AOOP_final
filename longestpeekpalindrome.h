#ifndef LONGESTPEEKPALINDROME_H
#define LONGESTPEEKPALINDROME_H

#include"mystring.h"

class LongestPeekPalindrome : public MyString
{
    int L[500];
public:
    LongestPeekPalindrome();
    string solve(const string &);
    string findLongestPalindromicString(const string &);
    virtual ~LongestPeekPalindrome(){}
};

#endif // LONGESTPEEKPALINDROME_H
