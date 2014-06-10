/*
 Firefly Class
 author: Li Yingchen
 2014/06/06
 */

#include "Firefly.h"

/*
constructor, default
*/
Firefly::Firefly() 
{
  pin = 0;
  fStatus = rand() % 4;
  if (fStatus == 0 || fStatus == 2){
    brightness = 125;
    keeping = 0;
  } else if (fStatus == 1) {
    keeping = 50;
    brightness = 225;
  } else {
    keeping = 40;
    brightness = 0;
  }
}

/*
constructor, with setting pin number
*/
Firefly::Firefly(unsigned int p)
{
  pin = p;
  fStatus = rand() % 4;
  if (fStatus == 0 || fStatus == 2){
    brightness = 125;
    keeping = 0;
  } else if (fStatus == 1) {
    keeping = 25;
  } else {
    keeping = 15;
  }
}

void Firefly::breath() 
{
  switch (fStatus % 4)
  {
    case 0:
      brightness = brightness + FADE_VALUE;
      if(brightness >= MAX_BRIGHTNESS) {
        brightness = MAX_BRIGHTNESS;
        fStatus = 1;
        keeping = rand() % 20 + 40;
      }
      break;
    case 1:
      keeping = keeping - 1;
      if(keeping <= 0) {
        fStatus = 2;
        keeping = 0;
      }
      break;
     case 2:
        brightness = brightness - FADE_VALUE;
        if(brightness <= MIN_BRIGHTNESS) {
          brightness = MIN_BRIGHTNESS;
          fStatus = 3;
          keeping = rand() % 20 + 30;
        }
        break;
    case 3:
      keeping = keeping - 1;
      if(keeping <= 0) {
        fStatus = 0;
        keeping = 0;
      }
      break;
  }
}

unsigned int Firefly::shine() 
{
  return brightness;
}

void Firefly::setBug(unsigned int p) 
{
  pin = p;
}

unsigned int Firefly::getBug() 
{
  return pin;
}

unsigned int Firefly::getStatus() 
{
  return fStatus;
}

unsigned int Firefly::getKeeping() 
{
  return keeping;
}
