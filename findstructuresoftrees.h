#ifndef FINDSTRUCTURESOFTREES_H
#define FINDSTRUCTURESOFTREES_H

#include "mytree.h"

class FindStructuresOfTrees : public MyTree
{
public:
    FindStructuresOfTrees();
    string solve(const string &);
    int search(char arr[],int x,int n);
    void printPostOrder(char inOrder[],char preOrder[],int n);
    virtual ~FindStructuresOfTrees(){}
private:
    char inO[100],preO[100];
    string ans;
};

#endif // FINDSTRUCTURESOFTREES_H
