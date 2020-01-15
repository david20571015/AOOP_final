#include "building.h"

Building::Building()
{
    judgewindow.show();
//    judgewindow.setSeed(0);
    int n=judgewindow.getConditionNum();
    simu_timer = new QTimer();
    connect(simu_timer,SIGNAL(timeout()),this,SLOT(update()));
    getInitial(dest,people);
    data.distance=0;
    data.elevatorpeople=0;

    floor[0]  = new Floor(new P1);
    floor[1]  = new Floor(new P2);
    floor[2]  = new Floor(new P3);
    floor[3]  = new Floor(new P4);
    floor[4]  = new Floor(new P5);
    floor[5]  = new Floor(new P6);
    floor[6]  = new Floor(new P7);
    floor[7]  = new Floor(new P8);
    floor[8]  = new Floor(new P9);
    floor[9]  = new Floor(new P10);
    floor[10] = new Floor(new P11);
    floor[11] = new Floor(new P12);
    floor[12] = new Floor(new P13);
    floor[13] = new Floor(new P14);
    floor[14] = new Floor(new P15);
    floor[15] = new Floor(new P16);
    floor[16] = new Floor(new P17);
    floor[17] = new Floor(new P18);
    floor[18] = new Floor(new P19);
    floor[19] = new Floor(new P20);
    floor[20] = new Floor(new P21);
    floor[21] = new Floor(new P22);
    floor[22] = new Floor(new P23);
    floor[23] = new Floor(new P24);
    floor[24] = new Floor(new P25);
    floor[25] = new Floor(new P26);
    floor[26] = new Floor(new P27);
//    qDebug() << "QQ";
//    QSqlDatabase database1;
//    string st;
//    database1 = QSqlDatabase::addDatabase("QMYSQL");
//    database1.setHostName("localhost");
//    database1.setUserName("aoopstudent");
//    database1.setPassword("1234567");
//    database1.setPort(3306);
//    qDebug() << "QQ";
//    qDebug() << database1.open();
//    QSqlQuery query1;
//    query1.exec("use aoopstudentuse");
//    for(int i = 0; i < 27; i++)
//    {
//        st = "insert into floorscore values('0710787', '一二三', '0710787', '一二三', '" + to_string(i + 1);
//        st += "', '0', '0', '0','0' )";
//        query1.exec(QString::fromStdString(st));


//        st = "insert into floorscore values('0710754', '梁育騰', '0710734', '邱俊耀', '" + to_string(i + 1);
//        st += "', '0', '0', '0','0' )";
//        query1.exec(QString::fromStdString(st));
//      }
}

void Building::getInitial(int *d,int *p)
{
    QSqlDatabase database;
    string st;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("l0963577306");
    database.setPort(3306);
    int t = database.open();
    QSqlQuery query;
    query = QSqlQuery(database);
    query.exec("drop database if exists Course8");
    query.exec("create database Course8");
    query.exec("use Course8");
    //----------getPeople----------
    query.exec("drop table if exists PeopleList");
    query.exec("create table PeopleList(Id char(8)primary key, Nowfloor int, Destination int, Number int)");
    query.exec("LOAD DATA INFILE \
                'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/initial_condition.csv' \
                INTO TABLE PeopleList FIELDS TERMINATED BY ',' \
                ENCLOSED BY '\"' LINES \
                TERMINATED BY '\r\n' \
                IGNORE 1 ROWS");

    conditionNum = 1;
    st = "select * from PeopleList where Id like '%0" + to_string(conditionNum) + "-%'";
    query.exec(QString::fromStdString(st));

    for (int i = 0; i < 27; i++)
    {
        query.next();
        d[i] = query.value(2).toInt();
        p[i] = query.value(3).toInt();
        // condition[i].setCondition(query.value(0).toString().toStdString(), query.value(1).toInt(), query.value(2).toInt(), query.value(3).toInt());
    }
}

void Building::run(int nowFloor,int inout)
{
    int times;
    data.testdata = judgewindow.getData(nowFloor-1, inout,times);
    //qDebug()<<QString::fromStdString(data.testdata);
    if(!data.testdata.compare("GIVEUP"))
    {
        data.correct=judgewindow.submitData("GIVEUP");
        data.spendtime = 0;
    }
    else
    {
        for(int i=0;i<times;i++)
            data.submit = floor[nowFloor-1]->p->solve(data.testdata);
        data.correct = judgewindow.submitData(data.submit);
        data.spendtime = judgewindow.getSpendTime();
    }
    if(!data.correct&&data.testdata.compare("GIVEUP"))
        qDebug()<<nowFloor<<' '<<QString::fromStdString(data.testdata.substr(0,10))<<' '<<QString::fromStdString(data.submit.substr(0,10));
}

void Building::startSimulation()
{
    scheduler.setInitial(dest,people);
    scheduler.calRoute();
    data.elevatorpeople=0;
    data.distance=0;
    data.nowfloor=scheduler.getNowFloor().first;
    simu_timer->setSingleShot(1);
    simu_timer->start(100);
//    exportToDatabase();
}

void Building::update()
{
    simu_timer->start(10);
    data.elevatorpeople+=(scheduler.getNowFloor().second*2-1);
    data.distance+=abs(data.nowfloor-scheduler.getNowFloor().first);
//    judgewindow.uploadistance=data.distance;
    data.nowfloor=scheduler.getNowFloor().first;
    int inOrOut=scheduler.getNowFloor().second;

    if(data.nowfloor)
    {
        run(data.nowfloor,inOrOut);
//        judgewindow.update(data.nowfloor,data.spendtime,data.correct,scheduler.getNowFloor().second);
        scheduler.nextFloor();
    }
    else
    {
        simu_timer->stop();
        judgewindow.scheduleEnd();
    }

    emit this->updateGUI();
}

Building::~Building()
{
    for (int i = 0; i < 27; i++)
        delete floor[i];
}
