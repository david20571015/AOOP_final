#ifndef DISTANCEBETWEENPRIME_H
#define DISTANCEBETWEENPRIME_H

#include "mymath.h"

class DistanceBetweenPrime : public MyMath
{
    stringstream ss;
public:
    DistanceBetweenPrime();
    string solve(const string &);
};

#endif // DISTANCEBETWEENPRIME_H
