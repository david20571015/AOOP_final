#include "prime.h"

Prime::Prime()
{
}

string Prime::solve(string s)
{
    vector<int> input = stringtoVectorInt(s);
    for (auto &i : input)
        i = biggestPrime(i);

    return vectorIntToString(input);
}

inline int Prime::biggestPrime(const int &n)
{
    for (int i = n; i >= 1; i--)
        if (isPrime(i))
            return i;
    return 0;
}
