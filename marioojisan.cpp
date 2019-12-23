#include "marioojisan.h"

MarioOjisan::MarioOjisan()
{

}

string MarioOjisan::solve(const string &s)
{
    string ans;
    ss.clear();
    ss << s;
    ss >> n;
    ss >> max;
    for (int i = 1; i < n; i++)
        ss >> coin[i];
    result = 1;
    for (int i = 1; i < n - 1; i++)
    {
        if(max + coin[i] < coin[i + 1])
        {
            max += coin[i];
            result++;
        }
    }
    ans = to_string(result + 1);
    while (ss >> n)
    {
        int *coin = new int[n];
        for (int i = 0; i < n; i++)
            ss >> coin[i];
        max = coin[0];
        result = 1;
        for (int i = 1; i < n - 1; i++)
        {
            if(max + coin[i] < coin[i + 1])
            {
                max += coin[i];
                result++;
            }
        }
        ans += " " + to_string(max);
    }
    return ans;
}
