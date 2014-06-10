/*
 Firefly Intallation
 author: Li Yingchen
 2014/06/06
 */

#include "Firefly.h"  

#define BUG_COUNT 5

//Fireflies
Firefly fireflyArr[6];
//PWM Pin Number
int pwmPin[6] = { 3, 5, 6, 9, 10, 11 };

//ON or OFF Switch
int flag;
int buttonValue;

void setup()  
{ 
  //Setup Serial
  Serial.begin(9600);
  
  //Setup Switch button
  pinMode(13, INPUT);
  buttonValue = 0;
  flag = 1;
  
  //Initialize Firefly
  for(int i = 0; i<BUG_COUNT; i++) {
    pinMode(pwmPin[i], OUTPUT);
    fireflyArr[i].setBug(pwmPin[i]);
  }
} 

void loop()  
{ 
  //ON or OFF Switch
  int buttonState = digitalRead(13);
  //Serial.println(buttonState);
  
  if(buttonState == 1 && buttonValue == 0) {
    flag = (flag + 1) % 2;
  }
  buttonValue = buttonState;
  
  if(flag == 1) {
    for(int i = 0; i<BUG_COUNT; i++) {
      //refresh the brightness
      fireflyArr[i].breath();
      analogWrite(fireflyArr[i].getBug(), fireflyArr[i].shine());
    }
  } else {
    //Turn off all lights
    for(int i = 0; i<BUG_COUNT; i++) {
      analogWrite(fireflyArr[i].getBug(), 0);
    }
  }
  
  delay(30);                            
}
