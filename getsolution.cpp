#include "getsolution.h"

GetSolution::GetSolution()
{

}

string GetSolution::solve(const string &s)
{
    stringstream ss;
    ss << s;
    int n;
    ss >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ss >> a[i][j];
    for (int i = 0; i < n; i++)
        ss >> b[i];

    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
            a[i][k] /= a[i][i];
        b[i] /= a[i][i];

        for (int c = i + 1; c < n; ++c)
        {
            for (int r = i + 1; r < n; ++r)
                a[c][r] -= a[i][r] * a[c][i];
            b[c] -= b[i] * a[c][i];
        }
    }

    for (int i = n - 1; i >= 0; i--)
        for (int j = i - 1; j >= 0; j--)
            b[j] -= b[i] * a[j][i];

    string ans, tmp;

    for (int i = 0; i < n; i++)
    {
        tmp = to_string(round(b[i]*100)/100);
        ans += (tmp.substr(0, tmp.find('.') + 3) + ' ');
    }
    ans.erase(ans.end() - 1);

    return ans;
}
