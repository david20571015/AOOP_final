#include "minesweeper.h"

Minesweeper::Minesweeper()
{
}

string Minesweeper::solve(string s)
{
    stringstream ss;
    ss<<s;
    int col,row;
    ss>>col>>row;
    string mine,tmp;
    while(ss>>tmp)
        mine+=tmp;

    int direct[8][2]={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
    vector<vector<char>> count(row,vector<char>(col,'0'));


    for(int i=0;i<static_cast<int>(mine.size());i++)
    {
        if(mine[i]=='*')
        {
            count.at(i%row).at(i/row)='*';
            for(int j=0;j<8;j++)
                if((i%row+direct[j][0])>=0 && (i%row+direct[j][0])<row &&
                   (i/row+direct[j][1])>=0 && (i/row+direct[j][1])<col &&
                   count.at(i%row+direct[j][0]).at(i/row+direct[j][1])!='*')
                    count[i%row+direct[j][0]][i/row+direct[j][1]]++;
        }
    }

    string ans;
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
            ans+=count[j][i];
        ans+=' ';
    }


    ans.erase(ans.end()-1);

    return ans;
}
