#include <SoftwareSerial.h>

SoftwareSerial bluetooth(11, 10); // RX, TX

char motores[3];
int length = 0;
int total = 0;
int multiplo = 100;
void setup() {
	// Open serial communications and wait for port to open:
	pinMode(9, OUTPUT);
	Serial.begin(9600);
	bluetooth.begin(9600); //esto es para cuando esta funcionando ya configurado
				   //bluetooth.begin(38400);  en modo configuracion AT

	while (!Serial) {
		; // wait for serial port to connect. Needed for native USB port only
	}


	Serial.println("Motor velocidad:");

	// set the data rate for the SoftwareSerial port
}

void loop() { // run over and over
	while (bluetooth.available()) {
		int a = bluetooth.read() - '0' ;
		if (a != 17) {
			 // hay que tener cuidado de la forma que se realzia la lectura, lo que se puede hacer es guardaren un array los valores y despues levantarlos.
			total = total + multiplo * a;
			multiplo = multiplo / 10;
			delay(10);
			length++;
		}
		else {
			Serial.println(total);
			total = 0;
			multiplo = 1;
		}
	}
	analogWrite(9, total);
	/*
	if (Serial.available()) {
	bluetooth.write(Serial.read());
	}*/
	
}