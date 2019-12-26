#include "symmetricpairs.h"

SymmetricPairs::SymmetricPairs()
{
}

string SymmetricPairs::solve(const string &s)
{
    query.exec("drop database if exists DataBase6");
    query.exec("create database DataBase6");
    query.exec("use DataBase6");
    query.exec("drop table if exists CityList");
    query.exec("create table CityList(Id int primary key, Country char(50), City char(60), Lat double, Lon double)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE CityList FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS;");
    string ans, st;
    ss.clear();
    ss << s;
    ss >> t1;
    ss >> t2;
    ss >> t3;
    ss >> n4;
    query.exec("use DataBase6");
    if(t1 == od)
        st = "update CityList set Lat = Lat + Lon, Lon = Lat - Lon, lat = Lat - Lon where Id regexp '[13579]$'";
    else
        st = "update CityList set Lat = Lat + Lon, Lon = Lat - Lon, lat = Lat - Lon where Id regexp '[24680]$'";
    query.exec(QString::fromStdString(st));
    st = "update CityList set Lat = Lon where Id regexp '" + t2 + "$'";
    query.exec(QString::fromStdString(st));
    st = "select * from(select * from (select x1, y1 from (select * from (select * from (select round(Lon, " + t3 + ") as x1, round(Lat, " + t3 + ") as y1, Id as Id1 from CityList )as a join (select round(Lon, " + t3 + ") as x2, round(Lat, " + t3;
    st += ") as y2, Id as Id2 from CityList)as b on x1 = y2 and x2 = y1 and Id1 != Id2)as t1 group by x1, y1 order by x1, y1) as t2)as t3 where x1 <= y1) as t4 limit " + to_string(n4 - 1) + ", 1";
    query.exec(QString::fromStdString(st));
    query.next();
    if(query.value(0).isNull())
        ans = "NULL ";
    else
    {
        ss.clear();
        ss << fixed << setprecision(stoi(t3)) << query.value(0).toDouble();
        ss >> t1;
        ans = t1;
    }
    if(query.value(1).isNull())
        ans += "NULL";
    else
    {
        ss.clear();
        ss << fixed << setprecision(stoi(t3)) << query.value(1).toDouble();
        ss >> t1;
        ans += " " + t1;
    }

    return ans;
}
