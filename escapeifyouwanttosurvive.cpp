#include "escapeifyouwanttosurvive.h"

EscapeIfYouWantToSurvive::EscapeIfYouWantToSurvive()
{
}

EscapeIfYouWantToSurvive::~EscapeIfYouWantToSurvive()
{
}

string EscapeIfYouWantToSurvive::solve(const string &s)
{
    stringstream ss;
    ss << s;
    int row, col;
    ss >> row >> col;

    vector<string> maze;
    string tmp;

    while (ss >> tmp)
        maze.push_back(tmp);

    vector<vector<short>> fire(row, vector<short>(col, 0));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (maze[i][j] == '#')
                fire[i][j] = -1;
    vector<vector<short>> joe(fire);

    pair<short, short> joe_pos, f;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            if (maze[i][j] == 'J')
            {
                joe_pos = make_pair(i, j);
                joe[i][j] = 1;
            }
            else if (maze[i][j] == 'F')
            {
                f = make_pair(i, j);
                fire[i][j] = 1;
            }
        }

    queue<pair<short, short>> fireRoute;
    fireRoute.push(f);

    pair<short, short> curr;
    short time;
    while (!fireRoute.empty())
    {
        curr = fireRoute.front();
        time = fire[curr.first][curr.second];

        if (curr.first > 0 && fire[curr.first - 1][curr.second] == 0)
        {
            fire[curr.first - 1][curr.second] = time + 1;
            fireRoute.push(make_pair(curr.first - 1, curr.second));
        }
        if (curr.first < row - 1 && fire[curr.first + 1][curr.second] == 0)
        {
            fire[curr.first + 1][curr.second] = time + 1;
            fireRoute.push(make_pair(curr.first + 1, curr.second));
        }
        if (curr.second > 0 && fire[curr.first][curr.second - 1] == 0)
        {
            fire[curr.first][curr.second - 1] = time + 1;
            fireRoute.push(make_pair(curr.first, curr.second - 1));
        }
        if (curr.second < col - 1 && fire[curr.first][curr.second + 1] == 0)
        {
            fire[curr.first][curr.second + 1] = time + 1;
            fireRoute.push(make_pair(curr.first, curr.second + 1));
        }
        fireRoute.pop();
    }

    queue<pair<short, short>> joeRoute;
    joeRoute.push(joe_pos);
    while (!joeRoute.empty())
    {
        curr = joeRoute.front();
        time = joe[curr.first][curr.second] + 1;
        if (curr.first == 0 || curr.first == row - 1 || curr.second == 0 || curr.second == col - 1)
            return to_string(time - 1);

        if (curr.first > 0 && joe[curr.first - 1][curr.second] == 0 && (time < fire[curr.first - 1][curr.second] || !fire[curr.first - 1][curr.second]))
        {
            joe[curr.first - 1][curr.second] = time;
            joeRoute.push(make_pair(curr.first - 1, curr.second));
        }
        if (curr.first < row - 1 && joe[curr.first + 1][curr.second] == 0 && (time < fire[curr.first + 1][curr.second] || !fire[curr.first + 1][curr.second]))
        {
            joe[curr.first + 1][curr.second] = time;
            joeRoute.push(make_pair(curr.first + 1, curr.second));
        }
        if (curr.second > 0 && joe[curr.first][curr.second - 1] == 0 && (time < fire[curr.first][curr.second - 1] || !fire[curr.first][curr.second - 1]))
        {
            joe[curr.first][curr.second - 1] = time;
            joeRoute.push(make_pair(curr.first, curr.second - 1));
        }
        if (curr.second < col - 1 && joe[curr.first][curr.second + 1] == 0 && (time < fire[curr.first][curr.second + 1] || !fire[curr.first][curr.second + 1]))
        {
            joe[curr.first][curr.second + 1] = time;
            joeRoute.push(make_pair(curr.first, curr.second + 1));
        }
        joeRoute.pop();
    }

    return "N";
}
