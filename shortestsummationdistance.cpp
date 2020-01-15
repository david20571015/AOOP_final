#include "shortestsummationdistance.h"

ShortestSummationDistance::ShortestSummationDistance()
{
}

string ShortestSummationDistance::solve(const string &s)
{
    ss.clear();
    ss << s;
    string ans;

    int n;

    while (ss >> n)
    {
        n *= 2;
        for (int i = 0; i < n; i++)
            ss >> x[i] >> y[i];

        double disSqrt[100][100];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                disSqrt[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));

        double *dp = new double[1 << n];
        dp[0] = 0;
        for (int s = 1; s < (1 << n); s++)
        {
            dp[s] = 0x3f3f3f3f;
            int i = 0, cnt = 0;
            for (int j = 0; j < n; j++)
                if (s & (1 << j))
                {
                    i = j;
                    cnt++;
                }
            if (cnt & 1)
                continue;
            for (int j = 0; j < i; j++)
                if (s & (1 << j))
                    dp[s] = min(dp[s], disSqrt[i][j] + dp[s ^ (1 << i) ^ (1 << j)]);
        }

        string s1 = to_string(dp[(1 << n) - 1]);
        delete[] dp;
        s1 = s1.substr(0, s1.find(".") + 4);
        int strsize = s1.size();
        if (s1[strsize - 1] > '4')
            if (s1[strsize - 2] < '9')
                s1[strsize - 2]++;
            else
            {
                s1[strsize - 2] = '0';
                if (s1[strsize - 3] < '9')
                    s1[strsize - 3]++;
                else
                {
                    s1[strsize - 3] = '0';
                    for (int i = 0; i <= strsize - 5; i++)
                    {
                        if (s1[strsize - 5 - i] < '9')
                        {
                            s1[strsize - 5 - i]++;
                            break;
                        }
                        else
                            s1[strsize - 5 - i] = '0';
                    }
                }
            }
        s1.pop_back();

        ans += s1 + ' ';
    }

    ans.erase(ans.end() - 1);
    return ans;
}

