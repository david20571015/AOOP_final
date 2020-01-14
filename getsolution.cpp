#include "getsolution.h"

GetSolution::GetSolution()
{

}

string GetSolution::solve(const string &s)
{
    ss.clear();
    ss<<s;
    ss >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ss >> a[i][j];
    for (int i = 0; i < n; i++)
        ss >> a[i][n];

    double tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][i] > -1e-9 && a[i][i] < 1e-9)
            {
                if ((a[j][i] > 1e-9 || a[j][i] < -1e-9) && (a[i][j] > 1e-9 || a[i][j] < -1e-9))
                    for (int k = 0; k < n + 1; k++)
                    {
                        tmp = a[j][k];
                        a[j][k] = a[i][k];
                        a[i][k] = tmp;
                    }
            }
            if ((a[i][i] < -1e-9 || a[i][i] > 1e-9) && (a[j][i] > 1e-9 || a[j][i] < -1e-9))
                for (int k = n; k >= i; k--)
                    a[j][k] -= a[i][k] * a[j][i] / a[i][i];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        a[i][n] /= a[i][i];
        a[i][i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if ((a[j][i] > 1e-9 || a[j][i] < -1e-9))
                for (int k = n; k >= i; k--)
                    a[j][k] -= a[i][k] * a[j][i];
        }
    }

    int strsize;
    string s1, ans;
    for (int i = 0; i < n; i++)
    {
        if (a[i][n] > -1e-9 && a[i][n] < 1e-9)
            a[i][n] = 0;

        s1 = to_string(a[i][n]);
        s1 = s1.substr(0, s1.find(".") + 4);
        strsize = s1.size();
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
