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
    double a[10][10];
    double b[10];
};

#endif // GETSOLUTION_H
