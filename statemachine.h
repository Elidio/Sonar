#ifndef __STATEMACHINE_H_INCLUDED__   // if x.h hasn't been included yet...
#define __STATEMACHINE_H_INCLUDED__   //   #define this so the compiler knows it has been included

class StateMachine
{
  public:
    virtual void exec();
    int inactive = 0;
    int active = 0;
};

#endif 
