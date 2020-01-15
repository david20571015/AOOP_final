#include "shygame.h"

ShyGame::ShyGame()
{
}

string ShyGame::solve(const string &s)
{
    ss.clear();
    ss << s;
    int n;
    ss >> n;
    int k;
    int step;
    string ans;
    while (ss >> k)
    {
        if (k == 1)
        {
            ans += to_string(n) + " ";
            continue;
        }

        int a = 0;
        for (int i = 2; i <= n;)
        {
            if (a + k >= i)
            {
                a = (a + k) % i++;
                continue;
            }
            step = (i - a - 2) / (k - 1);
            if (i + step > n)
            {
                a += (n - i + 1) * k;
                break;
            }
            i += step;
            a += step * k;
        }
        ans += to_string(a % n + 1) + " ";
    }

    ans.erase(ans.end() - 1);
    return ans;
}
