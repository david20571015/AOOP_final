#include "shygame.h"

ShyGame::ShyGame()
{
}
string ShyGame::solve(string input)
{
    string s, ans, st;
    stringstream ss, t;
    int m, n;
    queue<int> q;
    ss.clear();
    ss << input;
    ss >> n;
    while (ss >> m)
    {
        for (int i = 0; i < n; i++)
            q.push(i + 1);
        while (q.size() > 1)
        {
            for (int i = 0; i < m - 1; i++)
            {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        t.clear();
        t << q.front();
        t >> st;
        ans += st;
        ans += " ";
        q.pop();
    }
    ans.erase(ans.end() - 1);
    return ans;
}
