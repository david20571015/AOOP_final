#include "subtract1.h"

Subtract1::Subtract1()
{

}

string Subtract1::solve(const string &s)
{
    string ans = ' ' + s + ' ';

    if (s.find_first_of('-') != string::npos)
    {
        ss.clear();
        ss << s;
        int n;
        string ans1;
        while (ss >> n)
            ans1 += to_string(n - 1) + ' ';
        ans1.erase(ans1.end() - 1);
        return ans1;
    }

    string::iterator i = ans.end() - 1;
    while (i != ans.begin())
    {
        if ((*i) == ' ')
        {
            i--;
            if ((*i) > '0')
                (*i)--;
            else
            {
                (*i) = '9';
                (*(i - 1)) -= 1;
                while ((*(i - 1)) == '0' - 1)
                {
                    i--;
                    (*i) = '9';
                    (*(i - 1)) -= 1;
                }
                if ((*(i - 1)) == '0' && (*(i - 2) == ' '))
                    ans.erase(i - 1);
            }
        }
        i--;
    }

    ans.erase(ans.end() - 1);
    if (ans[0] == ' ')
        return ans.substr(1);
    return ans;
}
