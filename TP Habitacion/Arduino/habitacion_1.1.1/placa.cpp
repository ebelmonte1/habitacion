/* BIENVENIDOS A NUESTRAS HERMOSAS FUNCIONES. A CONTINUACIÓN SE DESARROLLAN DETALLADAMENTE TODAS LAS FUNCIONES NECESARIAS PARA OPERAR NUESTRA PLACA SIN NECESIDAD DE SER UN EXPERTO.
 * GRACIAS. ATTE: JOHNSSON & JOHNSSON COMPANY S.A.                          
 *                                                                                             PD: PATENTE EN TRÁMITE.
 */
#include <Arduino.h>
#include <SoftwareSerial.h>
 
#include "placa.h"
void iniciar (void) {
  Serial.begin(NORMALSERIAL);
}



//***********************************RELAY************************************************

//**************FUNCIONES******************
void RELAY (int Relay, int Estado){
  /*En esta función de los relays se otorgan dos variables al usuario. La primera indica que relay va a ser usado(el primero o el segundo)
  y la segunda variable indica su estado (activado o desactivado).*/
  if (Estado == 1 ){
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
    case 3: pinMode (RLY_3,OUTPUT);
            digitalWrite (RLY_3, 1);
            Serial.println("RELAY 3 ACTIVADO");
            break;
            
    case 4: pinMode (RLY_4,OUTPUT);
            digitalWrite (RLY_4, 1);
            Serial.println("RELAY 4 ACTIVADO");
            break;        
   default: pinMode (RLY_1,OUTPUT);
            digitalWrite (RLY_1, 0);
            pinMode (RLY_2,OUTPUT);
            digitalWrite (RLY_2, 0);
            pinMode (RLY_3,OUTPUT);
            digitalWrite (RLY_3, 0);
            pinMode (RLY_4,OUTPUT);
            digitalWrite (RLY_4, 0);
            Serial.println("RELAYS DESACTIVADOS. VALOR INGRESADO NO COMPATIBLE CON LOS ARAMETROS INDICADOS. INTENTE NUEVAMENTE");
            break; }
  } else if (Estado == 0 ){
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
    case 3: pinMode (RLY_3,OUTPUT);
            digitalWrite (RLY_3, 0);
            Serial.println("RELAY 3 DESACTIVADO");
            break;        
    case 4: pinMode (RLY_4,OUTPUT);
            digitalWrite (RLY_4, 0);
            Serial.println("RELAY 4 DESACTIVADO");
            break;
                                         
   default: pinMode (RLY_1,OUTPUT);
            digitalWrite (RLY_1, 0);
            pinMode (RLY_2,OUTPUT);
            digitalWrite (RLY_2, 0);
            pinMode (RLY_3,OUTPUT);
            digitalWrite (RLY_3, 0);
            pinMode (RLY_4,OUTPUT);
            digitalWrite (RLY_4, 0);
            Serial.println("RELAYS DESACTIVADOS. VALOR INGRESADO NO COMPATIBLE CON LOS PARAMETROS INDICADOS. INTENTE NUEVAMENTE"); 
            break;           
 }}}
 
  
