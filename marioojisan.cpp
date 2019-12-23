#include "marioojisan.h"

MarioOjisan::MarioOjisan()
{

}

string MarioOjisan::solve(const string &s)
{
    stringstream ss;
    string ans;
    int n, result, pre_sum, max;
    ss << s;
    ss >> n;
    max = 1;
    int *coin = new int[n];
    for (int i = 0; i < n; i++)
        ss >> coin[i];
    for (int i = n - 1; i >= 0; i--)
    {
        result = 1;
        pre_sum = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (coin[i] > pre_sum + coin[j])
            {
                result++;
                pre_sum += coin[j];
            }
        }
        if (result > max)
            max = result;
    }
    ans = to_string(max);
    while (ss >> n)
    {
        max = 1;
        int *coin = new int[n];
        for (int i = 0; i < n; i++)
            ss >> coin[i];
        for (int i = n - 1; i >= 0; i--)
        {
            result = 1;
            pre_sum = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                if (coin[i] > pre_sum + coin[j])
                {
                    result++;
                    pre_sum += coin[j];
                }
            }
            if (result > max)
                max = result;
        }
        ans += to_string(max);
    }
    return ans;
}
