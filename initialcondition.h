#ifndef INITIALCONDITION_H
#define INITIALCONDITION_H
#include<bits/stdc++.h>

using namespace std;

class InitialCondition
{
public:
    string Id;
    int Nowfloor;
    int Dest;
    int Number;
    InitialCondition();
    void setCondition(string s, int a, int b, int d);
    int getNowfloor(){return Nowfloor;}
};

#endif // INITIALCONDITION_H
