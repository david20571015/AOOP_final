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

//bool MyMath::isPrime(const int &n)
//{
//    if (n == 2)
//        return true;
//    if (n == 1 || (n & 1) == 0)
//        return false;

//    int u = n - 1, t = 0;
//    while ((u & 1) == 0)
//    {
//        u >>= 1;
//        t++;
//    }

//    int sprp[3] = {2, 7, 61};
//    for (int k = 0; k < 3; k++)
//    {
//        int a = sprp[k] % n;
//        if(a == 0 || a == 1 || a== n-1)
//            continue;

//        unsigned long long int x = pow_mod(a, u, n);
//        if (x == 1 || x == n - 1)
//            continue;

//        for (int i = 0; i < t - 1; i++)
//        {
//            x = (x * x ) % n;
//            if (x == n - 1)
//                break;
//        }
//        if (x == n - 1)
//            continue;

//        return false;
//    }
//    return true;
//}

bool MyMath::isPrime(const int &n)
{
    if(n==1)
        return 0;
    if((n==2)||(n==3))
        return 1;
    int s=static_cast<int>(sqrt(n)+1);
    for(int i=2;i<s;i++)
        if(n%i==0)
            return 0;
    return 1;
}

inline unsigned long long int MyMath::pow_mod(const int &k, const int &n, const int &m)
{
    if (n == 0)
        return 1;
    unsigned long long int halfResult = pow_mod(k, n / 2, m);
    if (n & 1)
        return (halfResult * halfResult * k) % m;
    return (halfResult * halfResult) % m;
}
