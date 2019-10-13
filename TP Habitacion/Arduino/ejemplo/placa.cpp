/* BIENVENIDOS A NUESTRAS HERMOSAS FUNCIONES. A CONTINUACIÓN SE DESARROLLAN DETALLADAMENTE TODAS LAS FUNCIONES NECESARIAS PARA OPERAR NUESTRA PLACA SIN NECESIDAD DE SER UN EXPERTO.
 * GRACIAS. ATTE: JOHNSSON & JOHNSSON COMPANY S.A.                          
 *                                                                                             PD: PATENTE EN TRÁMITE.
 */
#include <Arduino.h>
#include <SoftwareSerial.h>
//#include <Ultrasonic.h>
 
#include "placa.h"
void iniciar (void) {
  Serial.begin(NORMALSERIAL);
}
//***********************************MOTORES**************************************

//**************FUNCIONES******************

void MOTOR ( int modo,int motor, int velocidad){ 
  /*Esta función nos ayuda a definir qué modo vamos a usar, ya sea en giro horario o antihorario, clavar el motor o usar el motor como muerto.
  También para definir cuál de los dos motores vamos a usar, sumándole que tanto en la función de giro horario,
  como en la de antihorario le adicionamos una variable de velocidad, que también tendrá que ser ingresada por el usuario*/
  if (modo == 1){
    /*En el primer If nos aparece la función relacionada al modo horario o sea al giro del motor en sentido horario*/

    switch (motor){
      /*En este primer switch aparecen los casos 1 y 2 referidos cada uno a un motor respectivamente hablando. 
      En el que en el primer, caso el motor 1 está relacionado a los pines 2 a y 1a. En el caso 2, el motor 2 está relacionado a los Pines 4a y 3a.
      Y lo mismo sucede en los siguientes, hablando obviamente de los referidos a las funciones de los motores*/
  case 1: analogWrite (EN1,Vel);
          digitalWrite (A_2,0);
          digitalWrite (A_1,1);
          Serial.println("MOTOR 1 SENTIDO HORARIO");
          break;

  case 2: analogWrite (EN2,Vel);
          digitalWrite (A_4,0);
          digitalWrite (A_3,1);
          Serial.println("MOTOR 2 SENTIDO HORARIO");
          break;

  default: Serial.println("VALOR INGRESADO NO COMPATIBLE CON LOS PARAMETROS INDICADOS. INTENTE NUEVAMENTE"); 
  }}  

  else if (modo == 2){
    /*En el segundo, el Else If, nos estamos refiriendo ya al modo en el que el motor gira en sentido antihorario*/
  switch (motor){
    
  case 1: analogWrite (EN1,Vel);
          digitalWrite (A_1,0);
          digitalWrite (A_2,1);
          Serial.println("MOTOR 1 SENTIDO ANTIHORARIO");
          break;

  case 2: analogWrite (EN2,Vel);
          digitalWrite (A_3,0);
          digitalWrite (A_4,1);
          Serial.println("MOTOR 2 SENTIDO ANTIHORARIO");
          break;

  default: Serial.println("VALOR INGRESADO NO COMPATIBLE CON LOS PARAMETROS INDICADOS. INTENTE NUEVAMENTE"); 
  }} 

  else if (modo == 3){
    /*En este tercer Else If nos estamos refiriendo al modo en el que el motor lo configuramos como muerto,
    ya que se deja de acelerar y el mismo irá reduciendo su velocidad.*/
  switch (motor){
  
  case 1: analogWrite (EN1,0);
          digitalWrite (A_1,0);
          digitalWrite (A_2,0);
          Serial.println("MOTOR 1 MUERTO");
          break;
          
  case 2: analogWrite (EN2,0);
          digitalWrite (A_3,0);
          digitalWrite (A_4,0);
          Serial.println("MOTOR 2 MUERTO");
          break;

  default: Serial.println("VALOR INGRESADO NO COMPATIBLE CON LOS PARAMETROS INDICADOS. INTENTE NUEVAMENTE");         
  }} 

  else if (modo == 4){
    /*En este cuarto, y último, Else If nos referimos al modo en el que el motor se clava,
    ósea que se le hace una especie de bloqueo para lograr una frenada mucho más rápida, efectiva y precisa.*/
  switch (motor){
  
  case 1: analogWrite (EN1,1);  
          digitalWrite (A_1,1);
          digitalWrite (A_2,1);
          Serial.println("MOTOR 1 CLAVADO");
          break;

  case 2: analogWrite (EN2,1);
          digitalWrite (A_3,1);
          digitalWrite (A_4,1);
          Serial.println("MOTOR 2 CLAVADO");
          break;  

  default: Serial.println("VALOR INGRESADO NO COMPATIBLE CON LOS PARAMETROS INDICADOS. INTENTE NUEVAMENTE"); 
  }} 
  
  else {
    /*En el Else lo que hacemos es configurar la siguiente frase para que se le imprima en pantalla al usuario,
    cuando ingrese un valor erróneo, o no indicado, y que vuelva a intentarlo.*/
     Serial.println("VALOR INGRESADO NO COMPATIBLE CON LOS PARAMETROS INDICADOS. INTENTE NUEVAMENTE"); 
    }
}

  //MOVIMIENTO DE AMBOS MOTORES
