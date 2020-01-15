#include "findfactorial.h"

FindFactorial::FindFactorial()
{
}

string FindFactorial::solve(const string &s)
{
    ss.clear();
    ss << s;
    string ans;

    int n, count = 2, i, index, j, tmp;
    int prime[100];
    prime[0] = 2;
    prime[1] = 3;
    for (i = 5; i <= 541; i += 2)
        if (isPrime(i))
            prime[count++] = i;

    while (ss >> n)
    {
        count = 0;
        index = 2;
        j = 0;
        while (count < n)
        {
            tmp = index;
            while (index != 1)
            {
                if (index % prime[j] == 0)
                {
                    index /= prime[j];
                    count++;
                }
                else
                    j++;
            }
            index = tmp + 1;
            j = 0;
        }
        if (count == n)
            ans += to_string(index - 1) + "! ";
        else
            ans += "N ";
    }
    ans.erase(ans.end() - 1);
    return ans;
}
