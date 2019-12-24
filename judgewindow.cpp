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
    database.setPassword("l0963577306");
    database.setPort(3306);
    int t = database.open();
    query = QSqlQuery(database);
//    qDebug()<<"DBOPEN?" << t;
    query.exec("drop database if exists Course8");
    query.exec("create database Course8");
    query.exec("use Course8");
    //----------getPeople----------
    query.exec("drop table if exists PeopleList");
    query.exec("create table PeopleList(Id char(8)primary key, Nowfloor int, Destination int, Number int)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/initial_condition.csv' INTO TABLE PeopleList FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");

    setSeed(0);
    conditionNum = 1;
    st = "select * from PeopleList where Id like '%0" + to_string(conditionNum) + "-%'";
    query.exec(QString::fromStdString(st));
//    qDebug() << conditionNum;
    for(int i=0;i<27;i++)
        arrive[i] = 0;
    for (int i = 0; i < 27; i++)
    {
        query.next();
        condition[i].setCondition(query.value(0).toString().toStdString(), query.value(1).toInt(), query.value(2).toInt(), query.value(3).toInt());
        arrive[condition[i].Dest-1]+=condition[i].Number;
    }

    query.exec("drop table if exists TestData");
    query.exec("create table TestData(Id char(8)primary key, Floor int, Question text, answer text)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/testdata.csv' INTO TABLE TestData FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");

    //-----------getData-----------
    score=0;
    distance=0;
    ui->setupUi(this);
    for(int i=0;i<27;i++)
    {
        for(int j=0;j<4;j++)
            ui->gridLayout->addWidget(&showline[i][j],i,j);
        ui->gridLayout->addWidget(&giveup[i],i,5);
    }

    for(int i=0;i<27;i++)
     {
        showline[i][0].setText(QString::number(condition[i].Number));
        showline[i][1].setText(QString::number(arrive[i]));
        showline[i][2].setText(QString::number(0));
        showline[i][3].setText(QString::number(0));
     }

    for(int i=0;i<27;i++)
        giveup[i].setDisabled(1);
//    for(int i=20;i<27;i++)
//        giveup[i].setChecked(1);
    for(int i=0;i<27;i++)
        floordatatimes[i]=10;
    for(int i=0;i<27;i++)
        floornextdata[i]=0;
}

string JudgeWindow::getData(int floor,int b,int &datatimes)
{
    datatimes=floordatatimes[floor-1];

    if(giveup[floor-1].isChecked())
        return "GIVEUP";

    string st;
    this->floor=floor;
    query.exec("use Course8");
    st = "select * from (select * from testdata as t1 where Floor = " + to_string(floor) + " ) as t2 where id regexp '" + to_string(floornextdata[floor - 1]++) + "$' limit 1";
    query.exec(QString::fromStdString(st));
    query.next();
    answer = query.value(3).toString().toStdString();
    timer.start();
    return query.value(2).toString().toStdString();
}

void JudgeWindow::getInitial(int *dest, int *people)
{
    for(int i=0;i<27;i++)
    {
        dest[i]=condition[i].Dest;
        people[i]=condition[i].Number;
    }
}

int JudgeWindow::getConditionNum()
{
    return conditionNum;
}

bool JudgeWindow::submitData(string ans)
{
    costtime = timer.nsecsElapsed();
    costtime/=floordatatimes[floor-1];
    if(!ans.compare(answer))
    {
        score=1000000000+static_cast<int>(pow(2,floor-1));
        return 1;
    }
    score=0;
    return 0;
}

void JudgeWindow::update(int floor, qint64 time, bool corr, bool inOrOut)
{
    int leave=showline[floor-1][0].text().toInt();
    int arrive=showline[floor-1][1].text().toInt();
    qint64 cost=showline[floor-1][2].text().toLongLong();
    long long nowScroe=showline[floor-1][3].text().toLongLong();

    if(inOrOut)
        showline[floor-1][0].setText(QString::number(leave-1));
    else
        showline[floor-1][1].setText(QString::number(arrive-1));

    showline[floor-1][2].setText(QString::number(cost+time));
    showline[floor-1][3].setText((QString::number(nowScroe+score)));
}

JudgeWindow::~JudgeWindow()
{
    delete ui;
}

void JudgeWindow::scheduleEnd()
{
    time.open("time.txt",ios::out);

    for(int i=0;i<27;i++)
        time<<i<<','<<showline[i][2].text().toStdString()<<",0,0"<<endl;

    time.close();
}
