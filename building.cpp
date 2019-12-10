#include "building.h"

Building::Building()
{
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
    string s = judge.getData(n);
    data.testdata = s;
    string s2 = floor[n]->p->solve(s);
    data.submit = s2;
    bool correct = judge.submitData(s2);
    data.correct = correct;
    data.spendtime = judge.getSpendTime();
    data.score=judge.getScore();
}

void Building::startSimulation()
{
    simu_timer->start(1000);
    scheduler.reset();
}

void Building::update()
{
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
