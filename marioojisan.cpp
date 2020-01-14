#include "marioojisan.h"

MarioOjisan::MarioOjisan()
{

}

string MarioOjisan::solve(const string &s)
{
    ss.clear();
    ss << s;
    ss >> n;
    ss >> maxn;
    for (int i = 1; i < n; i++)
        ss >> coin[i];
    result = 2;
    for (int i = 1; i < n - 1; i++)
        if (maxn + coin[i] < coin[i + 1])
        {
            maxn += coin[i];
            result++;
        }
    return to_string(result);
}
