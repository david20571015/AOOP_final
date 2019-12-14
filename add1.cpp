#include "add1.h"

Add1::Add1()
{
}

string Add1::solve(const string &s)
{
    stringstream ss;
    ss<<s;
    int n;
    string ans;
    while(ss>>n)
        ans+=to_string(n+1)+' ';

    ans.erase(ans.end()-1);

    return ans;
}
