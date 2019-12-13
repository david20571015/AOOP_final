#include "subtract1.h"

Subtract1::Subtract1()
{

}

string Subtract1::solve(const string &s)
{
    stringstream ss;
    ss<<s;
    int n;
    string ans;
    while(ss>>n)
        ans+=to_string(n-1)+' ';

    ans.erase(ans.end()-1);

    return ans;
}
