#ifndef GETSIGNATURE_H
#define GETSIGNATURE_H

#include "myother.h"

class GetSignature : public MyOther
{
    stringstream ss;
    int v[50000];
    int asktosign[50000];
    bool check[50000];
    bool from[50000];
public:
    GetSignature();
    string solve(const string &);
    virtual ~GetSignature(){}
};

#endif // GETSIGNATURE_H
