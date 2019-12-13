#include "mymath.h"

MyMath::MyMath()
{
}

MyMath::~MyMath()
{
}

template <class T>
inline vector<T> MyMath::stringToVector(const string &s)
{
    vector<T> v;
    stringstream ss;
    ss<<s;
    T n;
    while (ss>>n)
        v.push_back(n);
    return v;
}

template <class T>
inline string MyMath::vectorToString(const vector<T> &v)
{
    string s;
    for(typename vector<T>::const_iterator i = v.cbegin(); i != v.cend(); i++)
        s+= to_string(*i)+ ' ';
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
    if (n == 1)
        return 0;
    if ((n == 2) || (n == 3))
        return 1;
    int s = static_cast<int>(sqrt(n) + 1);
    for (int i = 2; i < s; i++)
        if (n % i == 0)
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
