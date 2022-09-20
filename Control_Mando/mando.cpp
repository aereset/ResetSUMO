#include <Arduino.h>
#include <RF24.h>
//#include <stdio.h>

#include "mando.h"
#include "pinoutMando.h"

ResetMando::ResetMando(){
    
    this->leerCanal();

    RF24 rf(CE,CSN);
    rf.begin();
    rf.openWritingPipe(_canal);
   

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

void ResetMando::leerInputs(){
  Serial.println("leerInputs called");
}


void ResetMando::leerCanal(){

  uint8_t digit[3];
  digit[0] = 1;//digitalRead(CHNL_0);
  digit[1] = 1;//digitalRead(CHNL_1);
  digit[2] = 1;//digitalRead(CHNL_2);

  _canal[0] = (digit[0] + 2*digit[1] + 4*digit[2]);

}


