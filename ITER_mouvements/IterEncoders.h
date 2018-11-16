/*
 * IterEncoders.h
 *
 *  Created on: 25 oct. 2017
 *      Author: patrice
 *
 * bibliothèque de gestion des encodeurs
 * utilisation des interruptions externes pour compter les impulsions du codeurs
 * de la roue droite et gauche.
 * Sur le front montant de la broche 2/3 on incrémente un compteur
 *
 *
 */

#ifndef ITERENCODERS_H_
#define ITERENCODERS_H_

#include "Arduino.h"

#define encRTA  2  // Broche d'interruption encodeur droit

#define encLTA  3  // Broche d'interruption encodeur gauche





class IterEncoders {
public:
	void initEnc(void);
	void stopEnc(void);
	uint16_t getCountsEncRT(void);
	uint16_t getCountsEncLT(void);
	void resetCountsEncLT(void);
	void resetCountsEncRT(void);

};

#endif /* ITERENCODERS_H_ */