void Avanzar (int Vel){
  /*En nuestra primera función de ambos motores, la cual también funciona como atajo, se encuentra la función avanzar.
  En la que se configura al motor 1 en sentido antihorario y al motor 2 en sentido horario, usando una velocidad indicada por el usuario.*/
  Antihorario (1, 255);
  Horario (2, 255);
  Serial.println("MOTORES AVANZANDO");
  }

void Reversa (int Vel){
  /*En la función reversa se configura exactamente al revés,
  el motor uno como horario y el motor 2 como antihorario. Así logramos que con una determinada velocidad,
  nuestros motores dirijan al dispositivo paralelamente de reversa. */
  Antihorario (2, 255);
  Horario (1, 255);
    Serial.println("MOTORES RETROCEDIENDO");
  }
 
  //GIROS DE AMBOS MOTORES
 void Giro180_DER (int Vel){
  /*Este giro de 180 grados hacia la derecha lo logramos al configurar
  a ambos motores en sentido antihorario, ya que uno de los dos va a estar en espejo con el otro.
  Siempre debemos que tener en cuenta a la variable de velocidad qué modifica la misma en los motores.*/
  Antihorario (1, 255);
  Antihorario (2, 255);
   Serial.println("GIRO 180 DERECHA ACTIVADO");
  }

 void Giro180_IZQ (int Vel){
  /*Ahora en vez de configurarlos en sentido antihorario,
  los configuramos en sentido horario. Siempre debemos que tener en cuenta a la variable de velocidad
  qué modifica la misma en los motores.*/
  Horario (1, 255);
  Horario (2, 255);
  Serial.println("GIRO 180 IZQUIERDA ACTIVADO");
  }

void Giro_DER (int Vel){
  /*En el giro hacia la derecha debemos clavar el motor 2 y darle un sentido antihorario al motor 1, 
  para que el giro sea mucho más rápido.*/
  Antihorario (1, 255);
  Clavar (2);
  Serial.println("GIRO DERECHA ACTIVADO");
  }

void Giro_IZQ (int Vel){
  /*En el giro para la izquierda sucede lo mismo pero ahora vamos el motor uno
  y le damos un sentido horario al motor 2.*/
  Horario (2, 255);
  Clavar (1);
  Serial.println("GIRO IZQUIERDA ACTIVADO");
   }



//***********************************BT**************************************************

//**************FUNCIONES******************
/*No realizamos desarrollo de funciones en el modelo bluetooth  ya qué no son necesarias,
y sólo debemos leer los parámetros que otorga en su medición.*/

//***********************************RELAY************************************************

