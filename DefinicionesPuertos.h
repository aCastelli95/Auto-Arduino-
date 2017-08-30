// DefinicionesPuertos.h

#ifndef _DEFINICIONESPUERTOS_h
#define _DEFINICIONESPUERTOS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

/*
	Especifica con claridad los puertos de una forma que sea generico, en el caso que se queiran cambiar, accedemos y se cambiara de forma manual 
	o simplemente se reconectara cada puerto del microcontrolador.

*/
//Definicion de las ruedas
#define RUEDA_T_DERECHA 
#define RUEDA_T_IZQUIERDA
#define RUEDA_D_DERECHA  // no sabemos si lo vamos a usar, por ahora las declaro, de ultima le pongo dos puertos que no se utilizan
#define RUEDA_D_IZQUIERDA // no sabemos si lo vamos a usar, por ahora las declaro, de ultima le pongo dos puertos que no se utilizan

//Definicion del bluetooth
#define BT_RX  //a este puerto se le conecta el TX del modulo Bluetooth
#define BT_TX  //a este puerto se le conecta el TX del modulo Bluetooth

//Definicion del Servo 
#define SV_VOLANTE 

//Definicion del sensor de Ultrasonido
#define US_ELEMENTO_POSICION

//Definicion del LCD 16x2
#define LCD_RS 
#define LCD_EN
#define LCD_D4
#define LCD_D5
#define LCD_D6
#define LCD_D7
#define LCD_BRILLO //A partir de u potenciometro se desarrolla el control de intensidad/brillo en el mismo

//Definicion del Sistema de luces
#define 

#endif

