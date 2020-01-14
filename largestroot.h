#ifndef LARGESTROOT_H
#define LARGESTROOT_H

#include "mytree.h"

class LargestRoot : public MyTree
{
public:
    LargestRoot();
    string solve(const string &);

private:
    stringstream ss;
    double node[15];
    double value[15];
};

#endif // LARGESTROOT_H
