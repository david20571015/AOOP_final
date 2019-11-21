#include "shortestsummation.h"

shortestsummation::shortestsummation()
{

}

string shortestsummation::solve(string s)
{
    string ans;
    vector<int> house=stringtoVectorInt(s);

    for(int i=0;i<house.size();i+=house[i]*4+1)
    {
        stringstream ss;
        string tmp;
        vector<int> x,y;
        for(int j=0;j<house[i]*2;j++)
        {
           x.push_back(house[i+j*2+1]);
           y.push_back(house[i+j*2+2]);
        }
        ss<<fixed<<setprecision(2)<<shortestDistance(x,y);
        ss>>tmp;
        ans+=tmp+' ';
    }

    ans.erase(ans.end()-1);
    return ans;
}

double shortestsummation::shortestDistance(vector<int> &x,vector<int> &y)
{
    double dis=0;
    double min;
    int h1,h2;
    int n=x.size()/2;
    for(int i=0;i<n;i++)
    {
        min=distance(x[0]-x[1],y[0]-y[1]);
        for(int j=0;j<x.size()-1;j++)
            for(int k=j+1;k<x.size();k++)
                if(distance(x[j]-x[k],y[j]-y[k])<=min)
                {
                    min=distance(x[j]-x[k],y[j]-y[k]);
                    h1=j;
                    h2=k;
                }
        qDebug()<<x[h1]<<' '<<y[h1]<<"   "<<x[h2]<<' '<<y[h2];
        dis+=min;
        x.erase(x.begin()+h2);
        x.erase(x.begin()+h1);
        y.erase(y.begin()+h2);
        y.erase(y.begin()+h1);
    }
    qDebug()<<dis;
    return dis;
}
