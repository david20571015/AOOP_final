#include "themedian.h"

TheMedian::TheMedian()
{
    query.exec("drop database if exists Database3");
    query.exec("create database Database3");
    query.exec("use Database3");
    query.exec("drop table if exists TheMedian");
    query.exec("create table TheMedian(Id int primary key, Country char(50), City char(60), Lat double, Lon double)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE TheMedian FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");

}

string TheMedian::solve(const string &s)
{
    string ans;
    ss.clear();
    query.exec("use Database3");
    query.exec("select * from TheMedian");
    qDebug() << "test data:" << query.next();
    ss << s;
    ss >> t1;
    ss >> t2;
    ss >> t3;
    ss >> t4;
    ss >> t5;
    if(t5 == asc)
        st = "select round(avg(" + t3 + "), 4) from(select " + t3 + " from TheMedian as t1 where Id regexp '" + t4 + "$' order by " + t3 + " asc limit " + to_string((int)round((t2 - t1 - 1) / 2.) + t1 - 1) + ", " + to_string((int)(t2 - t1) % 2 + 1) + ") as t2";
    else
        st = "select round(avg(" + t3 + "), 4) from(select " + t3 + " from TheMedian as t1 where Id regexp '" + t4 + "$' order by " + t3 + " desc limit " + to_string((int)round((t2 - t1 - 1) / 2.) + t1 - 1) + ", " + to_string((int)(t2 - t1) % 2 + 1) + ") as t2";
    qDebug() << QString::fromStdString(st);
    query.exec(QString::fromStdString(st));
    if(!query.next())
        ans = "NULL";
    else
        ans = query.value(0).toString().toStdString();
    return ans;
}
