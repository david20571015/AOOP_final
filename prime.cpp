#include "prime.h"

#include<string>
#include<sstream>
#include<cmath>

Prime::Prime()
{
}

string Prime::solve(string s)
{
    stringstream ss;
    ss<<s;
    int n;
    string r;
    while(ss>>n)
        r+=(to_string(biggestPrime(n))+" ");
    return r;
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
    int s=static_cast<int>(sqrt(n));
    for(int i=2;i<s;i++)
        if(n%i==0)
            return 0;
    return 1;
}
