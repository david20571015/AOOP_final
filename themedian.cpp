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
    string ans, t3, t4, t5, lat = "lat", asc = "asc";
    int n1, n2;
    ss.clear();
    query.exec("use Database3");
    ss << s;
    ss >> n1;
    ss >> n2;
    ss >> t3;
    ss >> t4;
    ss >> t5;
    if (t5 == asc)
    {
        if (t3 == lat)
        {
            st = "select round(avg(lat), 4) from (select a.lat from (select * from TheMedian as t1 where Id regexp '" + t4 + "$' order by lat asc limit " + to_string(n1 - 1) + ", " + to_string(n2 - n1 + 1) + ")as a";
            st += " join ";
            st += "(select * from TheMedian as t1 where Id regexp '" + t4 + "$' order by lat asc limit " + to_string(n1 - 1) + ", " + to_string(n2 - n1 + 1) + ")as b ";
            st += "group by a.Id having SUM(SIGN(1-SIGN(a.lat-b.lat))) = round((COUNT(distinct b.Id)) / 2) or SUM(SIGN(1-SIGN(a.lat-b.lat))) = round((COUNT(distinct b.Id) + 1) / 2))as t2";
        }
        else
        {
            st = "select round(avg(lon), 4) from (select a.lon from (select * from TheMedian as t1 where Id regexp '" + t4 + "$' order by lon asc limit " + to_string(n1 - 1) + ", " + to_string(n2 - n1 + 1) + ")as a";
            st += " join ";
            st += "(select * from TheMedian as t1 where Id regexp '" + t4 + "$' order by lon asc limit " + to_string(n1 - 1) + ", " + to_string(n2 - n1 + 1) + ")as b ";
            st += "group by a.Id having SUM(SIGN(1-SIGN(a.lon-b.lon))) = round((COUNT(distinct b.Id)) / 2) or SUM(SIGN(1-SIGN(a.lon-b.lon))) = round((COUNT(distinct b.Id) + 1) / 2))as t2";
        }
    }
    else
    {
        if (t3 == lat)
        {
            st = "select round(avg(lat), 4) from (select a.lat from (select * from TheMedian as t1 where Id regexp '" + t4 + "$' order by lat desc limit " + to_string(n1 - 1) + ", " + to_string(n2 - n1 + 1) + ")as a";
            st += " join ";
            st += "(select * from TheMedian as t1 where Id regexp '" + t4 + "$' order by lat desc limit " + to_string(n1 - 1) + ", " + to_string(n2 - n1 + 1) + ")as b ";
            st += "group by a.Id having SUM(SIGN(1-SIGN(a.lat-b.lat))) = round((COUNT(distinct b.Id)) / 2) or SUM(SIGN(1-SIGN(a.lat-b.lat))) = round((COUNT(distinct b.Id) + 1) / 2))as t2";
        }
        else
        {
            st = "select round(avg(lon), 4) from (select a.lon from (select * from TheMedian as t1 where Id regexp '" + t4 + "$' order by lon desc limit " + to_string(n1 - 1) + ", " + to_string(n2 - n1 + 1) + ")as a";
            st += " join ";
            st += "(select * from TheMedian as t1 where Id regexp '" + t4 + "$' order by lon desc limit " + to_string(n1 - 1) + ", " + to_string(n2 - n1 + 1) + ")as b ";
            st += "group by a.Id having SUM(SIGN(1-SIGN(a.lon-b.lon))) = round((COUNT(distinct b.Id)) / 2) or SUM(SIGN(1-SIGN(a.lon-b.lon))) = round((COUNT(distinct b.Id) + 1) / 2))as t2";
        }
    }

    query.exec(QString::fromStdString(st));
    query.next();

    ss.clear();
    ss << fixed << setprecision(4) << query.value(0).toDouble();
    ss >> ans;
    return ans;
}
