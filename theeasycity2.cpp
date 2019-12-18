#include "TheEasyCity2.h"

TheEasyCity2::TheEasyCity2()
{
    query.exec("drop database if exists Course7");
    query.exec("create database Course7");
    query.exec("use Course7");
    query.exec("drop table if exists TheEasyCity2");
    query.exec("create table TheEasyCity2(Id int primary key, Country char(50), City char(60), Lat double, Lon double)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE TheEasyCity2 FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");
}
string TheEasyCity2::solve(const string &s)
{
    string ans;
    ss.clear();
    ss << s;
    query.exec("use Course7");
    ss >> n; // nth city
    n--;
    t1 = to_string(n);
    st = "select mid(Country, 1, 3), c1 from (select Country,count(city) as c1 from TheEasyCity2 group by country) as t2 order by c1 ";
    ss >> t; // large or small
    if (t == lar)
        st += "desc limit ";
    else
        st += "asc limit ";
    st += t1;
    st += ", 1";
    query.exec(QString::fromStdString(st));

    query.next();
    ans = query.value(0).toString().toStdString();
    ans += " ";
    ans += query.value(1).toString().toStdString();
    ans += " ";

    ss >> t1;   // start char
    ss >> t2;   // end char
    ss >> t3;   // min Lat
    ss >> t4;   // max Lat
    ss >> t5;   // min Lon
    ss >> t6;   // max Lon
    ss >> t;    // m

    st = "update TheEasyCity2 set Lat = Lat + Lon, Lon = Lat - Lon, lat = Lat - Lon where Id regexp '";
    st += t;
    st += "$'";
    query.exec(QString::fromStdString(st));


    st = "select * from (select * from (select * from TheEasyCity2 as t1 where City regexp '^[";
    st += t1;
    st += "]') as t2 where City regexp '[^";
    st += t2;
    st += "]$') as t3 where ( ";
    st += t3;
    st += " >= Lat or Lat >= ";
    st += t4;
    st += " ) or ( Lon <= ";
    st += t5;
    st += " or Lon >= ";
    st += t6;
    st += " )";
    query.exec(QString::fromStdString(st));

    if(!query.next())
        ans += "NULL";
    else
    {
        st = "select round(sqrt((max(Lat) - min(Lat)) * (max(Lat) - min(Lat)) + (max(Lon) - min(Lon)) * (max(Lon) - min(Lon))), 4) as val from (select * from (select * from TheEasyCity2 as t1 where City regexp '^[";
        st += t1;
        st += "]') as t2 where City regexp '[^";
        st += t2;
        st += "]$') as t3 where ( ";
        st += t3;
        st += " >= Lat or Lat >= ";
        st += t4;
        st += " ) or ( Lon <= ";
        st += t5;
        st += " or Lon >= ";
        st += t6;
        st += " )";
        query.exec(QString::fromStdString(st));

        query.next();
        ss.clear();
        ss << fixed << setprecision(4) << query.value(0).toDouble();
        ss >> t1;
        ans += t1;
    }

    st = "update TheEasyCity2 set Lat = Lat + Lon, Lon = Lat - Lon, lat = Lat - Lon where Id regexp '";
    st += t;
    st += "$'";
    query.exec(QString::fromStdString(st));
    return ans;
}

TheEasyCity2::~TheEasyCity2()
{
}
