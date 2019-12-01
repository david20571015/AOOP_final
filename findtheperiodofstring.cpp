#include "findtheperiodofstring.h"

FindThePeriodOfString::FindThePeriodOfString()
{
}

string FindThePeriodOfString::solve(string s)
{


    for(int i=1;i<=static_cast<int>(s.size());i++)
    {
        if(static_cast<int>(s.size())%i)
            continue;

        bool flag=1;
        for(int j=0;j<static_cast<int>(s.size());j+=i)
        {
            if(s.substr(j,i)!=s.substr(0,i))
                flag=0;
        }
        if(flag)
            return to_string(i);
    }
    return to_string(s.size());
}

