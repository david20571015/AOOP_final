#include "findfactorial.h"

findfactorial::findfactorial()
{
}

string findfactorial::solve(string s)
{
    vector<double> n = stringtoVectorDouble(s);
    string ans;
    for (int i = 0; i < static_cast<int>(n.size()); i++)
    {
        for (long long int f = 1;; f++)
        {
            if (numberOfPrime(f) == n[i])
            {
                ans += to_string(f) + "! ";
                break;
            }
            else if (numberOfPrime(f) > n[i])
            {
                ans += "N ";
                break;
            }
        }
    }
    ans.erase(ans.end() - 1);
    return ans;
}

int findfactorial::numberOfPrime(long long int &n)
{
    int sum = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            for (int r = 1; r <= n; r++)
            {
                sum += static_cast<int>(floor(n / pow(i, r)));
                if (floor(n / pow(i, r)) == 0)
                    break;
            }
        }
    }
    return sum;
}

bool findfactorial::isPrime(const int &n)
{
    if (n == 1)
        return 0;
    if ((n == 2) || (n == 3))
        return 1;
    int s = static_cast<int>(sqrt(n) + 1);
    for (int i = 2; i < s; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
