/* Classe de commande des moteurs
 * sans utilisation des encodeurs
 * pour des mouvements simples
 */

#include "IterMoteurSimple.h"

#include "Arduino.h"
#include <DRV8835MotorShield.h>


/* Faire avancer le robot à la vitesse vit
 * 0 < vit < 300
 *
 */
void IterMoteurSimple::avancer(int vit) {

	setSpeeds(vit,vit);

}


/* Faire tourner le robot vers la droite
 * 0 < ecart < 100
 *
 */
void IterMoteurSimple::tournerAdroite(int ecart, int vit) {

	float ect = vit*ecart/100;

	setSpeeds(vit,vit - ect);

}


/* Faire tourner le robot vers la gauche
 * 0 < ecart < 100
 *
 */
void IterMoteurSimple::tournerAgauche(int ecart, int vit) {

	float ect = vit*ecart/100;

	setSpeeds(vit - ect ,vit);

}

/* Faire reculer le robot
 * vitesse limitée
 * 0 <= vit <= 200
 *
 */
void IterMoteurSimple::reculer(int vit) {

	int vitesse = vit;
	if (vitesse > 0)
		vitesse = - vitesse;
	if (vitesse < -200)
		vitesse = -200;

	setSpeeds(vitesse,vitesse);

}


/* Stoper le robot
 *
 */
void IterMoteurSimple::stop() {

	setSpeeds(0,0);

}


/*
 * Tourner à plat dans le sens horaire
 * à vitesse 0 <= vit <= 150
 * vitesse limitée
 *
 */
void IterMoteurSimple::rotationHoraire(int vit) {

	int vitesse = vit;
	if (vitesse < 0)
		vitesse = - vitesse;
	if (vitesse > 150)
		vitesse = 150;

	setSpeeds(vitesse,-vitesse);

}


/*
 *  Tourner à plat dans le sens antihoraire
 *	à vitesse 0 <= vit <= 150
 *  vitesse limitée
 */
void IterMoteurSimple::rotationAntihoraire(int vit) {

	int vitesse = vit;
	if (vitesse < 0)
		vitesse = - vitesse;
	if (vitesse > 150)
		vitesse = 150;

	setSpeeds(-vitesse, vitesse);

}
