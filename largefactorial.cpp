#include "largefactorial.h"

LargeFactorial::LargeFactorial()
{
}

string LargeFactorial::solve(const string &s)
{

    int n = stoi(s);
    int *num = new int[2000];
    for (int i = 0; i < 2000; i++)
        num[i] = 0;
    num[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2000; j++)
            num[j] *= i;
        for (int j = 0; j < 1999; j++)
        {
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
        }
    }

    int digit;
    for (digit = 1999; digit >= 0; digit--)
        if (num[digit] != 0)
            break;

    string ans;
    for (; digit >= 0; digit--)
        ans += to_string(num[digit]);
    delete[] num;
    return ans;
}
