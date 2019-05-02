# slowPWM
A PWM Library for operating systems that are sensitive to very short actuation periods

* The minimum ON or OFF time is controlled to eliminate excessively short actuation cycles
* This is usefull for switching inductive electrical loads or mechanical systems where tradition PWM cycle frequencies would cause malfunction
* For high duty cycles the OFF period will be set to the minimum allowed and the ON will be extended to create the expected result
* For low duty cycles the ON period will be set to the minimum allowed and the OFF will be extended to create the expected result

FUNCTIONS
```
slowPWM( int periodMS );   // set minimum actuation period at object creation

void set( int rate );      // set desired PWM duty cycle (0-255)
bool check();              // returns TRUE during the on portion of the cycle and FALSE for the off portion
```

See the examples folder for a sketch showing hte usage for blinking an LED