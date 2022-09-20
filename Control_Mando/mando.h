#ifndef MANDO_H
#define MANDO_H

  #include <Arduino.h>
  #include "pinoutMando.h"

  class ResetMando
  { 
    public:

      ResetMando(); //Constructor
      RF24 rf;
      void leerInputs();
      void leerCanal();
      

    private:

      uint8_t _canal[5] = {0,0,0,0,0};

      uint8_t x1;
      uint8_t y1;
      uint8_t x2;
      uint8_t y2;

      bool btnA;
      bool btnB;
      bool btnC;
      bool btnD;

      uint8_t dial;

      bool flp1;
      bool flp2;
         
  };


#endif