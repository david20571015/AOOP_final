#include "mystring.h"

MyString::MyString()
{
}

MyString::~MyString()
{
}

string preProcess(const string &s)
{
    string tmp = s;
    int punct_pos;
    while ((punct_pos = tmp.find_first_of(",.?!")) != string::npos)
        tmp.erase(tmp.begin() + punct_pos);
    transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
    return tmp;
}
