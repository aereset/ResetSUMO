#define RM 7 
#define RMB 6 
#define PWMR 5 
#define LM 10 
#define LMB 8 
#define PWML 9

void setupMotorres(){
  pinMode(RM, OUTPUT);
  pinMode(RMB, OUTPUT);
  pinMode(LM, OUTPUT);
  pinMode(LMB, OUTPUT);
  pinMode(PWMR, OUTPUT);
  pinMode(PWML, OUTPUT);
  Serial.begin(9600);
}
//---


//---
void moveMotor(char motor, int Dir, int PWM) {
  /* Variables:
        - Motor ('L', 'R'): indica el motor.
        - Dir: dirección de Alpha de la rueda (delante - 1; atrás - 0).
        - PWM: Valor analógico.
  */
  int forward, backward, PWM_PIN; //Forward, backward
  
  switch(motor){   //Control de los pines de los motores
    case 'L':
          forward = LM;
          backward = LMB;
          PWM_PIN = PWML;
          break;
          
    case 'R':
          forward = RM;
          backward = RMB;
          PWM_PIN = PWMR;
          break;
  }

  //Dirección de Alpha de las ruedas
  if(Dir) { //Delante
    digitalWrite(backward, LOW); digitalWrite(forward, HIGH);}
  
  else{ //Atrás
    digitalWrite(forward, LOW); digitalWrite(backward, HIGH);}

   analogWrite(PWM_PIN, PWM);

}
//---
void robot(uint8_t Sm, uint8_t Alpha){ //Sm -> Velocidad media   Alpha -> Ángulo medio 
    float sR, sL;
    float Smp = Sm; float Alphap = Alpha; //Pasar datos a tipo float. Necesarios para las gráficas.
    
    if(Smp<127){ //Hacia atrás
      sR =(Smp-127.0)/127.0*(Alphap-255.0);
      if(sR >= 255) { sR = 255;}
      if(sR <= 0) { sR = 0;}
      sL = -(Smp-127.0)/127.0*(Alphap);
      if(sL >= 255) { sL = 255;}
      if(sL <= 0) { sL = 0;}
      moveMotor('R', 0, sR); moveMotor('L', 0, sL); //Conf del motor
    }

    else{ //Hacia delante
      sR = -(Smp-127.0)/127.0*(Alphap-255.0); 
      if(sR >= 255) { sR = 255;}
      if(sR <= 0) { sR = 0;}
      sL = (Smp-127.0)/127.0*Alphap;
      if(sL >= 255) { sL = 255;}
      if(sL <= 0) { sL = 0;}
      moveMotor('R', 1, sR); moveMotor('L', 1, sL); //Conf del motor
    }

    Serial.println("Alpha: " + String(Alpha) + " Speed: " + String(Sm) + " sR: " + String(sR) + " sL: " + String(sL)); //Pruebas
    
}
//---
void setup() {
  // put your setup code here, to run once:
  pinMode(A5, INPUT); //vrY Alpha
  pinMode(A2, INPUT); //VrX Sm
  setupMotorres();
  }


void loop() {
  uint8_t Sm, Alpha;
  Sm = map(analogRead(A2), 0, 1023, 0, 255);
  Alpha = map(analogRead(A5), 0, 1023, 0, 255);
  robot(Sm, Alpha);
}
