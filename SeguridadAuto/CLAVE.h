// CLAVE.h

#ifndef _CLAVE_h
#define _CLAVE_h
#include <LiquidCrystal.h>
class CLAVE
{
public:
	CLAVE();
	void ingreso(char tecla, LiquidCrystal lcd);
	char actualizarActual();
	char actualizarCambioCon();
	void cancelar();

private:
		
	int cantPosActual = 5;
	int cantPosIngresado = 0; 
	char actual[5] = { '1','2','3','4','5' };
	char ingresado[5] = { '0','0','0','0','0' };
};

#endif

