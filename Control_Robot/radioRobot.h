/*
Programa: Robot Sumo. Programa para el mando de Reset. Encabezado de clase ResetMando
Autor: Alberto Sevilla
Actualizado: 21/09/22
*/

#pragma once

  #include <RF24.h>

  //Struct data: joysticks, bottons, etc
  struct Data
   {
       uint8_t joyLx, joyLy, joyRx, joyRy, btnA, btnB, btnC, btnD, dial, flip1, flip2;
   };
   

  class RadioRobot
  { 
    public:
      RadioRobot(); //Constructor, initializer of RF module      

      void recibirInputs();
      void leerCanal();      

    private:      
      RF24 rf;
      Data _data;
      uint8_t _canal[5] = {0,0,0,0,0};         
  };