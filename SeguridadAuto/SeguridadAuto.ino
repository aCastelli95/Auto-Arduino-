
#include <LiquidCrystal.h>
#include "CLAVE.h"
#include "MEF_seguridad.h"

#include "RTC.h"

#include <Arduino.h>
#include<Keypad.h>

LiquidCrystal lcd(32, 30, 22, 24, 26, 28);
// INICIO TECLADO
const byte Filas = 4;          //Cuatro filas
const byte Cols = 4;           //Cuatro columnas
byte Pins_Filas[] = { 39, 41, 43,45  };     //Pines Arduino para las filas
byte Pins_Cols[] = { 47,49,51,53 };     // Pines Arduinopara las columnas
char Teclas[Filas][Cols] =
{
	{ '1','2','3','A' },
	{ '4','5','6','B' },
	{ '7','8','9','C' },
	{ '*','0','#','D' }
};
Keypad Teclado1 = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Cols, Filas, Cols);
//-----------------------------------------------
MEF_seguridad mefS;
void setup()
{
	
	Serial.begin(9600);
	lcd.begin(16, 2);
	lcd.setCursor(3, 0);
	lcd.println("BIENVENIDO    ");
	lcd.setCursor(1, 1);
	lcd.print("                 ");

}

void loop()
{
	char pulsacion = Teclado1.getKey();
	if (pulsacion != 0) {             // Si el valor es 0 es que no se
		//Serial.println(pulsacion);   // se ha pulsado ninguna tecla
		mefS.cambio_Intermedios(pulsacion, lcd);
		mefS.cambio_Estado(pulsacion, lcd);
	}
}
