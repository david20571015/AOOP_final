#include "add1.h"

#include<string>
#include<sstream>

Add1::Add1()
{
}

string Add1::solve(string s)
{
    stringstream ss;
    ss<<s;
    int n;
    string r;
    while(ss>>n)
        r+=(to_string(n+1)+" ");
    return r;
}
