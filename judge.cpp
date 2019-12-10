#include "judge.h"

Judge::Judge()
{
    score=0;
}

string Judge::getData(int question)
{
    in.open(to_string(question) + ".txt", ios::in);

    string s;
    vector<string> data;
    while (getline(in, s))
        data.push_back(s);
    in.close();

    //    srand(static_cast<int>(time(0)));
    int d = rand() % (data.size() / 2);
    this->ans = data.at(d * 2 + 1);
    timer.start();
    return data.at(d * 2);
}

bool Judge::submitData(string ans)
{
    costtime = timer.nsecsElapsed();
    if(ans.compare(this->ans)==0)
        score+=100;
    return ans.compare(this->ans)==0;
}
