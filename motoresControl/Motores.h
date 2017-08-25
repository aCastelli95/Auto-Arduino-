// Motores.h

#ifndef _MOTORES_h
#define _MOTORES_h
#include <SoftwareSerial.h>

class Motores{

	public:
		Motores();
		void valor_VelocidadBT(SoftwareSerial bt);

	private:
		char val; // contiene el valor de entrada del bluetooth que viene bit a bit.
		String vel; // variable velocidad
		int valorFinal; // contiene la velocidad actual


};

#endif

