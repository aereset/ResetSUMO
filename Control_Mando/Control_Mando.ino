#include <RF24.h>
#include "pinoutMando.h"
#include "mando.h"

void setup() {

  Mando mando();
  RF24 rfMando(CE,CSN);

}

void loop() {
  // put your main code here, to run repeatedly:

}
