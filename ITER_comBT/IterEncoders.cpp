/*
 * IterEncoders.cpp
 *
 *  Created on: 25 oct. 2017
 *      Author: patrice
 */

#include "IterEncoders.h"

static volatile uint16_t countEncRT, countEncLT;

void rightISR(void) {
	/*
	 * Incrémenter le compteur droit
	 * Quand une interruption est générée par l'encodeur droit
	 */
	noInterrupts();

	countEncRT += 1;

	interrupts();

}

void leftISR(void) {
	/*
	 * Incrémenter le compteur gauche
	 * Quand une interruption est générée par l'encodeur gauche
	 */
	noInterrupts();

	countEncLT += 1;

	interrupts();

}



void IterEncoders::initEnc() {
	/*Initialisation des interruptions externes
	 * pour les encodeurs droit et gauche
	 */
	pinMode(encRTA , INPUT_PULLUP);
	pinMode(encLTA , INPUT_PULLUP);
	countEncRT = 0;
	countEncLT = 0;
	attachInterrupt(digitalPinToInterrupt(encRTA), rightISR, CHANGE);
	attachInterrupt(digitalPinToInterrupt(encLTA), leftISR, CHANGE);
}

void IterEncoders::stopEnc() {
	/*
	 * Arrête la prise en compte des interruptions externes
	 */

	detachInterrupt(digitalPinToInterrupt(encRTA));
	detachInterrupt(digitalPinToInterrupt(encLTA));
	countEncRT = 0;
	countEncLT = 0;
}

uint16_t IterEncoders::getCountsEncRT(void) {
	/*
	 * Renvoie l'état du compteur d'impulsion de la roue droite
	 * 6 impulsions par tour moteur
	 * réducteur 3952:33
	 * soit 718 impulsions par tour de roue
	 */
	noInterrupts();
	uint16_t counts = countEncRT;
	interrupts();
	return counts;

}

uint16_t IterEncoders::getCountsEncLT(void) {
	/*
	 * Renvoie l'état du compteur d'impulsion de la roue gauche
	 * 6 impulsions par tour moteur
	 * réducteur 3952:33
	 * soit 718 impulsions par tour de roue
	 */
	noInterrupts();
	uint16_t counts = countEncLT;
	interrupts();
	return counts;

}

void IterEncoders::resetCountsEncLT(void) {
	/*
	 * Remet à zéro le compteur d'impulsion de la roue gauche
	 */
	noInterrupts();
	countEncLT = 0;
	interrupts();

}

void IterEncoders::resetCountsEncRT(void) {
	/*
	 * Remet à zéro le compteur d'impulsion de la roue droite
	 */
	noInterrupts();
	countEncRT = 0;
	interrupts();

}
