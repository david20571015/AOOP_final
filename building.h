#ifndef BUILDING_H
#define BUILDING_H

#include "judge.h"
#include "data.h"
#include "floor.h"
#include "scheduler.h"

#include "problems.h"

#include <QTimer>
#include <string>

class Building:public QObject
{
    Q_OBJECT

public:
    Building();
    void run(int n);
    Data getData() { return data; }
    void startSimulation();
    ~Building();

public slots:
    void update();

signals:
    void updateGUI();

private:
    QTimer *simu_timer;
    Scheduler scheduler;
    Judge judge;
    Data data;
    Floor *floor[30];
};

#endif // BUILDING_H
