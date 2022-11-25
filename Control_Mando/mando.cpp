/*/
Programa: Robot Sumo. Programa para el mando de Reset. Código de la clase ResetMando
Autor: Alberto Sevilla
Actualizado: 21/09/22
/*/

#include <RF24.h>
#include "mando.h"
#include "pinoutMando.h"


ResetMando::ResetMando(){
    
    this->leerCanal();  //Rewrite first digit of _canal to match DIP switch

    RF24 rf(CE,CSN);    //Declare and initialize RF module
    rf.begin();
    rf.openWritingPipe(_canal);
   
    //PinMode set
    pinMode(JL_X, INPUT);
    pinMode(JL_Y, INPUT);
    pinMode(JR_X, INPUT);
    pinMode(JR_Y, INPUT);

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
  Serial.println("leerInputs called");

  _jLx = map(analogRead(JL_X), 0,1023, 0,255);
  _jLy = map(analogRead(JL_Y), 0,1023, 0,255);
  _jRx = map(analogRead(JR_X), 0,1023, 0,255);
  _jRy = map(analogRead(JR_Y), 0,1023, 0,255);

  _btnA = digitalRead(BTN_A);
  _btnB = digitalRead(BTN_B);
  _btnC = digitalRead(BTN_C);
  _btnD = digitalRead(BTN_D);

  _dial = map(analogRead(DIAL), 0,1023, 0,255);

  _flip1 = digitalRead(FLIP_1);
  _flip2 = digitalRead(FLIP_2);
}


void ResetMando::enviarInputs()
{
  Serial.println("enviarInputs called");

  rf.write(&_jLx, sizeof(_jLx));
  rf.write(&_jLy, sizeof(_jLy));
  rf.write(&_jRx, sizeof(_jRx));
  rf.write(&_jRy, sizeof(_jRy));

  rf.write(&_btnA, sizeof(_btnA));
  rf.write(&_btnB, sizeof(_btnB));
  rf.write(&_btnC, sizeof(_btnC));
  rf.write(&_btnD, sizeof(_btnD));

  rf.write(&_dial, sizeof(_dial));

  rf.write(&_flip1, sizeof(_flip1));
  rf.write(&_flip2, sizeof(_flip2));
}


void ResetMando::leerCanal(){ //Makes _canal[0] equal to the DIP switch input, interpreted as binary number

  uint8_t digit[3];
  digit[0] = digitalRead(CHNL_0);
  digit[1] = digitalRead(CHNL_1);
  digit[2] = digitalRead(CHNL_2);

  _canal[0] = (digit[0] + 2*digit[1] + 4*digit[2]);

}


