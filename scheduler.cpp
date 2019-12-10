#include "scheduler.h"

Scheduler::Scheduler()
{
//    nowFloor={1,3,4,6,9,10,8,7,5,2,0};
    nowFloor={14,14,14,14,14,14,14,14,14,14};
    index=0;
}

int Scheduler::getNowFloor()
{
    return nowFloor[index++];
}

void Scheduler::reset()
{
    index=0;
}
