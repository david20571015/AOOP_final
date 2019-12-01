#ifndef MYMATH_H
#define MYMATH_H

#include"problemset.h"

using namespace std;

class MyMath : public ProblemSet
{
public:
    MyMath();
    virtual ~MyMath();
    virtual string solve(string)=0;
    vector<int>stringtoVectorInt(string);
    string vectorIntToString(vector<int>);
    vector<double>stringtoVectorDouble(string);
    string vectorDoubleToString(vector<double>);
};

#endif // MYMATH_H
