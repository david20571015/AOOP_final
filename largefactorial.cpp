#include "largefactorial.h"

LargeFactorial::LargeFactorial()
{
}

string LargeFactorial::solve(const string &s)
{
    stringstream ss;
    short n;
    ss << s;
    ss >> n;

    unsigned long long fac[2400] = {0};

    fac[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 2399; j++)
            fac[j] *= i;
        for (int j = 0; j < 2399; j++)
            if (fac[j] >= 1e15)
            {
                fac[j + 1] += fac[j] / (unsigned long long)1e15;
                fac[j] %= (unsigned long long)1e15;
            }
    }

    int digit = 2399;
    for (; digit >= 0 && !fac[digit]; digit--)
        ;
    stringstream tmp;
    string ans;

    for (; digit >= 0; digit--)
        tmp << fixed << setfill('0') << setw(15) << fac[digit];

    tmp >> ans;

    for (digit = 0; digit < ans.size() && ans[digit] == '0'; digit++)
        ;
    ans = ans.substr(digit, ans.size() - digit);

    return ans;
}
