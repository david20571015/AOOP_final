#ifndef LARGESTROOT_H
#define LARGESTROOT_H

#include "mytree.h"

class LargestRoot : public MyTree
{
public:
    LargestRoot();
    string solve(const string &);

protected:
    double node[15];
    double value[15];
};

#endif // LARGESTROOT_H
