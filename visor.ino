#include <Servo.h>
#include <elapsedMillis.h>
#include <NewPing.h>
#include <Wire.h>
#include <SPI.h>
#include <U8glib.h>
#include "servosm.h"
#include "sonar.h"
#include "tela.h"
 
#define SERVO 7 // Porta Digital 6 PWM
 
StateMachine * servosm;
StateMachine * sonar;
StateMachine * tela;

void setup ()
{
  Serial.begin(9600);
  servosm = new ServoSM(6, 50);
  sonar = new SonarSM(4,5,50,50);
  tela = new Tela((SonarSM *) sonar, (ServoSM *) servosm);
}
 
void loop()
{
  servosm->exec();
  sonar->exec();
  tela->exec();
}
 
