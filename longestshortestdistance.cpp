#include "longestshortestdistance.h"

LongestShortestDistance::LongestShortestDistance()
{
    query.exec("drop database if exists Database5");
    query.exec("create database Database5");
    query.exec("use Database5");
    query.exec("drop table if exists CityList");
    query.exec("create table CityList(Id int primary key, Country char(50), City char(60), Lat double, Lon double)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE CityList FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");
    query.exec("select * from CityList");
}

string LongestShortestDistance::solve(const string &s)
{
    query.exec("use Database5");
    stringstream ss;
    string ans;
    string t1, t4, al = "al", st;
    int n2, n3;

//    query.exec("drop database if exists Database5");
//    query.exec("create database Database5");

//    query.exec("drop table if exists CityList");
//    query.exec("create table CityList(Id int primary key, Country char(50), City char(60), Lat double, Lon double)");
//    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE CityList FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");
    ss << s;
    ss >> t1;
    ss >> n2;
    ss >> n3;
    ss >> t4;
    if (t4 == al)
    {
        st = "select max(round(sqrt(pow(a.col1-b.col1,2)+pow(a.col2-b.col2,2)), 4)) as max, min(round(sqrt(pow(a.col1-b.col1,2)+pow(a.col2-b.col2,2)), 4))as min from ";
        st += "(select * from (select round(Lat, " + t1 + ") as col1, round(Lon, " + t1 + ") as col2, City, Id from CityList as t1 group by col1, col2) ";
        st += "as t2 order by City, Id asc limit " + to_string(n2 - 1) + ", " + to_string(n3 - n2 + 1) + ")as a join";
        st += "(select * from (select round(Lat, " + t1 + ") as col1, round(Lon, " + t1 + ") as col2, City, Id from CityList as t1 group by col1, col2) ";
        st += "as t2 order by City, Id asc limit " + to_string(n2 - 1) + ", " + to_string(n3 - n2 + 1) + ")as b on ((a.col1 != b.col1 or a.col2 != b.col2) and a.City != b.City)";
    }
    else
    {
        st = "select max(round(sqrt(pow(a.col1-b.col1,2)+pow(a.col2-b.col2,2)), 4)) as max, min(round(sqrt(pow(a.col1-b.col1,2)+pow(a.col2-b.col2,2)), 4))as min from ";
        st += "(select * from (select round(Lat, " + t1 + ") as col1, round(Lon, " + t1 + ") as col2, City, Id from CityList as t1 group by col1, col2) ";
        st += "as t2 order by City desc, Id asc limit " + to_string(n2 - 1) + ", " + to_string(n3 - n2 + 1) + ")as a join";
        st += "(select * from (select round(Lat, " + t1 + ") as col1, round(Lon, " + t1 + ") as col2, City, Id from CityList as t1 group by col1, col2) ";
        st += "as t2 order by City desc, Id asc limit " + to_string(n2 - 1) + ", " + to_string(n3 - n2 + 1) + ")as b on ((a.col1 != b.col1 or a.col2 != b.col2) and a.City > b.City)";
    }
    query.exec(QString::fromStdString(st));
    query.next();


    if(query.value(0).toDouble() == 0)
    {
        ans = "NULL NULL";
    }
    else
    {
        ss.clear();
        ss << fixed << setprecision(4) << query.value(0).toDouble();
        ss >> t1;
        ss.clear();
        ans = t1;
        ss << fixed << setprecision(4) << query.value(1).toDouble();
        ss >> t1;
        ans += " " + t1;
    }
    return ans;
}
