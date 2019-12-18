#include "manhattandistance.h"

ManhattanDistance::ManhattanDistance()
{
    query.exec("drop database if exists Database2");
    query.exec("create database Database2");
    query.exec("use Database2");
    query.exec("drop table if exists ManhattanDistance");
    query.exec("create table ManhattanDistance(Id int primary key, Country char(50), City char(60), Lat double, Lon double)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE ManhattanDistance FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");
}

string ManhattanDistance::solve(const string &s)
{
    string ans;
    query.exec("use Database2");
    ss.clear();
    ss << s;
    ss >> t1;
    ss >> t2;
    ss >> t3;
    ss >> t4;
    st = "select count(col), round(sum(col),4) from (select x1 - x2 as col from (select max(Lon) as x1, min(Lon) as x2 from (select * from (select * from ManhattanDistance as t1 where Lat < " + t3;
    st += (")as t2 order by Lat desc limit " + to_string(t1 - 1) + ", " + to_string(t2 - t1 + 1) + ")as t3 union select max(Lat), min(Lat) from (select * from (select * from ManhattanDistance as t4 where Lon > " + t4);
    st += (")as t5 order by Lon asc limit " + to_string(t1 - 1) + ", " + to_string(t2 - t1 + 1) + ")as t6)as t7)as t8");

//    qDebug() << QString::fromStdString(st);
    query.exec(QString::fromStdString(st));
    query.next();
    if(query.value(0).toString().toInt() < 2)
        ans = "NULL";
    else
        ans = query.value(1).toString().toStdString();
    return ans;
}
