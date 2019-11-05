#ifndef JUDGE_H
#define JUDGE_H

#include<string>
#include<QtGlobal>
#include<fstream>
#include<QElapsedTimer>
#include<cstdlib>
#include<vector>

using namespace std;

class Judge
{
public:
    Judge();
    string getData(int question);
    bool submitData(string ans);
    qint64 getSpendTime(){return costtime;}
private:
    string ans;
    ifstream in;
    QElapsedTimer timer;
    qint64 costtime;
};

#endif // JUDGE_H
