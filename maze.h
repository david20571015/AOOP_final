#ifndef MAZE_H
#define MAZE_H

#include"myother.h"

class Maze : public MyOther
{
public:
    Maze();
    string solve(const string &);
    virtual ~Maze(){}
};

#endif // MAZE_H
