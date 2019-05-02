/*
 *    slowPWM example program
 *      by Phillip Schmidt
 *      
 *      Use slowPWM to blink the built int LED
 */

#include <slowPWM.h>

const int MINIMUM_PERIOD_MS = 30; // the minimum period that the LED will either be off or on

slowPWM blinker( MINIMUM_PERIOD_MS ); // create object

uint32_t nextChangeTime = 1000;
uint8_t  pwmDutyCycle   = 0;


void setup() 
{

  pinMode( LED_BUILTIN, OUTPUT );  // setup led pin

}


void loop() 
{

  digitalWrite( LED_BUILTIN, blinker.check() ); // the check() function returns true (HIGH) when the LED should be on

  if( millis() > nextChangeTime ) //cycle through the 0-255 range 
  {
    nextChangeTime = millis() + 300; // next cange in 0.3s
    blinker.set( pwmDutyCycle++ );   // set the PWM value and increment the variable
  }
  
}
