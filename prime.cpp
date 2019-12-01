#include "prime.h"

Prime::Prime()
{}

string Prime::solve(string s)
{
    vector<int> input=stringtoVectorInt(s);
    for(auto &i:input)
        i=biggestPrime(i);

    return vectorIntToString(input);
}

inline int Prime::biggestPrime(const int &n)
{
    for(int i=n;i>=1;i--)
        if(isPrime(i))
            return i;
    return 0;
}

inline bool Prime::isPrime(const int &n)
{
    if(n==1)
        return 0;
    if((n==2)||(n==3))
        return 1;
    int s=static_cast<int>(sqrt(n)+1);
    for(int i=2;i<s;i++)
        if(n%i==0)
            return 0;
    return 1;
}
