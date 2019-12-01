#include "mymath.h"

MyMath::MyMath()
{}

MyMath::~MyMath()
{}

vector<int> MyMath::stringtoVectorInt(string s)
{
    vector<int> v;
    stringstream ss;
    ss<<s;
    int n;
    while(ss>>n)
        v.push_back(n);
    return v;
}

string MyMath::vectorIntToString(vector<int> v)
{
    string s;
    for(vector<int>::const_iterator i=v.cbegin();i!=v.cend();i++)
        s+=to_string(*i)+" ";
    s.erase(s.end()-1);

    return s;
}

vector<double> MyMath::stringtoVectorDouble(string s)
{
    vector<double> v;
    stringstream ss;
    ss<<s;
    double n;
    while(ss>>n)
        v.push_back(n);
    return v;
}

string MyMath::vectorDoubleToString(vector<double> v)
{
    string s;
    for(vector<double>::const_iterator i=v.cbegin();i!=v.cend();i++)
        s+=to_string(*i)+" ";
    s.erase(s.end()-1);

    return s;
}
