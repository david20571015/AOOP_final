#include "distancebetweenprime.h"

DistanceBetweenPrime::DistanceBetweenPrime()
{
}

string DistanceBetweenPrime::solve(const string &s)
{
    ss.clear();
    ss<<s;
    int n, upperbound, lowerbound;
    string ans;
    while (ss >> n)
    {
        upperbound = n;
        lowerbound = n;
        while (!isPrime(upperbound++))
            ;
        while (!isPrime(lowerbound--))
            ;
        ans += to_string(upperbound - lowerbound - 2) + ' ';
    }

    ans.erase(ans.end() - 1);

    return ans;
}
