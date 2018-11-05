#ifndef __TELA_H_INCLUDED__   // if x.h hasn't been included yet...
#define __TELA_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <Wire.h>
#include <SPI.h>
#include <U8glib.h>
#include "servosm.h"
#include "sonar.h"

class Tela : public StateMachine
{
    typedef void (Tela::*STATE)();
  public:
    Tela(SonarSM * sonar, ServoSM * servosm); // por enquanto fica na hardserial, mas dá para mudar isso para por na softserial
    void exec();
    
  private:
    STATE State;
    SonarSM * sonar;
    ServoSM * servosm;
    void draw(void);
    void polar(int r, int theta);
    int speed;
    elapsedMillis timer;
    int x;
    int y;
    int reading[180][2];

    void show(void);
    void wait(void);
};

#endif
