#ifndef GETSIGNATURE_H
#define GETSIGNATURE_H

#include "myother.h"

class GetSignature : public MyOther
{
    stringstream ss;
public:
    GetSignature();
    string solve(const string &);
    virtual ~GetSignature(){}
};

#endif // GETSIGNATURE_H
