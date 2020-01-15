#include "TheEasyCity2.h"

TheEasyCity2::TheEasyCity2()
{
}
string TheEasyCity2::solve(const string &s)
{
    query.exec("drop database if exists Course7");
    query.exec("create database Course7");
    query.exec("use Course7");
    query.exec("drop table if exists TheEasyCity2");
    query.exec("create table TheEasyCity2(Id int primary key, Country char(50), City char(60), Lat double, Lon double)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE TheEasyCity2 FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");

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
    if(query.value(0).isNull())
        ans = "NULL NULL ";
    else
    {
        ans = query.value(0).toString().toStdString();
        ans += " ";
        ans += query.value(1).toString().toStdString();
        ans += " ";
    }


    ss >> t1;   // start char
    ss >> t2;   // end char
    ss >> t3;   // min Lat
    ss >> t4;   // max Lat
    ss >> t5;   // min Lon
    ss >> t6;   // max Lon
    ss >> t;    // m

    st = "delete from TheEasyCity2 where City regexp '^[^" + t1 + "]|[" + t2 + "]$' or ( Lat > " + t3 + " and Lat < " + t4 + " and Lon > " + t5 + " and Lon < " + t6 + ")";
    query.exec(QString::fromStdString(st));

    st = "update TheEasyCity2 set Lat = Lat + Lon, Lon = Lat - Lon, lat = Lat - Lon where Id regexp '";
    st += t;
    st += "$'";
    query.exec(QString::fromStdString(st));


    st = "select round(sqrt(pow(max(Lat) - min(Lat), 2) + pow(max(Lon) - min(Lon), 2)), 4) as val from TheEasyCity2";
    query.exec(QString::fromStdString(st));
    query.next();


//    if(query.value(0).isNull())
//        ans += "NULL";
//    else
//    {
        ss.clear();
        ss << fixed << setprecision(4) << query.value(0).toDouble();
        ss >> t1;
        ans += t1;
//    }
    return ans;
}

TheEasyCity2::~TheEasyCity2()
{
}
