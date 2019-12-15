#ifndef MANHATTANDISTANCE_H
#define MANHATTANDISTANCE_H

#include "mydatabase.h"

using namespace std;

class ManhattanDistance: public MyDatabase
{
public:
    ManhattanDistance();
    string solve(const string &);
    virtual ~ManhattanDistance(){}
};

#endif // MANHATTANDISTANCE_H
