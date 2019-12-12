#include "building.h"

Building::Building()
{
    judgewindow = new JudgeWindow();
    judgewindow->show();
    judgewindow->setSeed(0);
    int n=judgewindow->getConditionNum();
    simu_timer = new QTimer();
    connect(simu_timer,SIGNAL(timeout()),this,SLOT(update()));

//    floor[1]=new Floor(new Add1());
//    floor[2]=new Floor(new Add1());
//    floor[3]=new Floor(new Add1());
//    floor[4]=new Floor(new Add1());
//    floor[5]=new Floor(new Add1());
//    floor[6]=new Floor(new Add1());
//    floor[7]=new Floor(new Add1());
//    floor[8]=new Floor(new Add1());
//    floor[9]=new Floor(new Add1());
//    floor[10]=new Floor(new Add1());
    floor[0] = new Floor(new Add1());
    floor[1] = new Floor(new Prime());
    floor[2] = new Floor(new LongestPair());
    floor[3] = new Floor(new ShyGame());
    floor[4] = new Floor(new FibonacciOfFibonacci());
    floor[5] = new Floor(new Minesweeper());
    floor[6] = new Floor(new LargestRoot());
    floor[8] = new Floor(new findfactorial());
    floor[9] = new Floor(new shortestsummation());
    floor[10] = new Floor(new FindThePeriodOfString());
    floor[11] = new Floor(new LargeFactorial());
    floor[12] = new Floor(new SumOfLargeHex());
    floor[13] = new Floor(new DistanceBetweenPrime());
    floor[14] = new Floor(new Escape());
}

void Building::run(int n)
{
    data.testdata = judge.getData(n);
    data.submit = floor[n]->p->solve(data.testdata);
    data.correct = judgewindow->submitData(data.submit);
    data.spendtime = judgewindow->getSpendTime();
    data.score = judge.getScore();
    data.distance = judgewindow->getDistance();
}

void Building::startSimulation()
{
    simu_timer->start(100);
    simu_timer->setSingleShot(1);
}

void Building::update()
{
    simu_timer->start(100);
    data.nowfloor=scheduler.getNowFloor();
    if(data.nowfloor)
        run(data.nowfloor);
    else
        simu_timer->stop();
    emit this->updateGUI();
}

Building::~Building()
{
    for (int i = 0; i < 30; i++)
        delete floor[i];
}
