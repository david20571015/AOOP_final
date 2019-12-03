#include "distancebetweenprime.h"

DistanceBetweenPrime::DistanceBetweenPrime()
{

}

string DistanceBetweenPrime::solve(string s)
{
    stringstream ss;
    ss<<s;
    int n,upperbound,lowerbound;
    string ans;
    while(ss>>n)
    {
        upperbound=n;
        lowerbound=n;
        while(!isPrime(upperbound++));
        while(!isPrime(lowerbound--));
        ans+=to_string(upperbound-lowerbound-2)+' ';
    }

    ans.erase(ans.end()-1);

    return ans;
}

//inline bool DistanceBetweenPrime::isPrime(const int &n)
//{
//    if(n==1)
//        return 0;
//    if((n==2)||(n==3))
//        return 1;
//    int s=static_cast<int>(sqrt(n)+1);
//    for(int i=2;i<s;i++)
//        if(n%i==0)
//            return 0;
//    return 1;
//}
