#ifndef ESCAPE_H
#define ESCAPE_H

#include"myother.h"

class EscapeIfYouWantToSurvive : public MyOther
{
public:
    EscapeIfYouWantToSurvive();
    virtual ~EscapeIfYouWantToSurvive();
    string solve(string);
};

#endif // ESCAPE_H
