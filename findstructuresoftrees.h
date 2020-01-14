#ifndef FINDSTRUCTURESOFTREES_H
#define FINDSTRUCTURESOFTREES_H

#include "mytree.h"

class FindStructuresOfTrees : public MyTree
{
public:
    FindStructuresOfTrees();
    string solve(const string &);
    inline int search(char arr[],int x,int n);
    void printPostOrder(char inOrder[],char preOrder[],const int &n);
    virtual ~FindStructuresOfTrees(){}
private:
    stringstream ss;
    char inO[500],preO[500];
    string ans;
};

#endif // FINDSTRUCTURESOFTREES_H
