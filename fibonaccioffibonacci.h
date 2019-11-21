#ifndef FIBONACCIOFFIBONACCI_H
#define FIBONACCIOFFIBONACCI_H

#include"mymath.h"

class FibonacciOfFibonacci : public MyMath
{
public:
    FibonacciOfFibonacci();
    string solve(string);
    long long int fib(int n);
private:
    int digit[60];
};

#endif // FIBONACCIOFFIBONACCI_H
