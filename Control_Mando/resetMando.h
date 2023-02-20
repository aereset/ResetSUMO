/*/
Programa: Robot Sumo. Programa para el mando de Reset. Encabezado de clase ResetMando
Autor: Alberto Sevilla
Actualizado: 21/09/22
/*/

#pragma once

  #include <RF24.h>
  #include "pinoutMando.h"

  class ResetMando
  { 
    public:

      ResetMando(); //Constructor, initializer of RF module
      
      void leerInputs();
      void enviarInputs();
      void leerCanal();
      

    private:
      
      RF24 rf;
      uint8_t _canal[5] = {0,0,0,0,0};

      uint8_t _joyLx;
      uint8_t _joyLy;
      uint8_t _joyRx;
      uint8_t _joyRy;

      uint8_t _btnA;
      uint8_t _btnB;
      uint8_t _btnC;
      uint8_t _btnD;

      uint8_t _dial;

      uint8_t _flip1;
      uint8_t _flip2;

      uint8_t _data[11];
         
  };