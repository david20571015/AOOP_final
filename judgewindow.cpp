#include "judgewindow.h"
#include "ui_judgewindow.h"
#include <QDebug>
JudgeWindow::JudgeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JudgeWindow)
{
    string st;
    distance = 0;
    population = 0;
    ui->setupUi(this);
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("nctuece");
    database.setPort(3306);
    int t = database.open();
    query = QSqlQuery(database);
    qDebug()<<"DBOPEN?" << t;
    query.exec("drop database if exists Course8");
    query.exec("create database Course8");
    query.exec("use Course8");
    //----------getPeople----------
    query.exec("drop table if exists PeopleList");
    query.exec("create table PeopleList(Id char(8)primary key, Nowfloor int, Destination int, Number int)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/initial_condition.csv' INTO TABLE PeopleList FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");


    conditionNum = rand() % 300 + 1;
    st = "select * from PeopleList where Id like '%0" + to_string(conditionNum) + "-%'";
    query.exec(QString::fromStdString(st));
    for(int i=0;i<27;i++)
        arrive[i] = 0;
    for (int i = 0; i < 27; i++)
    {
        query.next();
        condition[i].setCondition(query.value(0).toString().toStdString(), query.value(1).toInt(), query.value(2).toInt(), query.value(3).toInt());
        arrive[condition[i].Dest]+=condition[i].Number;
    }

    query.exec("drop table if exists TestData");
    query.exec("create table TestData(Id char(8)primary key, Floor int, Question text, answer text)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/testdata.csv' INTO TABLE TestData FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");



    //-----------getData-----------
  score=0;
    distance=0;
    ui->setupUi(this);
    for(int i=0;i<27;i++)
        for(int j=0;j<4;j++)
            ui->gridLayout->addWidget(&showline[i][j],i,j);
//    time.open("time.txt");

    for(int i=0;i<27;i++)
     {

        showline[i][0].setText(QString::number(condition[i].Number));
        showline[i][1].setText(QString::number(arrive[i]));
        showline[i][2].setText(QString::number(0));
        showline[i][3].setText(QString::number(0));
    }

}

JudgeWindow::~JudgeWindow()
{
    delete ui;
}

string JudgeWindow::getData(int floor,int b)
{

    string st;
    distance += abs(condition[floor].Dest - floor);
    if(b)
    {
        if(condition[floor].Number + population <= 10)
        {
            population += condition[floor].Number;
            condition[floor].Number = 0;
        }
        else
        {
            condition[floor].Number -= 10 - population;
            population = 10;
        }
    }
    else

    this->floor=floor;
    query.exec("use Course8");
    st = "select * from (select * from TestData as t1 where Floor = " + to_string(floor) + ") as t2 order by rand() limit 1";
    query.exec(QString::fromStdString(st));
    query.next();
    ans = query.value(3).toString().toStdString();
    timer.start();
    return query.value(2).toString().toStdString();
}
int JudgeWindow::getConditionNum()
{
    return conditionNum;
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
