#include "minesweeper.h"

Minesweeper::Minesweeper()
{
}

string Minesweeper::solve(const string &s)
{
    return s;
//    stringstream ss;
//    ss << s;
//    int col, row;
//    ss >> col >> row;

//    vector<string> mine(col + 2);
//    int count = 0;
//    mine[0] = string(row + 2, '0');
//    string tmp;
//    while (ss >> tmp)
//    {
//        for (int i = 0; i < row; i++)
//            if (tmp[i] == '.')
//                tmp[i] = '0';
//        tmp = '0' + tmp + '0';
//        mine[++count] = tmp;
//    }
//    mine[++count] = string(row + 2, '0');

//    for (int c = 1; c <= col; c++)
//        for (int r = 1; r <= row; r++)
//        {
//            if (mine[c][r] == '*')
//            {
//                if (mine[c - 1][r - 1] != '*')
//                    mine[c - 1][r - 1]++;
//                if (mine[c - 1][r] != '*')
//                    mine[c - 1][r]++;
//                if (mine[c - 1][r + 1] != '*')
//                    mine[c - 1][r + 1]++;
//                if (mine[c][r - 1] != '*')
//                    mine[c][r - 1]++;
//                if (mine[c][r + 1] != '*')
//                    mine[c][r + 1]++;
//                if (mine[c + 1][r - 1] != '*')
//                    mine[c + 1][r - 1]++;
//                if (mine[c + 1][r] != '*')
//                    mine[c + 1][r]++;
//                if (mine[c + 1][r + 1] != '*')
//                    mine[c + 1][r + 1]++;
//            }
//        }

//    string ans;
//    for (int c = 1; c <= col; c++)
//        ans += mine[c].substr(1, row) + ' ';
//    ans.erase(ans.end() - 1);
//    return ans;

    stringstream ss;
    ss << s;
    int col, row;
    ss >> col >> row;

    vector<string> mine(col + 2);
    int count = 0;
    mine[0] = string(row + 2, '0');
    string tmp;
    while (ss >> tmp)
    {
        for (int i = 0; i < row; i++)
            if (tmp[i] == '.')
                tmp[i] = '0';
        tmp = '0' + tmp + '0';
        mine[++count] = tmp;
    }
    mine[++count] = string(row + 2, '0');

    for (int c = 1; c <= col; c++)
        for (int r = 1; r <= row; r++)
        {
            if (mine[c][r] == '*')
            {
                if (mine[c - 1][r - 1] != '*')
                    mine[c - 1][r - 1]++;
                if (mine[c - 1][r] != '*')
                    mine[c - 1][r]++;
                if (mine[c - 1][r + 1] != '*')
                    mine[c - 1][r + 1]++;
                if (mine[c][r - 1] != '*')
                    mine[c][r - 1]++;
                if (mine[c][r + 1] != '*')
                    mine[c][r + 1]++;
                if (mine[c + 1][r - 1] != '*')
                    mine[c + 1][r - 1]++;
                if (mine[c + 1][r] != '*')
                    mine[c + 1][r]++;
                if (mine[c + 1][r + 1] != '*')
                    mine[c + 1][r + 1]++;
            }
        }

    string ans;
    for (int c = 1; c <= col; c++)
        ans += mine[c].substr(1, row) + ' ';
    ans.erase(ans.end() - 1);
    return ans;
}
