#ifndef MARIOOJISAN_H
#define MARIOOJISAN_H

#include "mymath.h"

class MarioOjisan : public MyMath
{
public:
    MarioOjisan();
    string solve(const string &);
    virtual ~MarioOjisan(){}
};

#endif // MARIOOJISAN_H
