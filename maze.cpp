#include "maze.h"

Maze::Maze()
{

}

string Maze::solve(const string &s)
{
    ss.clear();
    ss<<s;
    int row, col;
    ss >> row >> col;

    char maze[100][100];

    char tmp;
    pair<int, int> start, end;
    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
        {
            ss >> tmp;
            maze[i][j] = tmp;
            if (tmp == 'S')
                start = make_pair(i, j);
            else if (tmp == 'E')
            {
                end = make_pair(i, j);
                maze[i][j] = '0';
            }
        }
    char route[100][100];
    memcpy(route,maze,sizeof(maze));

    pair<int, int> curr(start);
    stack<pair<int, int>> path;
    path.push(curr);

    while (curr != end)
    {
        if (maze[curr.first][curr.second + 1] == '0')
        {
            maze[curr.first][curr.second + 1] = '1';
            ++curr.second;
            path.push(curr);
        }
        else if (maze[curr.first + 1][curr.second] == '0')
        {
            maze[curr.first + 1][curr.second] = '1';
            ++curr.first;
            path.push(curr);
        }
        else if (maze[curr.first][curr.second - 1] == '0')
        {
            maze[curr.first][curr.second - 1] = '1';
            --curr.second;
            path.push(curr);
        }
        else if (maze[curr.first - 1][curr.second] == '0')
        {
            maze[curr.first - 1][curr.second] = '1';
            --curr.first;
            path.push(curr);
        }
        else
        {
            maze[curr.first][curr.second] = '3';
            path.pop();
            curr = path.top();
        }
    }

    while (!path.empty())
    {
        route[path.top().first][path.top().second] = '1';
        path.pop();
    }
    route[start.first][start.second] = 'S';
    route[end.first][end.second] = 'E';

    string ans;

    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
        {
            ans += route[i][j];
            ans += ' ';
        }
    ans.erase(ans.end() - 1);

    return ans;
}
