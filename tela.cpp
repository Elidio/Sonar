#include "tela.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

Tela::Tela(SonarSM * sonar, ServoSM * servosm)
{
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }

  u8g.setContrast(128);
  
  State = &Tela::show;
  this->sonar = sonar;
  this->servosm = servosm;
  for(int i =0; i<180; i++)
  {
    reading[i][0] = 63 ;
    reading[i][1] = 63 ;
  }
}

void Tela::exec()
{
  (this->*State)();

}

void Tela::show()
{
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );

  State = &Tela::wait;
  
  // rebuild the picture after some delay
}

void Tela::wait()
{
  int angle = servosm->getangle();
  int reading = sonar->getreading(); 
  polar(reading, angle);
  this->reading[angle][0] = x;
  this->reading[angle][1] = y;
  if (timer > 100)
  {
    timer = 0;
    State = &Tela::show;
  }
}

void Tela::draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  u8g.drawDisc(63, 63, 3, U8G_DRAW_UPPER_RIGHT|U8G_DRAW_UPPER_LEFT);
  for(int i = 0; i<180; i++)
  {
    u8g.drawPixel(this->reading[i][0],this->reading[i][1]);
  }
  int angle = servosm->getangle();
  int reading = sonar->getreading();
  polar(reading, angle);
  u8g.drawLine(63, 63, x, y);
  //u8g.setFont(u8g_font_osb21);
  //u8g.drawStr( 0, 22, "Hello World!");
}

void Tela::polar(int r, int theta)
{
  double angle = (double) theta * 1000 / 57296;
  x = cos(angle) * (64 * (double)r / 50) + 64;
  y = 64 - sin(angle) * (64 * (double)r / 50);
 /*
  Serial.print(x);
  Serial.print(" ");
  Serial.println(y);
*/
}

