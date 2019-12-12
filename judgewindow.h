#ifndef JUDGEWINDOW_H
#define JUDGEWINDOW_H

#include <QWidget>
#include <QElapsedTimer>
#include <QLineEdit>

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
    void setSeed(int seed){srand(static_cast<unsigned int>(seed));}
    qint64 getSpendTime(){return costtime;}
    int getConditionNum();
    int getDistance(){return distance;}
    void scheduleEnd();
    ~JudgeWindow();

private:
    QLineEdit showline[27][4];
    int score;
    int distance;
    int floor;
    int numOfCorr;
    int numOfQues;
    fstream time;
    string answer;
    QElapsedTimer timer;
    qint64 costtime;
    Ui::JudgeWindow *ui;
};

#endif // JUDGEWINDOW_H
