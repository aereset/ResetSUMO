/*/
Programa: Robot Sumo. Programa para el mando de Reset. Código de la clase ResetMando
Autor: Alberto Sevilla
Actualizado: 21/09/22
/*/

#include <RF24.h>
#include "resetMando.h"
#include "pinoutMando.h"


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
  Serial.println("leerInputs called");

  _joyLx = map(analogRead(JOYL_X), 0,1023, 0,255);  _data[0] = _joyLx;
  _joyLy = map(analogRead(JOYL_Y), 0,1023, 0,255);  _data[1] = _joyLy;
  _joyRx = map(analogRead(JOYR_X), 0,1023, 0,255);  _data[2] = _joyRx;
  _joyRy = map(analogRead(JOYR_Y), 0,1023, 0,255);  _data[3] = _joyRy;

  _btnA = digitalRead(BTN_A);                       _data[4] = _btnA;
  _btnB = digitalRead(BTN_B);                       _data[5] = _btnB;
  _btnC = digitalRead(BTN_C);                       _data[6] = _btnC;
  _btnD = digitalRead(BTN_D);                       _data[7] = _btnD;

  _dial = map(analogRead(DIAL), 0,1023, 0,255);     _data[8] = _dial;

  _flip1 = digitalRead(FLIP_1);                     _data[9] = _flip1;
  _flip2 = digitalRead(FLIP_2);                     _data[10] = _flip2;
}


void ResetMando::enviarInputs()
{
  Serial.println("enviarInputs called");

  rf.write(&_data, sizeof(_data));

  // rf.write(&_joyLx, sizeof(_joyLx));
  // rf.write(&_joyLy, sizeof(_joyLy));
  // rf.write(&_joyRx, sizeof(_joyRx));
  // rf.write(&_joyRy, sizeof(_joyRy));

  // rf.write(&_btnA, sizeof(_btnA));
  // rf.write(&_btnB, sizeof(_btnB));
  // rf.write(&_btnC, sizeof(_btnC));
  // rf.write(&_btnD, sizeof(_btnD));

  // rf.write(&_dial, sizeof(_dial));

  // rf.write(&_flip1, sizeof(_flip1));
  // rf.write(&_flip2, sizeof(_flip2));
}


void ResetMando::leerCanal(){ //Makes _canal[0] equal to the DIP switch input, interpreted as binary number

  uint8_t digit[3];
  digit[0] = digitalRead(CHNL_0);
  digit[1] = digitalRead(CHNL_1);
  digit[2] = digitalRead(CHNL_2);

  _canal[0] = (digit[0] + 2*digit[1] + 4*digit[2]);

}


