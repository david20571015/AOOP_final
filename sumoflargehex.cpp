#include "sumoflargehex.h"

SumOfLargeHex::SumOfLargeHex()
{
}

string SumOfLargeHex::solve(string s)
{
    stringstream ss;
    string tmp;
    ss << s;

    int n[30] = {0};

    while (ss >> tmp)
    {
        if (tmp == "0")
            break;
        for (int i = tmp.size() - 1; i >= 0; i--)
            n[i] += transtoint(tmp[tmp.size() - i - 1]);
    }

    for (int i = 0; i < 29; i++)
    {
        n[i + 1] += n[i] / 16;
        n[i] %= 16;
    }

    int digit;
    for (digit = 29; digit >= 0; digit--)
        if (n[digit] != 0)
            break;

    string ans;
    for (; digit >= 0; digit--)
        ans += transtochar(n[digit]);

    return ans;
}

int SumOfLargeHex::transtoint(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    return c - 'a' + 10;
}

char SumOfLargeHex::transtochar(int n)
{
    if (n >= 0 && n <= 9)
        return n + '0';
    return n + 'a' - 10;
}
