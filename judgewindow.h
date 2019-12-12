#ifndef JUDGEWINDOW_H
#define JUDGEWINDOW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<bits/stdc++.h>
#include "initialcondition.h"
using namespace std;

namespace Ui {
class JudgeWindow;
}

class JudgeWindow : public QWidget
{
    Q_OBJECT
    QSqlQuery query;
public:
    explicit JudgeWindow(QWidget *parent = nullptr);
    string getData(int floor,int b);
    bool submitData(string ans);
    void setSeed(int seed){srand(seed);}
    qint64 getSpendTime(){return costtime;}
    int getConditionNum();
    int getDistance(){return distance;}
    void scheduleEnd();
    ~JudgeWindow();

private:
    string ans;
    qint64 costtime;
    int distance;
    int conditionNum;
    InitialCondition condition[27];
    Ui::JudgeWindow *ui;
};

#endif // JUDGEWINDOW_H
