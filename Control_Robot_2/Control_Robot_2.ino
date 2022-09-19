/*/
Programa: Robot Sumo. Movimiento del robot
Autora: Irene 
Estado: En proceso.
Actualizado: 19/09/22
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



/*------------------------------------------*/
//FUNCIÓN PARA CONTROLAR EL ROBOT
void robot(int Vm, int Giro) {
  /* Variables:
        - Vm: velocidad media del motor). Velocidad 
        - Giro: valor para el giro del robot. Criterio a utilizar:
             (0, 255) ~ (0, 360) (Grados) 
    */
    
    int Grados = map(Giro, 0, 255, 0, 359); //Hallamos la equivalencia de Giro en grados
    int vr, vi;

    if(Grados >= 0 && Grados <= 180){ //CASO 1: HAY QUE GIRAR A LA IZQUIERDA
      vr = Vm+Giro*(255-Vm)/127.5; 
      vi = Vm-Giro*(Vm/127.5); 

     } //Fin del caso de girar a la izquierda

    if(Grados>180 && Grados<=360){ //CASO 2: HAY QUE GIRAR A LA DERECHA
      vi = Vm+(Giro-127.5)*(255-Vm)/127.5;
      vr = Vm-(Giro-127.5)*(Vm/127.5);
     
    } //Fin del caso de girar a la derecha

    mov('R', 1, vr);
    mov('L', 1, vi);

} //Fin del bucle de control robot


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
