#ifndef JUDGEWINDOW_H
#define JUDGEWINDOW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QElapsedTimer>
#include <QElapsedTimer>
#include <QLineEdit>
#include<QCheckBox>
#include <QDebug>

#include <bits/stdc++.h>
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
    string getData(int floor,int b,int &datatimes);
    bool submitData(string ans);
    void setSeed(int seed){srand(static_cast<unsigned int>(seed));}
    qint64 getSpendTime(){return costtime;}
    int getConditionNum();
    void getInitial(int *,int *);
    int getDistance(){return distance;}
    void scheduleEnd();
    void update(int,qint64,bool,bool);
    void uploadToDB();
    ~JudgeWindow();
    int arrive[27];
    int uploadistance;

private:
    QCheckBox giveup[27];
    int population;
    qint64 costtime;
    qint64 totaltime[27];
    int correct[27];
    int distance;
    int conditionNum;
    QElapsedTimer timer; 
    InitialCondition condition[27];
    QLineEdit showline[27][4];
    long long score;
    int floor;
    int numOfCorr;
    int numOfQues;
    fstream time;
    string answer;
    int floordatatimes[27];
    int floornextdata[27];
    Ui::JudgeWindow *ui;

    struct Upload
    {
        string Id1, Id2;
        string name1, name2;
        int pass, totalques;
        long long totalscore, timespent;
    }upload[27];
};

#endif // JUDGEWINDOW_H
