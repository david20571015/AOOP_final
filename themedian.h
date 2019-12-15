#ifndef THEMEDIAN_H
#define THEMEDIAN_H

#include "mydatabase.h"

using namespace std;

class TheMedian: public MyDatabase
{
public:
    TheMedian();
    string solve(const string &);
    virtual ~TheMedian(){}
};

#endif // THEMEDIAN_H
