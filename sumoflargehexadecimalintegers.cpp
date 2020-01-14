#include "sumoflargehexadecimalintegers.h"

SumOfLargeHexadecimalIntegers::SumOfLargeHexadecimalIntegers()
{
}

string SumOfLargeHexadecimalIntegers::solve(const string &s)
{
    ss.clear();
    ss << s;
    string tmp;

    short n[100] = {0};

    while (ss >> tmp)
    {
        if (tmp == "0")
            break;
        for (int i = static_cast<int>(tmp.size() - 1); i >= 0; i--)
            n[i] += transtoint(tmp[tmp.size() - i - 1]);
    }

    for (int i = 0; i < 99; i++)
    {
        n[i + 1] += n[i] / 16;
        n[i] %= 16;
    }

    int digit;
    for (digit = 99; digit >= 0 && n[digit] == 0; digit--)
        ;

    string ans;
    for (; digit >= 0; digit--)
        ans += transtochar(n[digit]);

    return ans;
}

short SumOfLargeHexadecimalIntegers::transtoint(const char &c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    return c - 'a' + 10;
}

char SumOfLargeHexadecimalIntegers::transtochar(const short &n)
{
    if (n >= 0 && n <= 9)
        return static_cast<char>(n + '0') ;
    return static_cast<char>(n + 'a' - 10);
}
