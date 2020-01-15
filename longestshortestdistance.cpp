#include "longestshortestdistance.h"

LongestShortestDistance::LongestShortestDistance()
{
}

string LongestShortestDistance::solve(const string &s)
{
//    QSqlQuery query(database);
//    QSqlQuery query;


    query.exec("DROP DATABASE IF EXISTS CITYDATABASE;");
    query.exec("CREATE DATABASE CITYDATABASE;");
    query.exec("USE CITYDATABASE;");
    query.exec("DROP TABLE IF EXISTS CITYTABLE;");
    query.exec("CREATE TABLE CITYTABLE(ID INT,COUNTRY VARCHAR(50),CITY VARCHAR(60),LAT DOUBLE,LON DOUBLE,PRIMARY KEY(ID));");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city_forFinal4.csv' INTO TABLE CITYTABLE FIELDS ENCLOSED BY '\"' TERMINATED BY ',' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS;");

    stringstream ss,so;
    int n,a,b;
    string al_ra;
    ss<<s;
    ss>>n>>a>>b>>al_ra;

    string command="SELECT MAX(DISTANCE),MIN(DISTANCE) FROM (SELECT ROUND(SQRT(POW(P1.RLON-P2.RLON,2)+POW(P1.RLAT-P2.RLAT,2)),4) AS DISTANCE FROM";
    string common="(SELECT * FROM(SELECT ID,COUNTRY,CITY,ROUND(LAT,"+to_string(n)+")AS RLAT,ROUND(LON,"+to_string(n)+")AS RLON FROM CITYTABLE GROUP BY RLAT,RLON)";
    command+=(common+"AS P3 ORDER BY CITY ");
    if(al_ra=="al")
        command+=("ASC,ID ASC LIMIT ");
    else
        command+=("DESC,ID ASC LIMIT ");
    command+=(to_string(b-a+1)+" OFFSET "+to_string(a-1)+")AS P1 INNER JOIN");
    command+=(common+"AS P4 ORDER BY CITY ");
    if(al_ra=="al")
        command+=("ASC,ID ASC LIMIT ");
    else
        command+=("DESC,ID ASC LIMIT ");
    command+=(to_string(b-a+1)+" OFFSET "+to_string(a-1)+")AS P2 ON P1.RLAT!=P2.RLAT OR P1.RLON!=P2.RLON)AS PP;");

    query.exec(command.c_str());

    query.next();
    if(query.value(0).isNull()&&query.value(1).isNull())
        so<<"NULL NULL";
    else
        so<<fixed<<setprecision(4)<<query.value(0).toDouble()<<" "<<query.value(1).toDouble();

    return so.str();
}
