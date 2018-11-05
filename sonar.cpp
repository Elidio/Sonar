#include "sonar.h"

SonarSM::SonarSM(int trigger, int echo, int speed, int distance)
{
  ping = new NewPing(trigger, echo, distance);
  this->speed = speed;
  State = &SonarSM::pulse;
  reading = -1;
}

void SonarSM::exec()
{
  (this->*State)();
}

void SonarSM::pulse()
{
  if (timer > speed)
  {
    reading = ping->ping_cm();
    timer = 0;
    Serial.println(reading);
  }
}

int SonarSM::getreading()
{
  if(reading < 200)
    return reading;
  else
    return 0;
}

