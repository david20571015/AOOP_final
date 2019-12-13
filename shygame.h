#ifndef SHYGAME_H
#define SHYGAME_H

#include "mymath.h"

using namespace std;

class ShyGame : public MyMath
{
public:
    ShyGame();
    string solve(const string &);
};

#endif // SHYGAME_H
