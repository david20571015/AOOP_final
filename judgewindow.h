#ifndef JUDGEWINDOW_H
#define JUDGEWINDOW_H

#include <QWidget>

#include<bits/stdc++.h>
using namespace std;

namespace Ui {
class JudgeWindow;
}

class JudgeWindow : public QWidget
{
    Q_OBJECT

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
    qint64 costtime;
    int distance;
    Ui::JudgeWindow *ui;
};

#endif // JUDGEWINDOW_H
