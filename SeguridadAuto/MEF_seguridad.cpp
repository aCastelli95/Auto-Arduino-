// 
// 
// 
#include "MEF_seguridad.h"

#include <Arduino.h>

MEF_seguridad::MEF_seguridad()
{

}

void MEF_seguridad::cambio_Intermedios(char tecla, LiquidCrystal lcd)
{
	switch (tecla) {

	case('A') :
		// habilito el acceso cuando pienso q se termino de ingresar la contraseña
		if (estado == CONTRASENIA) {
			if (clave.actualizarActual()) {

				lcd.setCursor(0, 1);
				lcd.print("              ");
				lcd.setCursor(0, 0);
				lcd.print("  CORRECTO      ");
				lcd.setCursor(0, 1);
				delay(1000);
				lcd.print("  DIVIERTASE    ");
				delay(3000);
				// hay que mandarlo al estado de ENCENDIDO
				lcd.setCursor(0, 0);
				lcd.print("              ");
				lcd.setCursor(0, 1);
				lcd.print("              ");
				estado = ENCENDIDO;
			}else {
				lcd.setCursor(0, 0);
				lcd.print("              ");
				lcd.setCursor(0, 1);
				lcd.print("              ");
				lcd.setCursor(0, 0);
				lcd.print("  INCORRECTO  ");
				delay(3000);
				lcd.setCursor(0, 1);
				lcd.print("              ");
				lcd.setCursor(0, 0);
				lcd.print("  CONTRASENIA  ");
				lcd.setCursor(0, 1);
			}
		}
		break;

	case('B') :
		// cancela todo
		clave.cancelar();
		estado = IDLE;
		// DEPENDIENDO EL estado anterior veo que mostrar en el LCD, si BIENVENIDO O u pausado, apagado etc.

		break;

	case('C') :
		// CONFIRMAR cambio de contraseña
		if (estado == CAMBIO_CONTRASENIA) {
			if (clave.actualizarCambioCon()) {

				lcd.setCursor(0, 1);
				lcd.print("              ");
				lcd.setCursor(0, 0);
				lcd.print("  CORRECTO      ");
				lcd.setCursor(0, 1);
				delay(1000);
				lcd.print("CONTRASENIA CAMB");
				delay(3000);
				// hay que mandarlo al estado IDLE
				lcd.setCursor(0, 0);
				lcd.print("                ");
				lcd.setCursor(0, 1);
				lcd.print("                ");
				estado = IDLE;
				
				
			}
			else {
				lcd.setCursor(0, 0);
				lcd.print("              ");
				lcd.setCursor(0, 1);
				lcd.print("              ");
				lcd.setCursor(0, 0);
				lcd.print("  INCORRECTO  ");
				delay(3000);
				lcd.setCursor(0, 1);
				lcd.print("              ");
				lcd.setCursor(0, 0);
				lcd.print("CAMBIO CONT. :  ");
				lcd.setCursor(0, 1);
			}
		}
		break;

	case('D') :
		// presionamos y salimos del estado IDLE
		// todavia no se q hacerle
	case('*') :
		// cambio contraseña
		if (estado == IDLE) {
			lcd.setCursor(0, 0);
			lcd.print("CAMBIO CONT. :  ");
			lcd.setCursor(0, 1);
			delay(2000);
			lcd.print("INGERSAR");
			delay(2000);
			lcd.setCursor(0, 1);
			lcd.print("                ");
			estado = CAMBIO_CONTRASENIA;
		}
		
	    break;
	case('#') :
		
		if (estado == IDLE) {
			lcd.setCursor(0, 0);
			lcd.print("  CONTRASENIA  ");
			estado = CONTRASENIA;
		}
		break;
	default:

		break;
	}
}


void MEF_seguridad::cambio_Estado(char tecla, LiquidCrystal lcd)
{	
	switch (estado){
	case(IDLE):
			//Espera de que se cambie de orden.
		break;
	case( CONTRASENIA ) :
			// si es un numero lo guardo en el vector de arreglos de ingersado.
		if ((tecla >= 48) && (tecla <= 57)) {
			clave.ingreso(tecla,lcd);
		}

		break;
	case(CAMBIO_CONTRASENIA) :
			// Si es u numero lo guardo en el coso de ingersado.
		if ((tecla >= 48) && (tecla <= 57)) {
			clave.ingreso(tecla, lcd);
		}
		break;
	case (ENCENDIDO) :
		// Funcionamiento del auto.
		lcd.setCursor(0, 0);
		lcd.print("   ENCENDIDO    ");

		// arranque del motor.
		break;
	case (APAGADO) :

		// VEO SI PONERLO EN ESPERA O simplemente utilizar el IDLE que seria como lo mismo, capazu if o algo soluciona este espacio.

		break;

	default:
		
		break;
	}
}


/*case('1') :

if (estado == CONTRASENIA) {
// VOY PARA GUARDAR LA LETRA EN LA CONTRASENIA
clave.ingreso(tecla);
lcd.setCursor(posCursorClave + 5, 1);
lcd.print("*");
posCursorClave++;
}

break;

case('2') :


if (e == CONTRASENIA) {
// VOY PARA GUARDAR LA LETRA EN LA CONTRASENIA
clave.ingreso(tecla);
lcd.setCursor(posCursorClave + 5, 1);
lcd.print("*");
posCursorClave++;
}

break;

case('3') :

if (estado == CONTRASENIA) {
// VOY PARA GUARDAR LA LETRA EN LA CONTRASENIA
clave.ingreso(tecla);
lcd.setCursor(posCursorClave + 5, 1);
lcd.print("*");
posCursorClave++;
}
break;

case('4') :

if (estado == CONTRASENIA) {
// VOY PARA GUARDAR LA LETRA EN LA CONTRASENIA
clave.ingreso(tecla);
lcd.setCursor(posCursorClave + 5, 1);
lcd.print("*");
posCursorClave++;
}

break;

case('5') :


if (estado == CONTRASENIA) {
// VOY PARA GUARDAR LA LETRA EN LA CONTRASENIA
clave.ingreso(tecla);
lcd.setCursor(posCursorClave + 5, 1);
lcd.print("*");
posCursorClave++;
}

break;

case('6') :


if (e == CONTRASENIA) {
// VOY PARA GUARDAR LA LETRA EN LA CONTRASENIA
clave.ingreso(tecla);
lcd.setCursor(posCursorClave + 5, 1);
lcd.print("*");
posCursorClave++;
}

break;

case('7') :


if (e == CONTRASENIA) {
// VOY PARA GUARDAR LA LETRA EN LA CONTRASENIA
clave.ingreso(tecla);
lcd.setCursor(posCursorClave + 5, 1);
lcd.print("*");
posCursorClave++;
}

break;

case('8') :

if (e == CONTRASENIA) {
// VOY PARA GUARDAR LA LETRA EN LA CONTRASENIA
clave.ingreso(tecla);
lcd.setCursor(posCursorClave + 5, 1);
lcd.print("*");
posCursorClave++;
}
break;

case('9') :


if (e == CONTRASENIA) {
// VOY PARA GUARDAR LA LETRA EN LA CONTRASENIA
clave.ingreso(tecla);
lcd.setCursor(posCursorClave + 5, 1);
lcd.print("*");
posCursorClave++;
}

break;

case('0') :


if (e == CONTRASENIA) {
// VOY PARA GUARDAR LA LETRA EN LA CONTRASENIA
clave.ingreso(tecla);
lcd.setCursor(posCursorClave + 5, 1);
lcd.print("*");
posCursorClave++;
}

break;*/