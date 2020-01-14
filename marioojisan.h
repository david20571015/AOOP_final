#ifndef MARIOOJISAN_H
#define MARIOOJISAN_H

#include "mymath.h"

class MarioOjisan : public MyMath
{
    stringstream ss;
    int n, result,maxn;
    int *coin = new int[100000000];
public:
    MarioOjisan();
    string solve(const string &);
    virtual ~MarioOjisan(){}
};

#endif // MARIOOJISAN_H
