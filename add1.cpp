#include "add1.h"

#include<string>
#include<sstream>

string Add1::solve(string s)
{
/*    stringstream ss;
    ss<<s;
    int n;
    string r;
    while(ss>>n)
        r+=(to_string(n+1)+" ");
    r.erase(r.end()-1);
*/
    vector<int> input=stringtoVectorInt(s);
    for(auto &i:input)
        i+=1;

    return vectorIntToString(input);
}
