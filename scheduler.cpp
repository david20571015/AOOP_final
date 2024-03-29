#include "scheduler.h"

Scheduler::Scheduler()
{
    index=0;
}

void Scheduler::setInitial(int *dest, int *people)
{
    for(int i=0;i<27;i++)
    {
        if(i+1<dest[i])
            up.push_back(Group{i+1,dest[i],people[i]});
        else if(i+1>dest[i])
            down.push_back(Group{i+1,dest[i],people[i]});
        reverse(down.begin(),down.end());
    }
//    qDebug()<<"upfloor:";
//    for(int i=0;i<up.size();i++)
//        qDebug()<<up[i].from<<' '<<up[i].to<<' '<<up[i].num;
//    qDebug()<<"downfloor:";
//    for(int i=0;i<down.size();i++)
//        qDebug()<<down[i].from<<' '<<down[i].to<<' '<<down[i].num;
}

void Scheduler::calRoute()
{
//    qDebug()<<"calRoute begin";
    vector<Group> elevator;
    int peopleInElevator=0;
    int now;

    while(up.size()||down.size())
    {
        now=1;
        while (now<=27)
        {
            //leave
            for(int i=0;i<elevator.size();i++)
            {
                if(elevator[i].to==now)
                {
                    peopleInElevator-=elevator[i].num;
                    for(int j=0;j<elevator[i].num;j++)
                        nowFloor.push_back(make_pair(now,0));
                    elevator.erase(elevator.begin()+i);
                }
            }

            //enter
            for(int i=0;i<up.size();i++)
            {
                if(up[i].from==now&&peopleInElevator<10)
                {
                    int n=min(up[i].num,10-peopleInElevator);
                    peopleInElevator+=n;
                    elevator.push_back(Group{now,up[i].to,n});
                    for(int j=0;j<n;j++)
                        nowFloor.push_back(make_pair(now,1));
                    up[i].num-=n;
                    if(up[i].num==0)
                        up.erase(up.begin()+i);
                }
            }
            now++;
        }

        now=27;
        while (now>=1)
        {
            //leave
            for(int i=0;i<elevator.size();i++)
            {
                if(elevator[i].to==now)
                {
                    peopleInElevator-=elevator[i].num;
                    for(int j=0;j<elevator[i].num;j++)
                        nowFloor.push_back(make_pair(now,0));
                    elevator.erase(elevator.begin()+i);
                }
            }

            //enter
            for(int i=0;i<down.size();i++)
            {
                if(down[i].from==now&&peopleInElevator<10)
                {
                    int n=min(down[i].num,10-peopleInElevator);
                    peopleInElevator+=n;
                    elevator.push_back(Group{now,down[i].to,n});
                    for(int j=0;j<n;j++)
                        nowFloor.push_back(make_pair(now,1));
                    down[i].num-=n;
                    if(down[i].num==0)
                        down.erase(down.begin()+i);
                }
            }
            now--;
        }
    }
    nowFloor.push_back(make_pair(0,0));

//    qDebug()<<"calRoute end";
//    for(auto i:nowFloor)
//    qDebug()<<i.first;
}

pair<int,int> Scheduler::getNowFloor()
{
    return nowFloor[index];
}

void Scheduler::nextFloor()
{
    index++;
}

void Scheduler::reset()
{
    index=0;
}
