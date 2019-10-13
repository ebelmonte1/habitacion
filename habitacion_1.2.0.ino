/*Habitacion codigo Version 1.2.0 
 * Cambios:
 * Envo de temperatura por bluetooth
 */
#define ACT 0
#define DESAC 1
#define DELAY 500
#define DIR 1
#define DHTPIN PIN_11
#define DHTTYPE DHT11 
#define PIN_13 13 
#define PIN_12 12 
#define PIN_11 11
#define PIN_10 10
#define PIN_9 9
#define PIN_8 8
#define PIN_7 7
#define PIN_6 6
#define PIN_5 5
#define PIN_4 4
#define PIN_3 3
#define PIN_2 2
#define PRX_BT PIN_2 
#define PTX_BT PIN_3
#define TRIG PIN_4   
#define ECHO PIN_5
#define RLY_1 PIN_6  
#define RLY_2 PIN_7
#define RLY_3 PIN_8  
#define RLY_4 PIN_9
#include <Ultrasonic.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>
#include "DHT.h"
SoftwareSerial BT(PRX_BT,PTX_BT);
Ultrasonic sensor(TRIG,ECHO); // (Trig PIN,Echo PIN, microsegundos max "distancia máxima") 30000us = 5 metros.
long int distancia=50;//Variable para almacenar la distancia medida. 
byte valor;
float t_set=23 ;
DHT dht(DHTPIN, DHTTYPE);
void setup() 
{
 digitalWrite (13, 0);
 digitalWrite (RLY_1, DESAC);
 digitalWrite (RLY_2, DESAC);
 digitalWrite (RLY_3, DESAC);
 digitalWrite (RLY_4, DESAC);
 Serial.begin(9600);
 BT.begin(9600); // Velocidad serial del Modulo BT
 dht.begin();
 pinMode(RLY_1,OUTPUT);
 pinMode(RLY_2,OUTPUT);
 pinMode(RLY_3,OUTPUT);
 pinMode(RLY_4,OUTPUT);
 Serial.println("hola");
}
char estadoBT;
char estado; 
void loop() 
{
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
 
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
 
  // Calcular el índice de calor en grados centígrados
  float hic = dht.computeHeatIndex(t, h, false);
 
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("Índice de calor: ");
  Serial.print(hic);
  Serial.println(" *C ");
  
  
 estadoBT=(BT.read());
 estado=(Serial.read());
 Serial.print("BT :");
 Serial.println(estadoBT);
 distancia = (sensor.read(CM));//Medimos la distancia y la guardamos en la variable
 Serial.print("DISTANCIA :");
 Serial.println(distancia);

if(estado=='q'){        
  Serial.println("valor enviado");
  BT.print(t);
  BT.println("ºC");
  estado=0;
 }
 if(estadoBT=='q'){ 
  Serial.println("valor enviado");       
  BT.print(t);
  BT.println("ºC");
  estadoBT=0;
 }
/* 
 *  //EN DESARROLLO
 if(t_set>=t){ 
  digitalWrite (RLY_4, 1);
  Serial.println("AIRE ACONDICIONADO ENCENDIDO");
 }
 if (t_set<t){ 
  digitalWrite (RLY_4, 0);
  Serial.println("AIRE ACONDICIONADO APAGADO");
 }
 */
 
 //presencia
 if (distancia<20)
 {
            digitalWrite (RLY_1, ACT);
            Serial.println("RELAY 1 ACTIVADO");
 }
 
 delay(DELAY);
 //Relay 1
 if (estado=='a')
 {
 digitalWrite (RLY_1, ACT);
            Serial.println("RELAY 1 ACTIVADO");
 }
 if (estado=='b')
 {
 digitalWrite (RLY_1, DESAC);
            Serial.println("RELAY 1 DESACTIVADO");
 } 
 //Relay 2
 if (estado=='c')
 {
 digitalWrite (RLY_2, ACT);
            Serial.println("RELAY 2 ACTIVADO");
 }
 if (estado=='d')
 {
 digitalWrite (RLY_2, DESAC);
            Serial.println("RELAY 2 DESACTIVADO");
 } 
 //Relay 3
 if (estado=='e')
 {
 digitalWrite (RLY_3, ACT);
            Serial.println("RELAY 3 ACTIVADO");
 }
 if (estado=='f')
 {
 digitalWrite (RLY_3, DESAC);
            Serial.println("RELAY 3 DESACTIVADO");
 } 
 //Relay 4
 if (estado=='g')
 {
 digitalWrite (RLY_4, ACT);
            Serial.println("RELAY 4 ACTIVADO");
 }
 if (estado=='h')
 {
 digitalWrite (RLY_4, DESAC);
            Serial.println("RELAY 4 DESACTIVADO");
 } 
 //BT
 //Relay 1
 if (estadoBT=='a')
 {
 digitalWrite (RLY_1, ACT);
            Serial.println("RELAY 1 ACTIVADO");
 }
 if (estadoBT=='b')
 {
 digitalWrite (RLY_1, DESAC);
            Serial.println("RELAY 1 DESACTIVADO");
 } 
 //Relay 2
 if (estadoBT=='c')
 {
 digitalWrite (RLY_2, ACT);
            Serial.println("RELAY 2 ACTIVADO");
 }
 if (estadoBT=='d')
 {
 digitalWrite (RLY_2, DESAC);
            Serial.println("RELAY 2 DESACTIVADO");
 } 
 //Relay 3
 if (estadoBT=='e')
 {
 digitalWrite (RLY_3, ACT);
            Serial.println("RELAY 3 ACTIVADO");
 }
 if (estadoBT=='f')
 {
 digitalWrite (RLY_3, DESAC);
            Serial.println("RELAY 3 DESACTIVADO");
 } 
 //Relay 4
 if (estadoBT=='g')
 {
 digitalWrite (RLY_4, ACT);
            Serial.println("RELAY 4 ACTIVADO");
 }
 if (estadoBT=='h')
 {
 digitalWrite (RLY_4, DESAC);
            Serial.println("RELAY 4 DESACTIVADO");
 } 
 }
