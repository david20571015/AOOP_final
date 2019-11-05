#include "judge.h"

Judge::Judge()
{

}

string Judge::getData(int question)
{
    in.open(to_string(question)+".txt");
    string s;
    vector<string> data;
    while(!in.eof())
    {
        getline(in,s);
        data.push_back(s);
    }
    return data.at(rand()%data.size());
}

bool Judge::submitData(string ans)
{
    return ans==this->ans;
}
