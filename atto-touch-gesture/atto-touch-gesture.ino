/*************************************************************************************************************************************************
 *  TITLE: Controlling Your Computer Using Capacitive Touch Inputs
 *
 *  By Frenoy Osburn
 *  YouTube Video: https://youtu.be/bZOlPnfm78o
 *  BnBe Post: https://www.bitsnblobs.com/computer-control-using-gestures-&-touch-input
 *************************************************************************************************************************************************/
#include "Keyboard.h"
#include <Arduino_APDS9960.h>

#define BUTTON_1   14
#define BUTTON_2   16
#define BUTTON_3   15
#define BUTTON_4   17

void setup() 
{
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  pinMode(BUTTON_3, INPUT);
  pinMode(BUTTON_4, INPUT);

  Keyboard.begin();
  if (!APDS.begin()) 
  {
    Serial.println("Error initializing APDS9960 sensor!");
  }

  // for setGestureSensitivity(..) a value between 1 and 100 is required.
  // Higher values makes the gesture recognition more sensible but less accurate
  // (a wrong gesture may be detected). Lower values makes the gesture recognition
  // more accurate but less sensible (some gestures may be missed).
  // Default is 80
  APDS.setGestureSensitivity(50);
}

void loop() 
{  
  if(digitalRead(BUTTON_1) == HIGH)     //LOCK
  {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('q');
    delay(100);
    Keyboard.releaseAll();
    delay(2000);
  }

  if(digitalRead(BUTTON_2) == HIGH)     //firefox
  {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(0x20);
    Keyboard.releaseAll();
    delay(100);
        
    Keyboard.write('f');
    Keyboard.write('i');
    Keyboard.write('r');
    Keyboard.write('e');
    Keyboard.write('f');
    Keyboard.write('o');
    Keyboard.write('x');
    delay(100);
    Keyboard.write(KEY_RETURN);
    delay(2000);
  }

  if(digitalRead(BUTTON_3) == HIGH)     //FCP
  {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(0x20);
    Keyboard.releaseAll();
    delay(100);
        
    Keyboard.write('f');
    Keyboard.write('i');
    Keyboard.write('n');
    Keyboard.write('a');
    Keyboard.write('l');
    Keyboard.write(' ');
    Keyboard.write('c');
    delay(100);
    Keyboard.write(KEY_RETURN);
    delay(2000);
  }

   if(digitalRead(BUTTON_4) == HIGH)     //play itunes
  {   
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(0x20);
    Keyboard.releaseAll();
    delay(100);
        
    Keyboard.write('i');
    Keyboard.write('t');
    Keyboard.write('u');
    Keyboard.write('n');
    Keyboard.write('e');
    Keyboard.write('s');
    delay(100);
    Keyboard.write(KEY_RETURN);
    delay(250);
    Keyboard.write(0x20);
    delay(2000);
  }

  if (APDS.gestureAvailable()) 
  {
    // a gesture was detected, read it and do something with it.
    int gesture = APDS.readGesture();

    switch (gesture) 
    {
      case GESTURE_LEFT:
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_UP_ARROW);
        Keyboard.releaseAll();
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_UP_ARROW);
        Keyboard.releaseAll();
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_UP_ARROW);
        Keyboard.releaseAll();
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_UP_ARROW);
        Keyboard.releaseAll();
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_UP_ARROW);
        Keyboard.releaseAll();
        delay(1000);
        break;

      case GESTURE_RIGHT:
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_DOWN_ARROW);
        Keyboard.releaseAll();
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_DOWN_ARROW);
        Keyboard.releaseAll();
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_DOWN_ARROW);
        Keyboard.releaseAll();
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_DOWN_ARROW);
        Keyboard.releaseAll();
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_DOWN_ARROW);
        Keyboard.releaseAll();
        delay(1000);
        break;

      case GESTURE_DOWN:
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_ARROW);
        Keyboard.releaseAll();
        delay(1000);
        break;

      case GESTURE_UP:
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_RIGHT_ARROW);
        Keyboard.releaseAll();
        delay(1000);
        break;

      default:
        // ignore
        break;
    }
  }  
}
