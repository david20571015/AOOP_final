#include "minesweeper.h"

Minesweeper::Minesweeper()
{
}

string Minesweeper::solve(const string &s)
{
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

    //    string mine,tmp;
    //    while(ss>>tmp)
    //        mine+=tmp;

    //    int direct[8][2]={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
    //    vector<vector<char>> count(row,vector<char>(col,'0'));

    //    for(int i=0;i<static_cast<int>(mine.size());i++)
    //    {
    //        if(mine[i]=='*')
    //        {
    //            count.at(i%row).at(i/row)='*';
    //            for(int j=0;j<8;j++)
    //                if((i%row+direct[j][0])>=0 && (i%row+direct[j][0])<row &&
    //                   (i/row+direct[j][1])>=0 && (i/row+direct[j][1])<col &&
    //                   count.at(i%row+direct[j][0]).at(i/row+direct[j][1])!='*')
    //                    count[i%row+direct[j][0]][i/row+direct[j][1]]++;
    //        }
    //    }

    //    string ans;
    //    for(int i=0;i<col;i++)
    //    {
    //        for(int j=0;j<row;j++)
    //            ans+=count[j][i];
    //        ans+=' ';
    //    }

    //    ans.erase(ans.end()-1);

    //    return ans;
}
