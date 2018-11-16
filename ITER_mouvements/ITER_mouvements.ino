#include "Arduino.h"
#include "IterMouvements.h"
//The setup function is called once at startup of the sketch
IterMouvements mouv;
void setup()
{
// Add your initialization code here
	delay(3000);
	mouv.avancer(200);
	delay(1000);
	//mouv.rotationGaucheAngle(90,100);
	mouv.stop();
	mouv.rotationDroiteAngle(90,100);
	mouv.stop();

}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
}
