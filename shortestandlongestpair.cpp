#include "shortestandlongestpair.h"

ShortestAndLongestPair::ShortestAndLongestPair()
{
}

string ShortestAndLongestPair::solve(const string &s)
{
    ss.clear();
    ss << s;

    int count = 0;
    while (ss >> x[count] >> y[count] >> z[count++])
        ;

    double max_dis = DBL_MIN, min_dis = DBL_MAX;
    for (int i = 0; i < count - 2; ++i)
        for (int j = i + 1; j < count - 1; ++j)
        {
            dx = x[i] - x[j];
            dy = y[i] - y[j];
            dz = z[i] - z[j];
            dis = dx * dx + dy * dy + dz * dz;
            max_dis = max(max_dis, dis);
            min_dis = min(min_dis, dis);
        }

    max_dis = sqrt(max_dis);
    min_dis = sqrt(min_dis);

    int tmp1 = int(round((min_dis - int(min_dis)) * 100));
    int tmp2 = int(round((max_dis - int(max_dis)) * 100));

    return to_string((int)min_dis) + "." + to_string(tmp1 / 10) + to_string(tmp1 % 10) + " " + to_string((int)max_dis) + "." + to_string(tmp2 / 10) + to_string(tmp2 % 10);
}

