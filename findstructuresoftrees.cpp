#include "findstructuresoftrees.h"

FindStructuresOfTrees::FindStructuresOfTrees()
{

}

int FindStructuresOfTrees::search(char arr[],int x,int n)
{
    int i;
    for(i=0;i<n;i++)
        if(arr[i]==x)
         return i;
    return -1;
}

void FindStructuresOfTrees::printPostOrder(char inOrder[],char preOrder[],const int &n)
{
    int rootNode=search(inOrder,preOrder[0],n);
    if(rootNode)
        printPostOrder(inOrder,preOrder+1,rootNode);
    if(rootNode!=n-1)
        printPostOrder(inOrder+rootNode+1,preOrder+rootNode+1,n-rootNode-1);
    ans+=preOrder[0];
}

string FindStructuresOfTrees::solve(const string &s)
{
    ss.clear();
    ss<<s;
    string pre,in;
    ss>>pre>>in;
    ans="";
    for(int i=0;i<pre.size();i++)
    {
        inO[i]=in[i];
        preO[i]=pre[i];
    }

    printPostOrder(inO,preO,pre.size());

    return ans.substr(0,pre.size());
}
