/*
Programa: Robot Sumo. 
          Funciones de la librería robotSumo.h
Autor: Irene Rodríguez
Actualizado: 25/11/22
*/

#include <RF24.h> //Librería de <RF24>
#include "pinoutRobot.h" //Libería de pines

/// @brief Setup inicial.
void setupMotores(){
  pinMode(RM, OUTPUT);
  pinMode(RMB, OUTPUT);
  pinMode(LM, OUTPUT);
  pinMode(LMB, OUTPUT);
  pinMode(PWMR, OUTPUT);
  pinMode(PWML, OUTPUT);
}

/// @brief Movimiento de los motores.
/// @param char motor
/// @param int Dir 
/// @param int PWM 
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

/// @brief Movimiento del robot.
/// @param uint8_t Sm
/// @param uint8_t Alpha 
void robot(uint8_t Sm, uint8_t Alpha){ //Sm -> Velocidad media   Alpha -> Ángulo medio 
    float sR, sL;
    float Smp = Sm; float Alphap = Alpha; //Pasar datos a tipo float. Necesarios para las gráficas.
    
    if(Smp<127){ //Hacia atrás
      sR =(Smp-127.0)/127.0*(Alphap-255.0);

      //Condiciones añadidas en las pruebas
      if(sR >= 255) { sR = 255;}
      if(sR <= 0) { sR = 0;}
      sL = -(Smp-127.0)/127.0*(Alphap);

      //Condiciones añadidas en las pruebas
      if(sL >= 255) { sL = 255;}
      if(sL <= 0) { sL = 0;}
      moveMotor('R', 0, sR); //Motor derecho
      moveMotor('L', 0, sL); //Motor izquierdo
    }

    else{ //Hacia delante
      sR = -(Smp-127.0)/127.0*(Alphap-255.0);

      //Condiciones añadidas en las pruebas
      if(sR >= 255) { sR = 255;}
      if(sR <= 0) { sR = 0;} 
      sL = (Smp-127.0)/127.0*Alphap;

      //Condiciones añadidas en las pruebas
      if(sL >= 255) { sL = 255;}
      if(sL <= 0) { sL = 0;}
      moveMotor('R', 1, sR); //Motor derecho
      moveMotor('L', 1, sL); //Motor izquierdo
    }
}
      
