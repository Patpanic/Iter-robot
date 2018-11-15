#include "Arduino.h"
//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	//PC connexion
	Serial.begin(9600);
	Serial.println("Ecoute du module BT");

	//BT connexion
	Serial1.begin(9600);
	Serial1.println("Iter robot bonjour");

}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	if(Serial1.available())
		Serial.write(Serial1.read());

	if(Serial.available())
		Serial1.write(Serial.read());

}
