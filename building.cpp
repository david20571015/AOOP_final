#include <building.h>

Building::Building()
{
    floor[0] = new Floor(new Add1());
    floor[1] = new Floor(new Prime());
    floor[2] = new Floor(new LongestPair());
    floor[3] = new Floor(new ShyGame());
    floor[4] = new Floor(new FibonacciOfFibonacci());
    floor[8] = new Floor(new findfactorial());
    floor[9] = new Floor(new shortestsummation());
}

void Building::run(int n)
{
    string s = judge.getData(n);
    data.testdata = s;
    string s2 = floor[n]->p->solve(s);
    data.submit = s2;
    bool correct = judge.submitData(s2);
    data.correct = correct;
    data.spendtime = judge.getSpendTime();
}

Building::~Building()
{
    for (int i = 0; i < 30; i++)
        delete floor[i];
}
