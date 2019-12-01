#include "add1.h"

Add1::Add1()
{

}

string Add1::solve(string s)
{
    vector<int> input=stringtoVectorInt(s);
    for(auto &i:input)
        i+=1;

    return vectorIntToString(input);
}
