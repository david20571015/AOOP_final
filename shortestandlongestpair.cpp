#include "shortestandlongestpair.h"

ShortestAndLongestPair::ShortestAndLongestPair()
{
}

string ShortestAndLongestPair::solve(string s)
{
    string ans;
    vector<int> house = stringtoVectorInt(s);

    for (int i = 0; i < static_cast<int>(house.size()) ; i += house[i] * 4 + 1)
    {
        stringstream ss;
        string tmp;
        vector<pair<int, int>> p;

        for (int j = 0; j < house[i] * 2; j++)
            p.push_back(make_pair(house[i + j * 2 + 1], house[i + j * 2 + 2]));
        this->point = p;
        ss << fixed << setprecision(2) << shortestDistance(p);
        ss >> tmp;
        ans += tmp + ' ';
    }

    ans.erase(ans.end() - 1);
    return ans;
}

double ShortestAndLongestPair::shortestDistance(vector<pair<int, int>> &p)
{
    int n = static_cast<int>(p.size());
    double *dp = new double[1 << 10];
    double dis[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dis[i][j] = hypot(p[i].first - p[j].first, p[i].second - p[j].second);

    dp[0] = 0;
    for (int S = 1; S < (1 << n); S++)
    {
        dp[S] = 0x3f3f3f3f;
        int i = 0, cnt = 0;
        for (int j = 0; j < n; j++)
            if (S & (1 << j))
            {
                i = j;
                cnt++;
            }
        if (cnt & 1)
            continue;
        for (int j = 0; j < i; j++)
            if (S & (1 << j))
                dp[S] = min(dp[S], dis[i][j] + dp[S ^ (1 << i) ^ (1 << j)]);
    }
    delete []dp;
    return dp[(1 << n) - 1];
}

//double shortestsummation::shortestDistance(vector<pair<int,int>> &p)
//{
//    int n=p.size();

//    for(auto i:label)
//        label[i]=0;

//    this->dist=LONG_MAX;

//    count=0;
//    label[0]=1;
//    vector<int> route(1,0);
//    findDistance(route,n);
//    qDebug()<<count;
//    return this->dist;
//}

//void shortestsummation::findDistance(vector<int> &route, const int &n)
//{
//    if(static_cast<int>(route.size())==n)
//    {
//        for(auto i:route)
//            qDebug()<<route[i];
//        qDebug();
//        double d=0;
//        for(int i=0;i<point.size();i+=2)
//            d+=hypot(point[i].first-point[i+1].first,point[i].second-point[i+1].second);
//        this->dist=min(this->dist,d);
//        return;
//    }

//    for(int i=1;i<n;i++)
//    {
//        if(!label[i])
//        {
//            route.push_back(i);
//            label[i]=1;
//            findDistance(route,n);
//            label[i]=0;
//            route.pop_back();
//        }
//    }
//}
