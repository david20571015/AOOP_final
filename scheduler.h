#ifndef SCHEDULER_H
#define SCHEDULER_H

#include<bits/stdc++.h>
#include <QDebug>
using namespace std;

class Scheduler
{
public:
    Scheduler();
    pair<int,int> getNowFloor();
    void nextFloor();
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
    vector<pair<int,int>> nowFloor;
    int index;
};

#endif // SCHEDULER_H
