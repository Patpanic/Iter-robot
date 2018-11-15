#include "Arduino.h"
//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
// Test sans commit
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
	// Ecoute du module BT
	if(Serial1.available())
		Serial.write(Serial1.read()); //Ecrire le caractère sur le port série du PC

	// Ecoute du port série du PC
	if(Serial.available())
		Serial1.write(Serial.read()); //Ecrire le caractère reçu sur le module BT

}
