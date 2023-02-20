/*/
Programa: Robot Sumo. Programa para el mando de Reset. Código de la clase ResetMando
Autor: Alberto Sevilla
Actualizado: 21/09/22
/*/

#include <RF24.h>
#include "resetMando.h"

ResetMando::ResetMando(){
    
    this->leerCanal();  //Rewrite first digit of _canal to match DIP switch

    RF24 rf(CE,CSN);    //Declare and initialize RF module
    rf.begin();
    rf.openWritingPipe(_canal);
   
    //PinMode set
    pinMode(JOYL_X, INPUT);
    pinMode(JOYL_Y, INPUT);
    pinMode(JOYR_X, INPUT);
    pinMode(JOYR_Y, INPUT);

    pinMode(CHNL_0, INPUT);
    pinMode(CHNL_1, INPUT);
    pinMode(CHNL_2, INPUT);

    pinMode(BTN_A, INPUT);
    pinMode(BTN_B, INPUT);
    pinMode(BTN_C, INPUT);
    pinMode(BTN_D, INPUT);

    pinMode(DIAL, INPUT);

    pinMode(FLIP_1, INPUT);
    pinMode(FLIP_2, INPUT);

    pinMode(CE, OUTPUT);
    pinMode(CSN, OUTPUT);

    pinMode(LED, OUTPUT);
}

void ResetMando::leerInputs()
{
  //Serial.println("leerInputs called");
  // JoyLX / JoyLY / JoyRX / JoyRY / BTNA / BTNB / BTNC / BTND / DIAL / FLIP1 / FLIP2

  _data.joyLx = map(analogRead(JOYL_X), 0,1023, 0,255);
  _data.joyLy = map(analogRead(JOYL_Y), 0,1023, 0,255);
  _data.joyRx = map(analogRead(JOYR_X), 0,1023, 0,255);
  _data.joyRy = map(analogRead(JOYR_Y), 0,1023, 0,255);

  _data.btnA = digitalRead(BTN_A);
  _data.btnB = digitalRead(BTN_B);
  _data.btnC = digitalRead(BTN_C);                      
  _data.btnD = digitalRead(BTN_D);                      

  _data.dial = map(analogRead(DIAL), 0,1023, 0,255);    

  _data.flip1 = digitalRead(FLIP_1);                     
  _data.flip2 = digitalRead(FLIP_2);                     
}

/// @brief Envía los datos del mando
/// @param void
void ResetMando::enviarInputs()
{
  //Serial.println("enviarInputs called");

  rf.write(&_data, sizeof(_data));

}

void ResetMando::leerCanal(){ //Makes _canal[0] equal to the DIP switch input, interpreted as binary number

  uint8_t digit[3];
  digit[0] = digitalRead(CHNL_0);
  digit[1] = digitalRead(CHNL_1);
  digit[2] = digitalRead(CHNL_2);

  _canal[0] = (digit[0] + 2*digit[1] + 4*digit[2]);

}


