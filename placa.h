/* BIENVENIDOS A NUESTRO HERMOSO DESARROLLO. A CONTINUACI�N SE MUETRA DETALLADAMENTE TODO EL PROCESO NECESARIO 
 * PARA OPERAR NUESTRA PLACA SIN NECESIDAD DE SER UN EXPERTO.
 * GRACIAS. ATTE: JOHNSSON & JOHNSSON COMPANY S.A.                          
 *                                                                                             PD: PATENTE EN TR�MITE.
 */ 
//******************LIBRERIAS*****************
/*incluimos las librerias necesarias para el desarrollo y la relacion de nuestros dispositivos y de sus funciones correspondientes.*/

#include <SoftwareSerial.h>

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



#define NORMALSERIAL 9600


//***********************************BT**************************************

//********************DEFINES*******************
/*definimos los pines del bluetooth relacionados a los pines rx y tx conectados al arduino a los terminales 2 y 3.*/
#define PRX_BT PIN_2  
#define PTX_BT PIN_3
  


//***********************************RELAYS************************************************

//********************DEFINES*******************
/*definimos los pines de los relays relacionados a los pines conectados al arduino a los terminales 6 y 7.*/
#define RLY_1 PIN_6  
#define RLY_2 PIN_7
#define RLY_3 PIN_8  
#define RLY_4 PIN_9


//****************PROTOTIPOS*****************
/*El usuario debe ingresar qu� relay quiere usar y si lo quiere activar o desactivar*/
void RELAY(int, int);
