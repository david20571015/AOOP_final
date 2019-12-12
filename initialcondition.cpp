#include "initialcondition.h"

InitialCondition::InitialCondition()
{

}

void InitialCondition::setCondition(string s, int a, int b, int d)
{
    Id = s;
    Nowfloor=a;
    Dest=b;
    Number=d;
}
