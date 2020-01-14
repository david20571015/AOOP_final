#ifndef SHYGAME_H
#define SHYGAME_H

#include<queue>

#include"mymath.h"

using namespace std;

class ShyGame:public MyMath
{
    stringstream ss;
    int n, p, st[100000], i, j, M;
public:
    ShyGame();
    string solve(const string &input);
};

#endif // SHYGAME_H
