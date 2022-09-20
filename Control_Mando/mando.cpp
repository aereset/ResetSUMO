#include <Arduino.h>
#include "mando.h"
#include "pinoutMando.h"

Mando::Mando(){
  pinMode(J1_X, INPUT);
    pinMode(J1_Y, INPUT);
    pinMode(J2_X, INPUT);
    pinMode(J2_Y, INPUT);

    pinMode(CHNL_1, INPUT);
    pinMode(CHNL_2, INPUT);
    pinMode(CHNL_3, INPUT);

    pinMode(BTN_1, INPUT);
    pinMode(BTN_2, INPUT);
    pinMode(BTN_3, INPUT);
    pinMode(BTN_4, INPUT);

    pinMode(KNOB, INPUT);

    pinMode(SW_1, INPUT);
    pinMode(SW_2, INPUT);

    pinMode(CE, OUTPUT);
    pinMode(CSN, OUTPUT);

    pinMode(LED, OUTPUT);
}


