#include <QTRSensors.h>

#include "Arduino.h"
#include "IterCapteursLigne.h"

//Créer une instance de la classe IterCapteursLigne
IterCapteursLigne cl;
//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	// Utilisation du port série sur USB
	Serial.begin(115200);
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here

	char message[10];	//Un buffer de 10 caractères
	uint8_t valCapteurs = cl.lire();	//Lire les capteurs
	//Formater une chaîne de caractère image de l'état des capteurs
	sprintf(message,"%d %d %d %d %d %d", cl.gauche2, cl.gauche1, cl.gauche, cl.droite, cl.droite1, cl.droite2);
	Serial.println(message);
	sprintf(message, "%d | %d", cl.poidsGauche, cl.poidsDroite);
	Serial.println(message);
	Serial.println(valCapteurs);

	delay(200);  //Répéter la boucle toutes les 200ms (5 fois par seconde)
}
