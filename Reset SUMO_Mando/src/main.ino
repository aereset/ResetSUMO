/*
Programa: Robot Sumo. Programa para el mando de Reset
Autor: Alberto Sevilla
Actualizado: 21/09/22
*/


#include "resetMando.h"

ResetMando mando; 

void setup() {
  Serial.begin(9600); 
}

void loop() {
  mando.leerInputs();
  mando.enviarInputs();
  delay(1);
}
