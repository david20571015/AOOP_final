#ifndef FIBONACCIOFFIBONACCI_H
#define FIBONACCIOFFIBONACCI_H

#include "mymath.h"

class FibonacciOfFibonacci : public MyMath
{
public:
    FibonacciOfFibonacci();
    string solve(const string &);
    inline long long int fib(int n);

private:
    stringstream ss;
    int digit[60];
};

#endif // FIBONACCIOFFIBONACCI_H
