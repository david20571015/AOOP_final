#ifndef DATA_H
#define DATA_H

#include <string>
#include <QtGlobal>

using namespace std;

class Data
{
public:
    int distance;
    int elevatorpeople;
    int score;
    int nowfloor;
    qint64 spendtime;
    string testdata;
    string submit;
    bool correct;
};
#endif // DATA_H
