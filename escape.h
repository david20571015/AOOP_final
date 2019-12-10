#ifndef ESCAPE_H
#define ESCAPE_H

#include"myother.h"

class Escape : public MyOther
{
public:
    Escape();
    virtual ~Escape();
    string solve(string);
};

#endif // ESCAPE_H
