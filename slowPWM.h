/*
      slowPWM by Phillip Schmidt
      
      Expected Input range 0-255 to match Arduino AnalogWrite function

      Off and on periods will never be less than minPeriod set at object creation
*/

#ifndef slowPWM_h
  #define slowPWM_h
  
  #include "arduino.h"
  
  class slowPWM
  {
     public:

        slowPWM( int periodMS );

        void set( int rate );
        bool check();


     private:

        uint32_t onTime;
        uint32_t offTime;

        uint32_t onPeriod;
        uint32_t offPeriod;

        uint32_t minPeriod; // [ms]
        uint32_t minPeriodx256; // [ms]

        bool onNow;
  };
  
#endif
