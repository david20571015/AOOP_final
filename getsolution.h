#ifndef GETSOLUTION_H
#define GETSOLUTION_H

#include "mymath.h"

class GetSolution : public MyMath
{
public:
    GetSolution();
    string solve(const string &);
    virtual ~GetSolution(){}
private:
    stringstream ss;
    int n;
    double a[10][11];
};

#endif // GETSOLUTION_H
