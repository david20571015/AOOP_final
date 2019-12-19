#ifndef BUILDING_H
#define BUILDING_H

#include "judge.h"
#include "judgewindow.h"
#include "data.h"
#include "floor.h"
#include "scheduler.h"

#include "problems.h"

#include <QTimer>
#include <bits/stdc++.h>

using namespace std;

struct Upload
{
    string Id1, Id2;
    string name1, name2;
    int pass, totalques, totalscore, timespent;
};

class Building:public QObject
{
    Q_OBJECT

public:
    Building();
    void run(int n);
    Data getData() { return data; }
    void startSimulation();
    void exportToDatabase();
    ~Building();

public slots:
    void update();

signals:
    void updateGUI();

private:
    int dest[27];
    int people[27];
    QTimer *simu_timer;
    Scheduler scheduler;
//    Judge judge;
    JudgeWindow judgewindow;
    Data data;
    Floor *floor[27];
    Upload upload[27];
};

#endif // BUILDING_H
