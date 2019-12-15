#ifndef THEEASYCITY1_H
#define THEEASYCITY1_H

#include "mydatabase.h"

using namespace std;

class TheEasyCity1: public MyDatabase
{
public:
    TheEasyCity1();
    string solve(const string &);
    virtual ~TheEasyCity1(){}
};

#endif // THEEASYCITY1_H
