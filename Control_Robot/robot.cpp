/*/
Programa: Robot Sumo. 
          Funciones de la librería robotSumo.h
Autor: Irene Rodríguez
Actualizado: 27/09/22
/*/

#include <RF24.h>
#include "pinout.h" 

/*------------------------------------------*/
//Iniciar motores
void setupMotorres(){
  pinMode(RM, OUTPUT);
  pinMode(RMB, OUTPUT);
  pinMode(LM, OUTPUT);
  pinMode(LMB, OUTPUT);
  pinMode(PWMR, OUTPUT);
  pinMode(PWML, OUTPUT);
}
/*------------------------------------------*/

/*------------------------------------------*/
//MOvLMIENTO DE LOS MOTORES
void moveMotor(char motor, int Dir, int PWM) {
  /* Variables:
        - Motor ('L', 'R'): indica el motor.
        - Dir: dirección de Alfa de la rueda (delante - 1; atrás - 0).
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

  //Dirección de Alfa de las ruedas
  if(Dir) { //Delante
    digitalWrite(backward, LOW); digitalWrite(forward, HIGH);}
  
  else{ //Atrás
    digitalWrite(forward, LOW); digitalWrite(backward, HIGH);}

   analogWrite(PWM_PIN, PWM);

}
/*------------------------------------------*/

/*------------------------------------------*/
//CONTROL DEL ROBOT. Segunda versión
void robot(int Vm, int Alfa){
    /* 
        - Vm: velocidad media del motor). Velocidad 
        - Alfa: valor para el Alfa del robot
    */
    float vR, vL;
    float Vmp = Vm; float Alfap = Alfa;
    
    if(Vmp<127){ //Hacia atrás
      vR = 127 + (Vmp-127)/127*(Alfap-255) -127; // Regulado a (
      if(vR<=0) {vR = 0;}
      
      vL = 127-(Vmp-127)/127.0*(Alfap) -127;
      if(vL<=0) {vL = 0;}
      
      moveMotor('R', 0, vR); moveMotor('L', 0, vL);
    }

    else{ //Hacia delante
      vR = 127-(Vmp-127)/127.0*(Alfap-255) - 127; 
      if(vR>=255) {vR = 255;}
      
      vL = 127+(Vmp-127)/127.0*Alfap - 127;
      if(vL>=255) {vL = 255;}
      
      moveMotor('R', 1, vR); moveMotor('L', 1, vL);
    }

    Serial.println("Alfa: " + String(Alfa) + " vR: " + String(vR) + " vL: " + String(vL));
    
}
/*------------------------------------------*/
      
