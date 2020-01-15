#include "findfactorial.h"

FindFactorial::FindFactorial()
{
}

string FindFactorial::solve(const string &s)
{
    ss.clear();
    ss << s;

    int prime_factors = 0;
    int fac_num = 1;
    int fac_tmp;
    string ans;
    int num;
    while (ss >> num)
    {
        prime_factors = 0;
        fac_num = 1;
        while (prime_factors < num)
        {
            fac_tmp = ++fac_num;
            if (isPrime(fac_tmp))
                prime_factors++;
            else
                for (int j = 2; j <= fac_tmp; j++)
                    while (isPrime(j) && fac_tmp % j == 0)
                    {
                        prime_factors++;
                        fac_tmp /= j;
                    }
        }
        ans += (num == prime_factors ? to_string(fac_num) + "! " : "N ");
    }
    ans.erase(ans.end() - 1);
    return ans;
}

