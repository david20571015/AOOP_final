#ifndef MYMATH_H
#define MYMATH_H

#include<problemset.h>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

class MyMath : public ProblemSet
{
public:
//    MyMath();
    string solve(string);
    vector<int>stringtoVectorInt(string);
    string vectorIntToString(vector<int>);
};

#endif // MYMATH_H
