#include "largestroot.h"

LargestRoot::LargestRoot()
{
}

string LargestRoot::solve(const string &s)
{
    ss.clear();
    ss<<s;
    int c = 0;

    while (ss >> node[c++]);

    value[7] = node[7];
    value[8] = node[8];
    value[9] = node[9];
    value[10] = node[10];
    value[11] = node[11];
    value[12] = node[12];
    value[13] = node[13];
    value[14] = node[14];

    value[3] = node[3] + (value[7] + value[8]) / 2;
    value[4] = node[4] + (value[9] + value[10]) / 2;
    value[5] = node[5] + (value[11] + value[12]) / 2;
    value[6] = node[6] + (value[13] + value[14]) / 2;

    value[1] = node[1] + (value[3] + value[4]) / 2;
    value[2] = node[2] + (value[5] + value[6]) / 2;

    value[0] = node[0] + (value[1] + value[2]) / 2;

    int maxn = 0;
    for (int i = 1; i < 15; i++)
        maxn = (value[maxn] < value[i]) ? i : maxn;

    string ans;
    ss.clear();
    ss << fixed << setprecision(3) << value[maxn];
    ss >> ans;

    return to_string(maxn+1) + ':' + ans;
}
