/* Classe de commande des moteurs
 * sans utilisation des encodeurs
 * pour des mouvements simples
 */

#ifndef ITERMOTEURSIMPLE_H_
#define ITERMOTEURSIMPLE_H_
#include "Arduino.h"


#include <DRV8835MotorShield.h>

/*
 * Commande simple des mouvements du robot
 * Hérite de la classe DRVDRV8835MotorShield qui commande
 * le double pont en H du driver moteur
 */
class IterMoteurSimple : private  DRV8835MotorShield{


	public:
		/* Avancer à la vitesse 0 <= vit <= 300 */
		void avancer(int vit);



		/*
		 * Virage à droite
		 * à vitesse 0 <= vit <= 200
		 * la roue droite tourne à ecart % de la roue gauche
		 *
		 */
		void tournerAdroite(int ecart, int vit);





		/*
		 * Virage à gauche
		 * à vitesse 0 <= vit <= 200
		 * la roue gauche tourne à ecart % de la roue droite
		 *
		 */
		void tournerAgauche(int ecart, int vit);



		/*
		 * Faire reculer le robot
		 * vitesse limitée
		 * 0 <= vit <= 200
		 *
		 */
		void reculer(int vit);


		/* Stoper le robot */
		void stop();


		/* Tourner à plat dans le sens horaire
		 * vu de dessus
		 */
		void rotationHoraire(int vit);


		/* Tourner à plat dans le sens antihoraire
		 * vu de dessus
		 */
		void rotationAntihoraire(int vit);

};








//Do not add code below this line
#endif /* _hermes_lib_mot_simple_H_ */
