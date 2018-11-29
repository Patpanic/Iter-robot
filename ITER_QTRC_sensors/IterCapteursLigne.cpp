/*
 * ITERCapteursLigne.cpp
 *
 *  Created on: 30 oct. 2017
 *      Author: patrice
 */
#include "IterCapteursLigne.h"

#include "Arduino.h"
#include "QTRSensors.h"


#define NUM_SENSORS   6     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   37     // emitter is controlled by digital pin 37
#define SH	800				// Seuil haut détection du noir
#define SB	400				// Seuil bas détection du blanc

QTRSensorsRC qtrrc((unsigned char[]) {27, 26, 25, 24, 23, 22},
				NUM_SENSORS, TIMEOUT, EMITTER_PIN);

unsigned int sensorValues[NUM_SENSORS];


IterCapteursLigne::IterCapteursLigne() {
	// TODO Auto-generated constructor stub
	// Création d'un objet capteur
	/*
	 * Position des capteurs :
	 *
	 * gauche2   gauche1   gauche   droit   droit1   droit2
	 *
	 */
	droite = 0;
	gauche = 0;
	droite1 = 0;
	gauche1 = 0;
	droite2 = 0;
	gauche2 = 0;
	poidsDroite = 0;
	poidsGauche = 0;

}

uint8_t IterCapteursLigne::lire() {
	/*
	 * lire l'état binaire des capteurs de ligne
	 * et actualiser les attributs pour une utilisation plus facile
	 * Renvoyer la valeur lue (0 à 63)
	 */
	uint8_t etatCapteurs = _lireCapteursTOR();
	droite = (etatCapteurs & 4) >> 2;
	gauche = (etatCapteurs & 8) >> 3;
	droite1 = (etatCapteurs & 2) >> 1;
	gauche1 = (etatCapteurs & 16) >> 4;
	droite2 = (etatCapteurs & 1);
	gauche2 = (etatCapteurs & 32) >> 5;
	poidsDroite = etatCapteurs & 7;
	poidsGauche = gauche2 + (gauche1 << 1) + (gauche << 2);
	return etatCapteurs;

}

uint8_t IterCapteursLigne::_trigger(int sensorValue) {

	/* Traite la valeur renvoyée par un capteur
	 * renvoie
	 * 1 si sensorValue > SH, ligne noire détectée
	 * 0 si sensorValue < SB, ligne noire non détectée
	 * 2 si sensorValue est dans la bande morte
	 * Réalise un comparateur non inverseur à hystérésis
	 */
	if (sensorValue > SH)
		return 1;

	else if (sensorValue < SB)
		return 0;

	else
		return 2;

}

uint8_t IterCapteursLigne::_lireCapteursTOR() {
	/* Renvoie un nombre image de l'état des 6 capteurs
	 * 0 => que du blanc
	 * 1 => noir à droite
	 * 32 => noir à gauche
	 * 63 => noir sous tous les capteurs
	 */
	uint8_t etat = 0;
	static uint8_t etatCapteurs = 0; // etatCpateurs est conservé quand la fonction est terminée
	qtrrc.read(sensorValues);
	// Traitement des valeurs brutes lues
	for (uint8_t i = 0; i < NUM_SENSORS; i++)
	  {
		etat = _trigger(sensorValues[i]);  // etat d'un capteur selon la valeur brute lue

		// Si on n'est pas dans la bande morte, actualiser l'état du capteur
		if (etat != 2){
			if (etat == 0) {
				etat = 1 << i;
				etatCapteurs = etatCapteurs & (~etat);  //mettre à zéro le bit correspondant au capteur
			}

			else {
				etatCapteurs = etatCapteurs | (etat << i);
			}
		}

	  }
	return etatCapteurs;
}

