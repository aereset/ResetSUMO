/*/
Programa: Robot Sumo. Movimiento de los motores
Autora: Irene 
Estado: En proceso.
Actualizado: 18/09/22
/*/

//Librerías Arduino
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "pinout.h"

/*
#define RM 7 //Pin del motor derecho
#define RMB 6 //Pin del motor derecho (hacia atrás)
#define PWMR 5 //PWM del motor derecho
#define LM 10 //Pin del motor izquierdo
#define LMB 8 //Pin del motor izquierdo (hacia atrás)
#define PWML 9//PWM del motor izquierdo
*/

/*------------------------------------------*/
//FUNCIÓN PARA CONTROLAR LOS MOTORES
void mov(char motor, int Dir, int PWM) {
  /* Variables:
        - Motor (Char: 'L', 'R'): indica el motor.
        - Dir: dirección de giro de la rueda. 
              - Hacia delante = 1
              - Hacia atrás = 0
        - PWM: Valor de la velocidad para ese motor (Se entiende que es dato)
  */
  int forward, backward, PWM_PIN; //Forward, backward
  
  //Control de los pines de los motores
  switch(motor){
    case 'L':
          forward = LM;
          backward = LMB;
          PWM_PIN = PWMR;
          break;
    case 'R':
          forward = RM;
          backward = RMB;
          PWM_PIN = PWML;
          break;
  }

  //Control de dirección de giro de las ruedas
  if(Dir) { //Se mueve hacia delante
    digitalWrite(backward, LOW); 
    digitalWrite(forward, HIGH);
    analogWrite(PWM_PIN, PWM); 
  }
  
  else{ //Se mueve hacia atrás
    digitalWrite(forward, LOW); 
    digitalWrite(backward, HIGH);
    analogWrite(PWM_PIN,PWM);
  }
}
/*------------------------------------------*/
