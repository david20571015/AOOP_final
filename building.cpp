#include<building.h>

void Building::run()
{
    string s=judge.getData(0);
    data.testdata1=s;
    string s2=add1.solve(s);
    data.submit1=s2;
    bool correct=judge.submitData(s2);
    data.correct1=correct;
    data.spendtime1=judge.getSpendTime();

    //Advenced
    s=judge.getData(1);
    data.testdata2=s;
    s2=prime.solve(s);
    data.submit2=s2;
    correct=judge.submitData(s2);
    data.correct2=correct;
    data.spendtime2=judge.getSpendTime();
}
