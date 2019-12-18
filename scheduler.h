#ifndef SCHEDULER_H
#define SCHEDULER_H

#include<bits/stdc++.h>
using namespace std;

class Scheduler
{
public:
    Scheduler();
    int getNowFloor();
    void reset();
    void setInitial(int [27],int [27]);
    void calRoute();

private:
    struct Group
    {
        int from;
        int to;
        int num;
    };
    vector<Group> up,down;
    vector<int> nowFloor;
    int index;
};

#endif // SCHEDULER_H
