#include "longestcommonsubstring.h"

LongestCommonSubstring::LongestCommonSubstring()
{

}

string LongestCommonSubstring::solve(const string &s)
{
    string tmp = s;
    preProcess(tmp);

    int space_pos = tmp.find(" ");
    string str[2] = {tmp.substr(0, space_pos), tmp.substr(space_pos + 1)};

    int len[100][100];
    int z = 0;
    string ans;

    for (int i = 0; i < str[0].size(); i++)
        for (int j = 0; j < str[1].size(); j++)
        {
            if (str[0][i] == str[1][j])
            {
                if (!(i && j))
                    len[i][j] = 1;
                else
                    len[i][j] = len[i - 1][j - 1] + 1;

                if ((len[i][j] > z) || (len[i][j] == z && str[0].substr(i - z + 1, z) < ans))
                {
                    z = len[i][j];
                    ans = str[0].substr(i - z + 1, z);
                }
            }
            else
                len[i][j] = 0;
        }
    return ans;
}
