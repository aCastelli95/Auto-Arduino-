// 
// 
// 

#include "Motores.h"
#include "Arduino.h"
Motores::Motores()
{
}

/* Funcion que va guardando todo en variable String y que luego se ira 
*/
void Motores::valor_VelocidadBT(SoftwareSerial bt)
{
	while (bt.available()) {
		val = bt.read();
		if (val != 'A') {
			vel += val;
		}
		else {
			// realizamos la salida a las tracciones de las ruedas
			analogWrite(9, vel.toInt());
			analogWrite(3, vel.toInt());
			vel = "";

		}
	}

}
