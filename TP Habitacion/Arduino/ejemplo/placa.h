/* BIENVENIDOS A NUESTRO HERMOSO DESARROLLO. A CONTINUACI�N SE MUETRA DETALLADAMENTE TODO EL PROCESO NECESARIO 
 * PARA OPERAR NUESTRA PLACA SIN NECESIDAD DE SER UN EXPERTO.
 * GRACIAS. ATTE: JOHNSSON & JOHNSSON COMPANY S.A.                          
 *                                                                                             PD: PATENTE EN TR�MITE.
 */ 
//******************LIBRERIAS*****************
/*incluimos las librerias necesarias para el desarrollo y la relacion de nuestros dispositivos y de sus funciones correspondientes.*/

#include <SoftwareSerial.h>
//#include <Ultrasonic.h>

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
/*#define PIN_A5 5
#define PIN_A4 4
#define PIN_A3 3
#define PIN_A2 2
#define PIN_A1 1
#define PIN_A0 0*/

#define NORMALSERIAL 9600

//***********************************MOTORES**************************************
/*1 horrio
2
3
4 muerto etc
*/
 /*                         TABLAS DE COMBINACIONES

  * En1 1A 2A   MOTOR 1        *                * En2 3A 4A   MOTOR 2        *                     
  *  o  -  -    no anda        *                *  o  -  -    no anda        *  
  *  1  1  0    horario        *                *  1  1  0    horario        *
  *  1  0  1    antihorario    *                *  1  0  1    antihorario    *
  *  1  0  0    muerto         *                *  1  0  0    muerto         *
  *  1  1  1    enclavamiento  *                *  1  1  1    enclavamiento  *
  */

//********************DEFINES*******************
/*definimos los pines del arduino con el nombre del terminal del integrado L293D conectado a cada uno de los mismos.*/
#define A_1 8
#define A_2 9
#define A_3 12
#define A_4 13
#define EN1 10
#define EN2 11


//************VARIABLES GLOBALES************
int Vel;
 
//****************PROTOTIPOS*****************

/*Se crea el prototipo del motor. En la cual se integran el giro horario y el antihorario, clavar el motor y usar el motor como muerto.
El usuario debe indicar qu� modo de operaci�n quiere emplear, en qu� motor y a qu� velocidad.*/

//MOTORES POR INDIVIDUAL
void MOTOR (int,int,int);

  

/*Se crea el prototipo en el cual se integran el avance y el retroceso, utilizando ambos motores en simult�neo.
El usuario debe indicar a qu� velocidad desea operar.*/

//AMBOS MOTORES
void Avanzar (int);
void Reversa (int);

/*Se crea el prototipo en el cual se integran el giro de 180� tanto hacia la derecha como hacia la izquierda y los giros simples tambi�n para ambos lados. 
 * Utilizando ambos motores en simult�neo. El usuario debe indicar a qu� velocidad desea operar.*/

//GIROS DE AMBOS MOTORES
void Giro180_DER (void);
void Giro180_IZQ (void);
void Giro_DER (int);
void Giro_IZQ (int);

//COMANDOS BASICOS
void Antihorario(int, int);
void Horario(int, int);

void Clavar(int);
//***********************************BT**************************************

//********************DEFINES*******************
/*definimos los pines del bluetooth relacionados a los pines rx y tx conectados al arduino a los terminales 2 y 3.*/
#define PRX_BT PIN_2  
#define PTX_BT PIN_3
  
//****************PROTOTIPOS*****************
/*Se crea el proto de la librer�a del BT*/
SoftwareSerial BT (PRX_BT,PTX_BT);


//***********************************RELAYS************************************************

//********************DEFINES*******************
/*definimos los pines de los relays relacionados a los pines conectados al arduino a los terminales 6 y 7.*/
#define RLY_1 PIN_6  
#define RLY_2 PIN_7
#define ACTIVADO 1
#define DESACTIVADO 0


//****************PROTOTIPOS*****************
/*El usuario debe ingresar qu� relay quiere usar y si lo quiere activar o desactivar*/
void RELAY(int, char);

//***********************************ULTRASONIDO**************************************

//********************DEFINES*******************
/*definimos los pines del US relacionados a los pines trig y echo conectados al arduino a los terminales 4 y 5.*/
#define US_TRIG PIN_4
#define US_ECHO PIN_5

//************VARIABLES GLOBALES************

long Distancia;
//Ultrasonic ULTS (US_TRIG,US_ECHO);

//****************PROTOTIPOS*****************
/*devuelve el valor medido por el US*/
long Medir_Distancia (void);

//***********************************PINES ANALOGICOS**************************************

//********************DEFINES*******************
/*definimos los pines anal�gicos relacionados a los pines conectados al arduino a los terminales: switch = A 0
                                                                                                  pote 1 = A 1
                                                                                                  pote 2 = A 2
                                                                                                  libre 1 = A3
                                                                                                  libre 2 = A4
                                                                                                  libre 3 = A5.*/
#define SWITCH PIN_A0
#define POT_1 PIN_A1
#define POT_2 PIN_A2
#define FREE_1 PIN_A3
#define FREE_2 PIN_A4
#define FREE_3 PIN_A5

//************VARIABLES GLOBALES************
int SW;
int POT1;
int POT2;
int FREE1;
int FREE2;
int FREE3;

//****************PROTOTIPOS*****************
int VALOR_SW (int);
int VALOR_POT (int);//se ingresa qu� pote desea usar el usuario.
int VALOR_FREEpin (int);//se ingresa qu� pin desea usar el usuario.

void iniciar(void);
