#ifndef FLOOR_H
#define FLOOR_H

#include"problemset.h"

class Floor
{
public:
    Floor();
    ~Floor(){delete p;}
    Floor(ProblemSet *problem){this->p=problem;}
    void setProblem(ProblemSet *problem){this->p=problem;}
    ProblemSet *p;

private:
    int fn;
};

#endif // FLOOR_H
