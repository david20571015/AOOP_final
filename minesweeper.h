#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "myother.h"

class Minesweeper : public MyOther
{
public:
    Minesweeper();
    string solve(const string &);

private:
    stringstream ss;
};

#endif // MINESWEEPER_H
