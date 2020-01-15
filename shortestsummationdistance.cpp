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

        int tmp = int(round((dp[(1 << n) - 1] - int(dp[(1 << n) - 1])) * 100));

        ans += to_string((int)dp[(1 << n) - 1]) + "." + to_string(tmp / 10) + to_string(tmp % 10) + " ";
        delete[] dp;
    }
    ans.erase(ans.end() - 1);
    return ans;
}

