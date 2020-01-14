#include "findfactorial.h"

FindFactorial::FindFactorial()
{
}

string FindFactorial::solve(const string &s)
{
    ss.clear();
    ss<<s;
    string ans;
    vector<int>v;
    int n,count=2,i,index,j;
    int prime[100];
    prime[0]=2;
    prime[1]=3;
    for(i=5;i<=541;i+=2)
        if(isPrime(i))
            prime[count++]=i;

    while(ss>>n)
        v.push_back(n);

    for(i=0;i<v.size();i++)
    {
        count=0;
        index=2;
        j=0;
        while(count<v[i])
        {
            n=index;
            while(index!=1)
            {
                if(index%prime[j]==0)
                {
                    index/=prime[j];
                    count++;
                }
                else
                    j++;
            }
            index=n+1;
            j=0;

        }
        if(count==v[i])
            ans+=to_string(index-1)+"! ";
        else
            ans+="N ";
    }
    ans.erase(ans.end()-1);
    return ans;
}
