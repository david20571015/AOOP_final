#include "building.h"

Building::Building()
{
    judgewindow.show();
//    judgewindow.setSeed(0);
    int n=judgewindow.getConditionNum();
    simu_timer = new QTimer();
    connect(simu_timer,SIGNAL(timeout()),this,SLOT(update()));
    judgewindow.getInitial(dest,people);

    floor[0]  = new Floor(new P1);
    floor[1]  = new Floor(new P2);
    floor[2]  = new Floor(new P3);
    floor[3]  = new Floor(new P4);
    floor[4]  = new Floor(new P5);
    floor[5]  = new Floor(new P6);
    floor[6]  = new Floor(new P7);
    floor[7]  = new Floor(new P8);
    floor[8]  = new Floor(new P9);
    floor[9]  = new Floor(new P10);
    floor[10] = new Floor(new P11);
    floor[11] = new Floor(new P12);
    floor[12] = new Floor(new P13);
    floor[13] = new Floor(new P14);
    floor[14] = new Floor(new P15);
    floor[15] = new Floor(new P16);
    floor[16] = new Floor(new P17);
    floor[17] = new Floor(new P18);
    floor[18] = new Floor(new P19);
    floor[19] = new Floor(new P20);
    floor[20] = new Floor(new P21);
    floor[21] = new Floor(new P22);
    floor[22] = new Floor(new P23);
    floor[23] = new Floor(new P24);
    floor[24] = new Floor(new P25);
    floor[25] = new Floor(new P26);
    floor[26] = new Floor(new P27);
}

void Building::run(int n)
{
    data.testdata = judgewindow.getData(n, 1);
    data.submit = floor[n-1]->p->solve(data.testdata);
    data.correct = judgewindow.submitData(data.submit);
    data.spendtime = judgewindow.getSpendTime();
}

void Building::startSimulation()
{
    simu_timer->start(100);
    simu_timer->setSingleShot(1);
    data.elevatorpeople=0;
    data.distance=0;
    scheduler.setInitial(dest,people);
    scheduler.calRoute();
}

void Building::update()
{
    simu_timer->start(100);
    data.elevatorpeople+=(scheduler.getNowFloor().second*2-1);
    data.distance+=abs(data.nowfloor-scheduler.getNowFloor().first);
    data.nowfloor=scheduler.getNowFloor().first;

    if(data.nowfloor)
    {
        run(data.nowfloor);
        judgewindow.update(data.nowfloor,data.spendtime,data.correct,scheduler.getNowFloor().second);
        scheduler.nextFloor();
    }
    else
        simu_timer->stop();

    emit this->updateGUI();
}

Building::~Building()
{
    for (int i = 0; i < 27; i++)
        delete floor[i];
}
