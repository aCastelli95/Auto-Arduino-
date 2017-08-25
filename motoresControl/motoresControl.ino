
#include "Motores.h"
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(11, 10); // RX, TX
Motores traseros;


void setup() {
	// Open serial communications and wait for port to open:
	pinMode(3, OUTPUT);
	Serial.begin(9600);
	bluetooth.begin(9600); //esto es para cuando esta funcionando ya configurado
						   //bluetooth.begin(38400);  en modo configuracion AT

	while (!Serial) {
		; // wait for serial port to connect. Needed for native USB port only
	}


	Serial.println("Velociadd marcada por la aplicación");

	// set the data rate for the SoftwareSerial port
}
void loop() { // run over and over
	traseros.valor_VelocidadBT(bluetooth);
}