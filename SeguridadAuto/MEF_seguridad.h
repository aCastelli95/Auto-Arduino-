// MEF_seguridad.h

#ifndef _MEF_SEGURIDAD_h
#define _MEF_SEGURIDAD_h
#include "CLAVE.h"
#include <LiquidCrystal.h>
class MEF_seguridad {

public:
	MEF_seguridad();
	void cambio_Intermedios(char tecla, LiquidCrystal lcd);
	void cambio_Estado(char tecla, LiquidCrystal lcd);

private:
	CLAVE clave;
	int posCursorClave = 0;
	enum estados { IDLE, 
					CONTRASENIA, 
					CAMBIO_CONTRASENIA, 
					ENCENDIDO,
					APAGADO
					}; // Fin de los estados del auto.

	estados estado = IDLE;
};

#endif

