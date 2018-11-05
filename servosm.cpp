#include "servosm.h"


ServoSM::ServoSM(int port, int speed)
{
  s.attach(port);
  pos = 90;
  s.write(pos);
  State = &ServoSM::going;
  timer = 0;
  this->speed = speed;
}

void ServoSM::exec()
{
  (this->*State)();
}

void ServoSM::going()
{
  if (timer > speed)
  {
    pos ++;
    s.write(pos);
    timer = 0;
  }
  if (pos == 180)
  {
    State = &ServoSM::coming;
  }
}

void ServoSM::coming()
{
  if (timer > speed)
  {
    pos --;
    s.write(pos);
    timer = 0;
  }
  if (pos == 0)
  {
    State = &ServoSM::going;
  }
}

int ServoSM::getangle()
{
  return pos;
}



