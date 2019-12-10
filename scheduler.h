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

private:
    vector<int> nowFloor;
    int index;
};

#endif // SCHEDULER_H
