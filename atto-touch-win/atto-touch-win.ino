/*************************************************************************************************************************************************
 *  TITLE: Controlling Your Computer Using Capacitive Touch Inputs
 *
 *  By Frenoy Osburn
 *  YouTube Video: https://youtu.be/bZOlPnfm78o
 *  BnBe Post: https://www.bitsnblobs.com/computer-control-using-gestures-&-touch-input
 *************************************************************************************************************************************************/
 
#include "Keyboard.h"

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
}

void loop() 
{
  if(digitalRead(BUTTON_1) == HIGH)     //Lock
  {
      // ALT-l:
     Keyboard.press(KEY_LEFT_GUI);
     Keyboard.press('l');
    
     Keyboard.releaseAll();
     delay(2000);
  }

  if(digitalRead(BUTTON_2) == HIGH)     //Firefox
  {
    Keyboard.write(KEY_LEFT_GUI);
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

  if(digitalRead(BUTTON_3) == HIGH)     //VLC
  {
    Keyboard.write(KEY_LEFT_GUI);
    delay(100);
        
    Keyboard.write('v');
    Keyboard.write('l');
    Keyboard.write('c');
    delay(100);
    Keyboard.write(KEY_RETURN);
    delay(2000);
  }

  if(digitalRead(BUTTON_4) == HIGH)     //Windows Media Player
  {
    Keyboard.write(KEY_LEFT_GUI);
    delay(100);
    
    Keyboard.write('w');
    Keyboard.write('i');
    Keyboard.write('n');
    Keyboard.write('d');
    Keyboard.write('o');
    Keyboard.write('w');
    Keyboard.write('s');
    Keyboard.write(0x20);  
    delay(100);
    Keyboard.write('m');
    Keyboard.write('e');
    Keyboard.write('d');
    Keyboard.write('i');
    Keyboard.write('a');
    delay(100);
    Keyboard.write(KEY_RETURN);
    delay(2000);
  }  
}
