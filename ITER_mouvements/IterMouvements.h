/*
 * HERMESunoMotors.h
 *
 *  Created on: 27 oct. 2017
 *      Author: patrice
 */

#ifndef ITERMOUVEMENTS_H_
#define ITERMOUVEMENTS_H_

#include "Arduino.h"
#include "DRV8835MotorShield.h"
#include "IterEncoders.h"

class IterMouvements : public DRV8835MotorShield, public IterEncoders{
public:
	void avancer(int vitesse);
	void tournerAdroite(int ecart, int vitesse);
	void tournerAgauche(int ecart, int vitesse);
	void reculer(int vitesse);
	void stop();
	void tournerAdroiteAngle(int angle, int vitesse);
	void tournerAgaucheAngle(int angle, int vitesse);
	void rotationDroite(int vitesse);
	void rotationGauche(int vitesse);
	void rotationDroiteAngle(int angle, int vitesse);
	void rotationGaucheAngle(int angle, int vitesse);

};

#endif /* ITERMOUVEMENTS_H_ */
