#include "getsignature.h"

GetSignature::GetSignature()
{

}

string GetSignature::solve(const string &s)
{
    ss.clear();
    ss << s;
    int c = 0, people;
    ss >> people;
    while (ss >> v[++c])
        ;

    int keepnode = 0;
    int length = 0;
    int node = 0;
    int count = 0;

    memset(from, 0, people);

    for (int i = 0; i < people; i++)
    {
        asktosign[v[2 * i + 1] - 1] = v[2 * (i + 1)];
        from[v[2 * (i + 1)] - 1] = true;
    }

    for (int i = 0; i < people; i++)
    {
        if (from[i])
            continue;
        node = i;
        count = 0;
        memset(check, 0, people);

        while (!check[node])
        {
            check[node] = true;
            count++;
            node = asktosign[node] - 1;
        }

        if (length < count)
        {
            keepnode = i;
            length = count;
        }
        else if ((length == count) && i < keepnode)
        {
            keepnode = i;
            length = count;
        }
    }

    return to_string(keepnode + 1);
}

//string GetSignature::solve(const string &s)
//{
//    ss.clear();
//    ss<<s;
//    int n;
//    ss >> n;
//    vector<int> cele(n + 1), sign(n + 1, 0);
//    vector<bool> traversal(n + 1, 0);

//    int index = 0;
//    while (ss >> index && ss >> cele[index])
//        ;

//    int now;
//    for (int i = n; i >= 1; i--)
//    {
//        now = i;
//        traversal[now] = 1;
//        while (!traversal[cele[now]])
//        {
//            now = cele[now];
//            traversal[now] = 1;
//            sign[i]++;
//        }
//        std::fill(traversal.begin(), traversal.end(), 0);
//    }

//    return to_string(max_element(sign.begin(), sign.end()) - sign.begin());
//}