//**************FUNCIONES******************
void RELAY (int Relay, char Estado){
  /*En esta función de los relays se otorgan dos variables al usuario. La primera indica que relay va a ser usado(el primero o el segundo)
  y la segunda variable indica su estado (activado o desactivado).*/
  if (Estado == ACTIVADO ){
  //activamos los relays
  switch(Relay){
    /*Este switch sirve para elegir qué relay va a ser activado.*/
    
    case 1: pinMode (RLY_1,OUTPUT);
            digitalWrite (RLY_1, 1);
            Serial.println("RELAY 1 ACTIVADO");
            break;
            
    case 2: pinMode (RLY_2,OUTPUT);
            digitalWrite (RLY_2, 1);
            Serial.println("RELAY 2 ACTIVADO");
            break;
            
   default: pinMode (RLY_1,OUTPUT);
            digitalWrite (RLY_1, 0);
            pinMode (RLY_2,OUTPUT);
            digitalWrite (RLY_2, 0);
            Serial.println("RELAYS DESACTIVADOS. VALOR INGRESADO NO COMPATIBLE CON LOS ARAMETROS INDICADOS. INTENTE NUEVAMENTE");
            break; }
  } else if (Estado == DESACTIVADO ){
  //desactivamos los relays
  switch(Relay){
    /*Este switch sirve para elegir qué relay va a ser desactivado.*/
    
    case 1: pinMode (RLY_1,OUTPUT);
            digitalWrite (RLY_1, 0);
            Serial.println("RELAY 1 DESACTIVADO");
            break;
            
    case 2: pinMode (RLY_2,OUTPUT);
            digitalWrite (RLY_2, 0);
            Serial.println("RELAY 2 DESACTIVADO");
            break;
            
   default: pinMode (RLY_1,OUTPUT);
            digitalWrite (RLY_1, 0);
            pinMode (RLY_2,OUTPUT);
            digitalWrite (RLY_2, 0);
            Serial.println("RELAYS DESACTIVADOS. VALOR INGRESADO NO COMPATIBLE CON LOS PARAMETROS INDICADOS. INTENTE NUEVAMENTE"); 
            break;           
 }}}
 
  //***********************************ULTRASONIDO**************************************

//**************FUNCIONES******************

 long Medir_Distancia (void){
  /*Esta función nos otorga la medición de la distancia que lee el ultrasonido. 
  Vale aclarar que es una función tomada de una librería y que si no la hubiesemos incluido, no podríamos usar la función.*/
// Distancia= ULTS.read(CM);                       // .read es igual a .ranging
 Serial.println (Distancia);                      
 return Distancia;
 /*Se desarrolla con el tipo de variable long ya que es el dato que devuelve en nuestra variable distancia con el return.*/
}

  //***********************************PINES ANALOGICOS**************************************

//**************FUNCIONES******************
int VALOR_SW (int Switch){
  /*Esta función simplemente lee y devuelve el valor del switch y lo imprime en pantalla.*/
  SW = analogRead (SWITCH);
  Serial.println (SW);
  return SW;
  }
  
int VALOR_POT (int orden){
  /*Esta función nos permite leer y devolver el valor del potenciometro elegido por el usuario*/
  switch (orden){
    /*Este switch nos permite elegir entre el potenciometro 1 y el 2.
    En el que el caso 1 se refiere al pot1 y el caso 2 al pot2*/
    
  case 1: POT1 = analogRead (POT_1);
          Serial.println (POT1);
          return POT1;
          break;
 
  case 2: POT2 = analogRead (POT_2);
          Serial.println (POT2);
          return POT2;
          break;

  default: Serial.println("VALOR INGRESADO NO COMPATIBLE CON LOS PARAMETROS INDICADOS. INTENTE NUEVAMENTE"); 
  break;
  }}
  
int VALOR_FREEpin (int orden){
  /*Esta función nos permite leer y devolver el valor del pin analógico libre elegido por el usuario*/
  switch (orden){
    /*Este switch nos permite elegir entre los pines analógicos libres 1, 2 y 3.*/
  
  case 1: FREE1 = analogRead (FREE_1);
                  Serial.println(FREE1);
                  return FREE1;
                  break;

  case 2:  FREE2 = analogRead (FREE_2);
                   Serial.println (FREE2);
                   return FREE2;
                   break;
  case 3 : FREE3 = analogRead (FREE_3);
                   Serial.println (FREE3);
                   return FREE3;
                   break;

 default: Serial.println("VALOR INGRESADO NO COMPATIBLE CON LOS PARAMETROS INDICADOS. INTENTE NUEVAMENTE"); 
  }}
