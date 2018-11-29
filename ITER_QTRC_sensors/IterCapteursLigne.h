/*
 * IterCapteursLigne.h
 * Utiliser les capteurs de ligne à réflexion
 * QTRRC de polulu
 *
 *  Created on: 30 oct. 2017
 *      Author: patrice
 */

#ifndef ITERCAPTEURSLIGNE_H_
#define ITERCAPTEURSLIGNE_H_
#include "Arduino.h"
class IterCapteursLigne {

public:
	// Constructeur
	IterCapteursLigne();
	uint8_t lire();
	/*
	 * Position des capteurs :
	 *
	 * gauche2   gauche1   gauche   droit   droit1   droit2
	 *
	 */
	uint8_t droite;
	uint8_t gauche;
	uint8_t droite1;
	uint8_t gauche1;
	uint8_t droite2;
	uint8_t gauche2;
	uint8_t poidsDroite;
	uint8_t poidsGauche;

private:
	uint8_t _trigger(int sensorValue);
	uint8_t _lireCapteursTOR(void);

	uint8_t _sensorValues[];

};

#endif /* ITERCAPTEURSLIGNE_H_ */
