#include "fibonaccioffibonacci.h"

FibonacciOfFibonacci::FibonacciOfFibonacci()
{
    digit[0] = 0;
    digit[1] = 1;
    for (int i = 2; i < 60; i++)
        digit[i] = (digit[i - 1] + digit[i - 2]) % 10;
}

string FibonacciOfFibonacci::solve(string s)
{
    vector<int> n = stringtoVectorInt(s);
    string ans;
    for (int i = 0; i < n.size(); i++)
        ans += to_string(digit[fib(n[i]) % 60]) + ' ';

    ans.erase(ans.end() - 1);
    return ans;
}

long long int FibonacciOfFibonacci::fib(int n)
{
    long long int sum1 = 0, sum2 = 1, sum3 = 0;
    if (n == 0)
        return sum1;
    if (n == 1)
        return sum2;
    for (int i = 2; i <= n; i++)
    {
        sum3 = (sum1 + sum2) % 60;
        sum1 = sum2 % 60;
        sum2 = sum3 % 60;
    }
    return sum3;
}
