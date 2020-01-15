#include "subtract1.h"

Subtract1::Subtract1()
{

}

string Subtract1::solve(const string &s)
{
    string ans = ' ' + s + ' ';
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
