#include "Arduino.h"
#include "IterMoteurSimple.h"
//The setup function is called once at startup of the sketch

IterMoteurSimple mouv;
void setup()
{
// Add your initialization code here
	delay(5000);
	mouv.avancer(250);
	delay(1000);
	mouv.rotationHoraire(150);
	delay(1000);
	mouv.rotationAntihoraire(150);
	delay(1000);
	mouv.reculer(100);
	delay(1000);
	mouv.stop();
	delay(3000);
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here


}
