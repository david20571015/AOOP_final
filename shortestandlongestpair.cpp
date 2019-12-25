#include "shortestandlongestpair.h"

ShortestAndLongestPair::ShortestAndLongestPair()
{
}

string ShortestAndLongestPair::solve(const string &s)
{
    stringstream ss;
    ss<<s;
    double tmp1,tmp2,tmp3;
    vector<Point> points;
    while(ss>>tmp1>>tmp2>>tmp3)
        points.push_back({tmp1,tmp2,tmp3});

    double max_dis=DBL_MIN,min_dis=DBL_MAX;
    for(int i=0; i<points.size()-1;++i)
        for(int j=i+1;j<points.size();++j)
        {
            max_dis=max(max_dis,sqrtOfDis(points[i],points[j]));
            min_dis=min(min_dis,sqrtOfDis(points[i],points[j]));
        }

    string ans,tmp;
    tmp=to_string(round(sqrt(min_dis)*100)/100);
    ans += (tmp.substr(0, tmp.find('.') + 3) + ' ');
    tmp=to_string(round(sqrt(max_dis)*100)/100);
    ans+=tmp.substr(0, tmp.find('.') + 3);

    return ans;
}

