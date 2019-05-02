/*
      slowPWM by Phillip Schmidt
      
      Expected Input range 0-255 to match Arduino AnalogWrite function
      Off and on periods will never be less than minPeriod set at object creation
*/

#include "slowPWM.h"

slowPWM::slowPWM( int periodMS )
{
   minPeriod = abs(periodMS);
   minPeriodx256 = minPeriod << 8;
}


void slowPWM::set(int rate)
{

   if( rate < 1 )  // full off
   {
      onPeriod  = 0;
      offPeriod = 4.19e6;
      return;
   }

   if( rate > 254 )  // full on
   {
      onPeriod  = 4.19e6;
      offPeriod = 0;
      return;
   }

   if( rate < 128 )  // less than 50%
   {
      onPeriod  = minPeriod;
      offPeriod = minPeriodx256 / rate - minPeriod;
   }
   else              // over 50%
   {
      offPeriod = minPeriod;
      onPeriod  = minPeriodx256 / (255 - rate) - minPeriod;
   }
}


bool slowPWM::check()
{
   uint32_t timeNow = millis();

   if( onNow )
   {
      // currently on, check for turn off
      if( timeNow - onTime > onPeriod )
      {
         onNow   = false;
         offTime = timeNow;
      }
   }
   else
   {
      // currently off, check for turn on
      if( timeNow - offTime > offPeriod )
      {
         onNow  = true;
         onTime = timeNow;
      }
   }
   return onNow;
}
