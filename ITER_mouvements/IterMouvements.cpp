/*
 * IterMouvements.cpp
 *
 *  Created on: 27 oct. 2017
 *      Author: patrice
 */

#include "Arduino.h"
#include "DRV8835MotorShield.h"
#include "IterEncoders.h"
#include "IterMouvements.h"

#define KDEG 8.554

//const float kdeg = 8.554;  // imp = kdeg * angle  imp: nombre d'impulsion encodeur, angle: angle de rotation du robot en degr�

void IterMouvements::avancer(int vitesse) {
		/* Faire avancer le IterMouvements à la vitesse vit
		 * 0 <= vit <= 300
		 *
		 */
		int vit = vitesse;
		if(vit<0)
			vit = -vit;
		if(vit > 300)
			vit = 300;

		setSpeeds(vit,vit);
}

void IterMouvements::tournerAdroite(int ecart, int vitesse) {
	/* Faire tourner le IterMouvements vers la droite
	 * 0 < ecart < 100
	 *
	 */
	float ect = ecart;
	int vit = vitesse;
	if(ect < 0)
			ect = -ect;
	if(ect > 100)
		ect = 100;

	if(vit < 0)
		vit = -vit;
	if(vit > 300)
		vit = 300;

	ect = vit*ecart/100;

	setSpeeds(vit,vit - ect);

}

void IterMouvements::tournerAgauche(int ecart, int vitesse) {
	/* Faire tourner le IterMouvements vers la gauche
	 * 0 < ecart < 100
	 *
	 */
	float ect = ecart;
	int vit = vitesse;
	if(ect < 0)
			ect = -ect;
	if(ect > 100)
		ect = 100;

	if(vit < 0)
		vit = -vit;
	if(vit > 300)
		vit = 300;

	ect = vit*ecart/100;

	setSpeeds(vit - ect ,vit);

}

void IterMouvements::reculer(int vitesse) {
	/* Faire reculer le IterMouvements
	 * vitesse limitée à 50%
	 * 0 <= vit <= 200
	 *
	 */
	int vit = vitesse;
	if (vit > 0)
		vit = - vit;
	if (vit < -200)
		vit = -200;

	setSpeeds(vit,vit);

}

void IterMouvements::stop() {
	/* Stoper le IterMouvements
	 *
	 */

	setSpeeds(0,0);

}

void IterMouvements::tournerAgaucheAngle(int angle, int vitesse) {

	int ang = angle;
	int vit = vitesse;
	uint16_t imps;
	if (ang < 0)
		ang = -ang;
	if (ang > 180)
		ang = 180;
	//A trouver fonction de transfert impulsions = f(angle)
	imps = KDEG*ang;

	initEnc();

	while(getCountsEncLT() < imps) {
		setSpeeds(0,vit);
		delay(50);
	}
	setSpeeds(0,0);
	stopEnc();
}

void IterMouvements::tournerAdroiteAngle(int angle, int vitesse) {

	int ang = angle;
	int vit = vitesse;
	uint16_t imps;
	if (ang < 0)
		ang = -ang;
	if (ang > 180)
		ang = 180;
	//A trouver fonction de transfert impulsions = f(angle)
	imps = KDEG*ang;
	initEnc();

	while(getCountsEncRT() < imps) {
		setSpeeds(vit,0);
		delay(50);
	}
	setSpeeds(0,0);
	stopEnc();
}


void IterMouvements::rotationDroite(int vitesse) {
	/* Faire tourner le robot autour de son centre (le milieu de l'axe des roues)
	 *
	 */
	int vit = vitesse;
	if (vit < 0)
		vit = - vit;
	if (vit > 200)
		vit = 200;

	setSpeeds(-vit,vit);

}

void IterMouvements::rotationGauche(int vitesse) {
	/* Faire tourner le robot autour de son centre (le milieu de l'axe des roues)
	 *
	 */
	int vit = vitesse;
	if (vit < 0)
		vit = - vit;
	if (vit > 200)
		vit = 200;

	setSpeeds(vit,-vit);

}

void IterMouvements::rotationGaucheAngle(int angle, int vitesse) {

	int ang = angle;
	int vit = vitesse;
	uint16_t imps;
	if (ang < 0)
		ang = -ang;
	if (ang > 180)
		ang = 180;

	imps = KDEG/2*ang; // Consigne de rotation en nombre d'impulsions codeur

	initEnc();

	while(getCountsEncLT() < imps) {
		setSpeeds(-vit,vit);
		delay(50);
	}
	setSpeeds(0,0);
	stopEnc();
}

void IterMouvements::rotationDroiteAngle(int angle, int vitesse) {

	int ang = angle;
	int vit = vitesse;
	uint16_t imps;
	if (ang < 0)
		ang = -ang;
	if (ang > 180)
		ang = 180;

	imps = KDEG/2*ang;
	initEnc();

	while(getCountsEncRT() < imps) {
		setSpeeds(vit,-vit);
		delay(50);
	}
	setSpeeds(0,0);
	stopEnc();
}
