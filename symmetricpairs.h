#ifndef SYMMETRICPAIRS_H
#define SYMMETRICPAIRS_H

#include "mydatabase.h"

using namespace std;

class SymmetricPairs: public MyDatabase
{
public:
    SymmetricPairs();
    string solve(const string &);
    virtual ~SymmetricPairs(){}
};

#endif // SYMMETRICPAIRS_H
