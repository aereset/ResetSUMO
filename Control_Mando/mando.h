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

      uint8_t _jLx;
      uint8_t _jLy;
      uint8_t _jRx;
      uint8_t _jRy;

      bool _btnA;
      bool _btnB;
      bool _btnC;
      bool _btnD;

      uint8_t _dial;

      bool _flip1;
      bool _flip2;
         
  };