#ifndef JUDGE_H
#define JUDGE_H

#include <bits/stdc++.h>
#include <QtGlobal>
#include <QElapsedTimer>

using namespace std;

class Judge
{
public:
    Judge();
    string getData(int question);
    bool submitData(string ans);
    qint64 getSpendTime() { return costtime; }
    int getScore(){return  score;}

private:
    int score;
    string ans;
    ifstream in;
    QElapsedTimer timer;
    qint64 costtime;
};

#endif // JUDGE_H
