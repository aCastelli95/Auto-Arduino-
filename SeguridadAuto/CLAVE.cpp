// 
// 
// 

#include "CLAVE.h"
#include <LiquidCrystal.h>
#include "Arduino.h"

CLAVE::CLAVE()
{
}

void CLAVE::ingreso(char tecla, LiquidCrystal lcd)
{
	if (cantPosIngresado < 5){
		ingresado[cantPosIngresado] = tecla;
		lcd.setCursor(cantPosIngresado+5,1);
		lcd.print("*");
	}
	cantPosIngresado++;
}

void CLAVE::cancelar()
{
	cantPosIngresado = 0;
	for (int i = 0; i < cantPosActual; i++) {
		ingresado[i] = '0';
	}
}

char CLAVE::actualizarActual()
{
	// verifico primero la longitud de la actual con lo ingresado, si no es correcto ya tiro error
	if ((cantPosIngresado > cantPosActual) || (cantPosIngresado < cantPosActual)){
		cancelar();
		return 0;
	}else {
		while(cantPosIngresado < cantPosActual) {
			if (ingresado[cantPosIngresado] == actual[cantPosIngresado]) {
				cantPosIngresado--;
			} else {
				cantPosIngresado = 0;
				return 0;
				}
			}
		}
	cantPosIngresado = 0;
	return 1;
}

char CLAVE::actualizarCambioCon() {

	if ((cantPosIngresado > cantPosActual) || (cantPosIngresado == 0)) {
		// si no se ingersan 5 la clave no es segura, por lo que rebota y te manda error para el cambio.
		cancelar();
		return 0;
	}else {
		cantPosActual = cantPosIngresado;
		for (int i = 0; i < cantPosActual; i++) {
			actual[i] = ingresado[i];
			}// fin del for
		cantPosIngresado = 0;
		return 1;
		}
}



