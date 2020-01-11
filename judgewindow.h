#ifndef JUDGEWINDOW_H
#define JUDGEWINDOW_H

#include <QDebug>
#include <QElapsedTimer>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QRandomGenerator>

#include <string>
#include <vector>
#include <map>

//#include <people.h>

#define FLOORNUMBER     27
#define ELEVATORLIMIT   10

namespace Ui {
class JudgeWindow;
}

struct Performance{
    Performance(){}
    Performance(int c, qint64 ctime) : correctness(c), costtime(ctime){}
    int correctness;
    qint64 costtime;
};

using namespace std;
class JudgeWindow : public QWidget
{
    Q_OBJECT

public:

    explicit JudgeWindow(QWidget *parent = nullptr);
    ~JudgeWindow();

    string getData(int floorindex, int b, int& times);
    //floorindex : 0~26, b=(0,1):(出電梯,進電梯)
    bool submitData(string);

    qint64 getSpendTime(){return costtime;}
    QSqlDatabase& getDatabase(){return db;}
    //get intial condition by db from this function
    int getConditionNum(){return conditionNum;}
    int getDistance(){return distance;}
    int getElevatorPeople(){return this->elevactorPeople;}

    void scheduleEnd();
    //necessary to call this function when simulation is over

private slots:
    void on_pushButton_clicked();

private:

    Ui::JudgeWindow *ui;
    QLineEdit *showline[FLOORNUMBER][4];
    QLabel *eleplace[FLOORNUMBER];
    QCheckBox *giveupbox[FLOORNUMBER];

    QRandomGenerator random;
    QElapsedTimer timer;
    QSqlDatabase db;

    const quint32 globalseed;
    quint32 floorseed[FLOORNUMBER];

    int conditionNum;
    qint64 costtime;
    string ans;
    string ques;

    int lastfloor=0;

    int correct[FLOORNUMBER]={0};
    int quesnum[FLOORNUMBER]={0};
    int waitingpeople[FLOORNUMBER]={0};
    int arrivingpeople[FLOORNUMBER]={0};
    qint64 costlist[FLOORNUMBER]={0};
    int floorscore[FLOORNUMBER]={0};
    uint testdatacount[FLOORNUMBER]={0};
    int runtimecount[FLOORNUMBER]={0};
    map<quint32, Performance> performap[FLOORNUMBER];
    int distance=0;
    int elevactorPeople=0;
    int totalpeople=0;
    int totalscore=0;

    void initializeDB();
    void initializeGUI();
    void initializeSystem();
};

#endif // JUDGEWINDOW_H
