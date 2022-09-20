#include <RF24.h>
#include "pinoutMando.h"
#include "mando.h"

ResetMando mando; 

void setup() {
  Serial.begin(9600); 
}

void loop() {

  mando.leerInputs();
  delay(100);

}
