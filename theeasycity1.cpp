#include "theeasycity1.h"

TheEasyCity1::TheEasyCity1()
{
    query.exec("drop database if exists Database1");
    query.exec("create database Database1");
    query.exec("use Database1");
    query.exec("drop table if exists TheEasyCity1");
    query.exec("create table TheEasyCity1(Id int primary key, Country char(50), City char(60), Lat double, Lon double)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE TheEasyCity1 FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS;");
}

string TheEasyCity1::solve(const string &s)
{
    ss.clear();
    string ans;
    ss << s;
    query.exec("use Database1");
    query.exec("select * from TheEasyCity1");

//    qDebug() << "get data: " <<query.next();
    ss >> t1;
    ss >> t2;
    ss >> t3;
    st = "select count(City) - count(distinct City) from (select * from (select * from TheEasyCity1 as t1 where City regexp '^[" + t1 + "]')as t2 where City regexp '[^aeiou]$')as t3 where Lat > " + t2 + " and Lon < " + t3;
    query.exec(QString::fromStdString(st));
    query.next();
    ans += query.value(0).toString().toStdString() + " ";

    ss >> t1;
    ss >> t2;
    ss >> t3;
    ss >> t4;
    ss >> t5;
    ss >> t6;
    ss >> t7;
    st = "select round(sum(col1), " + t7 + "), round(sum(col2), " + t7 + "), max(length(City)) - min(length(City)) from (select * from  (select Id, Country, City, Lat * " + t1 + " as col1, Lon * " + t2 + " as col2 from TheEasyCity1 where Id regexp '[";
    if (t3 == ev)
        st += "24680]$' union select * from TheEasyCity1 where Id regexp '[13579]$')";
    else
        st += "13579]$' union select * from TheEasyCity1 where Id regexp '[24680]$')";
    if (t5 == even)
        st += "as t1 where Id regexp '[24680]$' order by length(City)";
    else
        st += "as t1 where Id regexp '[13579]$' order by length(City)";
    if (t6 == asc)
        st += "asc limit 0, " + t4 + ")as t2";
    else
        st += "desc limit 0, " + t4 + ")as t2";
    query.exec(QString::fromStdString(st));

    query.next();


    ss.clear();
    ss << fixed << setprecision(stoi(t7)) << query.value(0).toDouble();
    ss >> t1;
    ans += t1 + " ";

    ss.clear();
    ss << fixed << setprecision(stoi(t7)) << query.value(1).toDouble();
    ss >> t1;
    ans += t1 + " ";

    ans += query.value(2).toString().toStdString();

    return ans;
}
