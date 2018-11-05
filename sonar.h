#ifndef __SONAR_H_INCLUDED__   // if x.h hasn't been included yet...
#define __SONAR_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <elapsedMillis.h>
#include <NewPing.h>
#include "statemachine.h"

class SonarSM : public StateMachine
{
    typedef void (SonarSM::*STATE)();
  public:
    SonarSM(int trigger, int echo, int speed, int distance); // por enquanto fica na hardserial, mas dá para mudar isso para por na softserial
    void exec();
    int getreading();
  private:
    STATE State;
    elapsedMillis timer;
    int reading;
    int speed;
    NewPing * ping;
    void pulse();
};

#endif
