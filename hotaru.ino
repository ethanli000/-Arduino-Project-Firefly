/*
 Firefly Intallation
 2014/06/06
 */

#include "Firefly.h"  

#define BUG_COUNT 5

//Fireflies
Firefly fireflyArr[6];
//PWM Pin Number
int pwmPin[6] = { 3, 5, 6, 9, 10, 11 };

//ON/OFF Switch
int flag;
int buttonValue;

// the setup routine runs once when you press reset:
void setup()  
{ 
  //Setup Serial
  Serial.begin(9600);
  
  //Setup Switch button
  pinMode(13, INPUT);
  buttonValue = 0;
  flag = 1;
  
  //Initial Firefly
  for(int i = 0; i<BUG_COUNT; i++) {
    pinMode(pwmPin[i], OUTPUT);
    fireflyArr[i].setBug(pwmPin[i]);
  }
} 

// the loop routine runs over and over again forever:
void loop()  
{ 
  //ON/OFF Switch
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
      /*
      if(i == 10) {
        Serial.println("K");
        Serial.println(fireflyArr[i].getKeeping());
        //Serial.println("S");
        //Serial.println(fireflyArr[i].getStatus());
        Serial.println("B");
        Serial.println(fireflyArr[i].shine());
      }
      */
    }
  } else {
    //Turn off all the lights
    for(int i = 0; i<BUG_COUNT; i++) {
      analogWrite(fireflyArr[i].getBug(), 0);
    }
  }
  
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);                            
}
