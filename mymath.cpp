#include "mymath.h"

MyMath::MyMath()
{
}

MyMath::~MyMath()
{
}

bool MyMath::isPrime(const int &data)
{
    int i;

    if (data%2 == 0 || data%3 == 0)
        return false;

    for (i=5; i*i<=data; i+=6)
        if (data%i == 0 || data%(i+2) == 0)
           return false;
    return true;
}
