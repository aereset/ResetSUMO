/*
Programa: Robot Sumo. Programa para el mando de Reset. Código de la clase ResetMando
Autor: Alberto Sevilla
Actualizado: 21/09/22
*/

#include <RF24.h>
#include "radioRobot.h"
#include "pinoutRobot.h"

/// @brief Constructor de la clase RadioRobot. Inicializa el módulo RF
/// @param void
RadioRobot::RadioRobot(){
    
    this->leerCanal();  //Rewrite first digit of _canal to match DIP switch

    RF24 rf(CE,CSN);    //Declare and initialize RF module
    rf.begin();
    rf.openReadingPipe(0,_canal);
    rf.startListening();

    //PinMode set
    pinMode(CE, INPUT);
    pinMode(CSN, INPUT);


}

/// @brief Recibe los datos del mando y lo guarda en la estructura "_data"
/// @param void
void RadioRobot::recibirInputs()
{
  //Serial.println("enviarInputs called");
    if(rf.available()){
        rf.read(&_data, sizeof(_data));
    }
}

/// @brief Lee el canal que se ha configurado en el selector.
void RadioRobot::leerCanal(){ //Makes _canal[0] equal to the DIP switch input, interpreted as binary number
  uint8_t digit[3];
  digit[0] = digitalRead(CHNL_0);
  digit[1] = digitalRead(CHNL_1);
  digit[2] = digitalRead(CHNL_2);

  _canal[0] = (digit[0] + 2*digit[1] + 4*digit[2]);
}


