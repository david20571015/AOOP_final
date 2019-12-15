#include "longestpeekpalindrome.h"

LongestPeekPalindrome::LongestPeekPalindrome()
{

}

string LongestPeekPalindrome::solve(const string &s)
{
    string tmp = s;
    int len = s.size();
    if (len == 1)
        return s;
    for (int i = 0; i < len; i++)
        if (ispunct(tmp[i]))
        {
            tmp.erase(i--, 1);
            len--;
        }

    transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);

    string str = "^";
    for (int i = 0; i < len; i++)
        str += ("#" + tmp.substr(i, 1));
    str += "#$";

    len = len * 2 + 1;
    vector<int> p(len, 0);
    int c = 0, r = 0;
    for (int i = 1; i < len - 1; i++)
    {
        p[i] = (r > i) ? min(r - i, p[2 * c - i]) : 0;
        while (str[i + 1 + p[i]] == str[i - 1 - p[i]])
            p[i]++;
        if (i + p[i] > r)
        {
            c = i;
            r = i + p[i];
        }
    }

    string ans, comp;

    for (int i = 0; i < len; i += 2)
    {
        comp = tmp.substr((i - 1 - p[i]) / 2, p[i]);
        if (ans.size() <= comp.size() && (ans + string(comp.size() - ans.size(), 127)).compare(comp) > 0)
            ans = comp;
    }
    return ans;
}
