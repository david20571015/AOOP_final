#include "shygame.h"

ShyGame::ShyGame()
{
}
string ShyGame::solve(const string &input)
{
    string ans;
    ss.clear();
    ss << input;
    ss >> n;
    for (M = 1; M < n + 1; M <<= 1)
        ;
    while (ss >> p)
    {
        for (i = 2 * M - 1; i > 0; i--)
        {
            if (i >= M)
                st[i] = 1;
            else
                st[i] = st[i << 1] + st[i << 1 | 1];
        }
        int m, last, prev = 0, s;
        for (i = 1; i <= n; i++)
        {
            m = (p + prev) % (n - i + 1);
            if (m == 0)
                m = n - i + 1;
            prev = m - 1;
            for (s = 1; s < M;)
            {
                if (st[s << 1] < m)
                {
                    m -= st[s << 1];
                    s = s << 1 | 1;
                }
                else
                    s = s << 1;
            }
            last = s - M + 1;
            while (s)
            {
                st[s]--;
                s >>= 1;
            }
        }
        ans += to_string(last) + ' ';
    }
    ans.erase(ans.end() - 1);
    return ans;
}
