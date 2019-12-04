#include "escape.h"

Escape::Escape()
{
    maze=new char*[1000];
    for(int i=0;i<1000;i++)
        maze[i]=new char[1000];

    step=new short int*[1000];
    for(int i=0;i<1000;i++){
        step[i]=new short int[1000];
        memset(step[i],0,1000);
    }
}

Escape::~Escape()
{
    for(int i=0;i<1000;i++)
    {
        delete []maze[i];
        delete []step[i];
    }
    delete []maze;
    delete []step;
}

string Escape::solve(string s)
{
    stringstream ss;
    ss<<s;
    int row,col;
    ss>>row>>col;




}
