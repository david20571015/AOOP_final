#include "judgewindow.h"
#include "ui_judgewindow.h"

JudgeWindow::JudgeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JudgeWindow)
{
    score=0;
    distance=0;
    ui->setupUi(this);
    for(int i=0;i<27;i++)
        for(int j=0;j<4;j++)
            ui->gridLayout->addWidget(&showline[i][j],i,j);
    time.open("time.txt");
}

JudgeWindow::~JudgeWindow()
{
    delete ui;
}

bool JudgeWindow::submitData(string ans)
{
    costtime = timer.nsecsElapsed();
    if(!ans.compare(answer))
    {
        score+=100;
        return 1;
    }
    return 0;
}

void JudgeWindow::scheduleEnd()
{
    time<<floor<<','
        <<getSpendTime()<<','
        <<numOfCorr<<','
        <<numOfQues<<endl;
}


