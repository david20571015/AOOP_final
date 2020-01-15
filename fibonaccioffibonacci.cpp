#include "fibonaccioffibonacci.h"

FibonacciOfFibonacci::FibonacciOfFibonacci()
{
}

string FibonacciOfFibonacci::solve(const string &s)
{
    digit[0] = 0;
    digit[1] = 1;
    for (int i = 2; i < 60; i++)
        digit[i] = (digit[i - 1] + digit[i - 2]) % 10;

    ss.clear();
    ss << s;

    string ans;
    int n;
    while (ss >> n)
        ans += to_string(digit[fib(n)]) + ' ';

    ans.erase(ans.end() - 1);
    return ans;
}

long long int FibonacciOfFibonacci::fib(int &n)
{
    long long int sum1 = 0, sum2 = 1, sum3 = 0;
    n %= 60;
    if (n == 0)
        return sum1;
    if (n == 1)
        return sum2;
    for (int i = 2; i <= n; i++)
    {
        sum3 = (sum1 + sum2);
        sum1 = sum2;
        sum2 = (sum3 - 60 >= 0) ? (sum3 -= 60) : sum3;
    }
    return sum3;
}
