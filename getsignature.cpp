#include "getsignature.h"

GetSignature::GetSignature()
{

}

string GetSignature::solve(const string &s)
{
    stringstream ss(s);
        int n;
        ss >> n;
        vector<int> cele(n + 1), sign(n + 1, 0);
        vector<bool> traversal(n + 1, 0);

        int index = 0;
        while (ss >> index && ss >> cele[index])
            ;

        int now;
        for (int i = n; i >= 1; i--)
        {
            now = i;
            traversal[now] = 1;
            while (!traversal[cele[now]])
            {
                now = cele[now];
                traversal[now] = 1;
                sign[i]++;
            }
            std::fill(traversal.begin(), traversal.end(), 0);
        }

        return to_string(max_element(sign.begin(), sign.end()) - sign.begin());
}
