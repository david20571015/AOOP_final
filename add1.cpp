#include "add1.h"

Add1::Add1()
{
}

string Add1::solve(const string &s)
{
    string ans = ' ' + s + ' ';
    string::iterator i = ans.end() - 1;
    while (i != ans.begin())
    {
        if ((*i) == ' ')
        {
            i--;
            if ((*i) < '9')
                (*i)++;
            else
            {
                (*i) = '0';
                (*(i - 1)) += 1;
                while ((*(i - 1)) == '9' + 1)
                {
                    i--;
                    (*i) = '0';
                    (*(i - 1)) += 1;
                }
                if ((*(i - 1)) == ' ' + 1)
                {
                    (*(i - 1)) = '1';
                    ans.insert(i - 1, ' ');
                }
            }
        }
        i--;
    }
    ans.erase(ans.end() - 1);
    if (ans[0] == ' ')
        return ans.substr(1);
    return ans;
}
