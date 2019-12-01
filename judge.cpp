#include "judge.h"

Judge::Judge()
{

}

string Judge::getData(int question)
{
    in.open(to_string(question)+".txt",ios::in);

    string s;
    vector<string> data;
    while(getline(in,s))
        data.push_back(s);
    in.close();

    int d=rand()%(data.size()/2);
    this->ans=data.at(d*2+1);
    timer.start();
    return data.at(d*2);
}

bool Judge::submitData(string ans)
{
    costtime=timer.nsecsElapsed();
    return ans==this->ans;
}
