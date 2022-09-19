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


  //Void de la casuística del robot -> Optimización
  void casuistica_Robot(int va, int vb, char a, char b ){ //va -> motor que aumenta velocidad
  //Velocidad del motor que acelera
      if(va>=0 && va< 255){ //Si va se encuentra en el intervalo de 0 a 255
        mov(a, 1, va);}

      else{ // Si va se encuentra en el intervalo de más de 255
        mov(a, 1, 255);}
          
      //Nota: va no puede ser negativo ya que Vm>0, 127.5>Giro>0 y ambos términos se suman

    //Velocidad del motor que disminuye
     if(vb>=0 && vb<=255){ //vb es positivo. 
      mov(b, 1, vb);}
      
     else{
      if(vb<0 && vb>=-255){ //vb es negativo
        mov(b, 0, -vb);}
        
      else{
        mov(b, 0, 255);} //vb tiene el valor negativo máximo  
         }

       //Nota: vb no va a ser nunca superior a 255 ya que siempre resta a vm
    } //Fin del bucle de casuística




void robot(int Vm, int Giro) {
  /* Variables:
        - Vm: velocidad media del motor). Velocidad 
        - Giro: valor para el giro del robot. Criterio a utilizar:
             (0, 255) ~ (0, 360) (Grados) 
    */

    int Grados = map(Giro, 0, 255, 0, 359); //Hallamos la equivalencia de Giro en grados
    int vr, vi;

    if(Grados >= 0 && Grados <= 180){ //CASO 1: HAY QUE GIRAR A LA IZQUIERDA
      vr = Vm+Giro; 
      vi = Vm-map(Giro, 0, 255, 0, 510); //Para ajustar un poco el tema del giro, en sentido de que a los 180 grados pueda girar sobre sí mismo

      casuistica_Robot(vr, vi, 'R', 'L');
         
     } //Fin del caso de girar a la izquierda

    if(Grados>180 && Grados<=360){ //CASO 2: HAY QUE GIRAR A LA DERECHA
      vi = Vm+(255-Giro);
      vr = Vm-map(255-Giro, 0, 255, 0, 510);

      casuistica_Robot(vi, vr, 'L', 'R');
         
    } //Fin del caso de girar a la derecha
    

} //Fin del bucle de control robot


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
