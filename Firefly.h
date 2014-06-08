#ifndef FIREFLY_H  //
#define FIREFLY_H

#include <stdlib.h>  

//constant value
#define FADE_VALUE 5
#define MAX_BRIGHTNESS 255
#define MIN_BRIGHTNESS 0

class Firefly
{
private:
  unsigned int pin; //PWM OUTPUT PIN
  unsigned int fStatus; //0:turning-on; 1:on; 2:turning-off; 3:off;
  unsigned int brightness; // 0-255[51 times]
  unsigned int keeping; //on[40-60 times]/off[30-50 times] duration

public:
  Firefly();
  Firefly(unsigned int p); //construct
  void breath(); //update brightness
  unsigned int shine();//get brightness
  void setPin(unsigned int p); //set pin number
  unsigned int getPin();//get bug(pin number)
  unsigned int getStatus();//for debuging
  unsigned int getKeeping();//for debuging
};

#endif // FIREFLY_H
