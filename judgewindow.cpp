#include "judgewindow.h"
#include "ui_judgewindow.h"
#include <QDebug>
JudgeWindow::JudgeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JudgeWindow)
{
    string st;
    ui->setupUi(this);

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("1234567s");
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
    //----------giveup----------
//    for(int i=21;i<27;i++)
//        giveup[i].setChecked(1);
    //----------giveup----------
    for(int i=0;i<21;i++)
        floordatatimes[i]=10;
    for(int i=21;i<27;i++)
        floordatatimes[i]=1;
    for(int i=0;i<27;i++)
        floornextdata[i]=0;

    for(int i = 0; i < 27; i++)
    {
        upload[i].pass = 0;
        upload[i].totalques = condition[i].Number+arrive[i];
        upload[i].totalscore = 0;
        upload[i].timespent = 0;
    }
    uploadistance=0;
}

string JudgeWindow::getData(int floor,int b,int &datatimes)
{
    datatimes=floordatatimes[floor-1];

    if(giveup[floor-1].isChecked())
    {
        answer="";
        return "GIVEUP";
    }

    string st;
    this->floor=floor;
    query.exec("use Course8");
//    query.exec("select * from TestData");
//    query.next();
//    qDebug() << query.value(0);
    st = "select * from (select * from TestData as t1 where Floor = " + to_string(floor) + " ) as t2 where id regexp '" + to_string(floornextdata[floor - 1]++) + "$' limit 1";
//    floornextdata[floor-1]%=6;
    query.exec(QString::fromStdString(st));
    int tflag = query.next();
//    qDebug() << tflag;
    if(tflag)
        answer = query.value(3).toString().toStdString();
    else
    {
        floornextdata[floor-1] %= (floornextdata[floor - 1]);
        st = "select * from (select * from TestData as t1 where Floor = " + to_string(floor) + " ) as t2 where id regexp '" + to_string(floornextdata[floor - 1]++) + "$' limit 1";
        query.exec(QString::fromStdString(st));
        query.next();
        answer = query.value(3).toString().toStdString();
    }
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

    if(!ans.compare(answer))
    {
        costtime/=floordatatimes[floor-1];
        upload[floor-1].timespent+=costtime;
        upload[floor-1].pass++;
        score=10000000000+static_cast<long long>(pow(2,floornextdata[floor-1]-1));
        upload[floor-1].totalscore+=score;

        return 1;
    }
    costtime=0;
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

void JudgeWindow::uploadToDB()
{
    QSqlDatabase database1;
    string st;
    database1 = QSqlDatabase::addDatabase("QMYSQL");
    database1.setHostName("140.113.146.126");
    database1.setUserName("aoopstudent");
    database1.setPassword("tsaimother");
    database1.setPort(3306);
    database1.open();
    QSqlQuery query1;
    query1.exec("use aoopstudentuse");
    for(int i = 0; i < 27; i++)
    {
        st = "insert into floorscore values('0710754', '梁育騰', '0710734', '邱俊耀', '" + to_string(i + 1);
        st += "', '"+ to_string(upload[i].timespent) +"', '"+ to_string(upload[i].pass) +"', '"+ to_string(upload[i].totalques) +"','"+ to_string(upload[i].totalscore) +"' )";
        query1.exec(QString::fromStdString(st));
    }
    query1.exec(QString::fromStdString("insert into totalpath values('0710734', '邱俊耀', '0710754', '梁育騰', '" + to_string(uploadistance) + "')"));
}
