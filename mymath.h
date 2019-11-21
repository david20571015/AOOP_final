#ifndef MYMATH_H
#define MYMATH_H

#include<problemset.h>
#include<vector>
#include<sstream>
#include<cmath>
#include<iomanip>

using namespace std;

class MyMath : public ProblemSet
{
public:
    MyMath();
    virtual ~MyMath();
    string solve(string);
    vector<int>stringtoVectorInt(string);
    string vectorIntToString(vector<int>);
    vector<double>stringtoVectorDouble(string);
    string vectorDoubleToString(vector<double>);
};

#endif // MYMATH_H
