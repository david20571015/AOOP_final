#include "longestpeekpalindrome.h"

LongestPeekPalindrome::LongestPeekPalindrome()
{

}

string LongestPeekPalindrome::solve(const string &s)
{
    string tmp = s;
    preProcess(tmp);
    int N = tmp.length();
    if (N == 0)
        return "";

    N = 2 * N + 1;

    L[0] = 0;
    L[1] = 1;
    int C = 1;
    int R = 2;
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int diff = -1;

    for (int i = 2; i < N; i++)
    {
        L[i] = 0;
        diff = R - i;
        if (diff > 0)
            L[i] = min(L[2 * C - i], diff);

        while ((i + L[i]) < N && (i - L[i]) > 0 && (((i + L[i]) & 1) || (tmp[(i + L[i] + 1) / 2] == tmp[(i - L[i] - 1) / 2])))
            L[i]++;

        if (L[i] > maxLPSLength)
        {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }

        if (i + L[i] > R)
        {
            C = i;
            R = i + L[i];
        }
    }

    return tmp.substr((maxLPSCenterPosition - maxLPSLength) / 2, maxLPSLength);
}
