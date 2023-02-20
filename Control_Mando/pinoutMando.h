/*/
Programa: Robot Sumo. Programa para el mando de Reset. Pinout de Arduino Nano
Autor: Alberto Sevilla
Actualizado: 21/09/22
/*/

#pragma once

//Joysticks
#define JOYL_X A0     //Left joystick, x axis (analog in)
#define JOYL_Y A1     //Left joystick, y axis (analog in)
#define JOYR_X A6     //Right joystick, x axis (analog in)
#define JOYR_Y A7     //Right joystick, y axis (analog in)

//DIP for channel selection
#define CHNL_0 4    //Digit 0 (analog in)
#define CHNL_1 3    //Digit 1 (analog in)
#define CHNL_2 2    //Digit 2 (analog in)

//Buttons (digital in)
#define BTN_A 18    //Same as left joystick click  
#define BTN_B 5
#define BTN_C 17    //Same as right joystick click 
#define BTN_D 6

#define DIAL A2     //Knob dial (analog in)

//Flip switches (digital in)
#define FLIP_1 8
#define FLIP_2 7

//Pins for RF module data transmission (analog out)
#define CE 9
#define CSN 10

//Extra pin, provisional
#define LED 19