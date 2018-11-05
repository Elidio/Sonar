#ifndef __SERVOSM_H_INCLUDED__   // if x.h hasn't been included yet...
#define __SERVOSM_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include "statemachine.h"
#include <elapsedMillis.h>
#include <Servo.h>

class ServoSM : public StateMachine
{
    typedef void (ServoSM::*STATE)();
  public:
    ServoSM(int port, int speed); // por enquanto fica na hardserial, mas dá para mudar isso para por na softserial
    void exec();
    int getangle();
  private:
    STATE State;
    elapsedMillis timer;
    int pos;
    int speed;
    Servo s;
    void going();
    void coming();
};

#endif

