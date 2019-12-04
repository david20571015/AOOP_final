#ifndef BUILDING_H
#define BUILDING_H

#include "judge.h"
#include "data.h"
#include "floor.h"

#include "problems.h"

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
