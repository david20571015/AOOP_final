#include "mystring.h"

MyString::MyString()
{
}

MyString::~MyString()
{
}

void MyString::preProcess(string &s)
{
    int punct_pos;
    while ((punct_pos = s.find_first_of(",.?!")) != string::npos)
        s.erase(s.begin() + punct_pos);
}
