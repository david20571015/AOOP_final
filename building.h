#ifndef BUILDING_H
#define BUILDING_H
#include "judge.h"
#include "data.h"
#include "floor.h"
#include "add1.h"
#include "prime.h"
#include "longestpair.h"
#include "shygame.h"
#include "fibonaccioffibonacci.h"
#include "findfactorial.h"
#include "shortestsummation.h"

#include <string>

class Building
{
public:
    Building();
    void run(int n);
    Data getData() { return data; }
    ~Building();

private:
    Judge judge;
    Data data;
    Floor *floor[30];
};

#endif // BUILDING_H
