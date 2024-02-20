// TODO

#ifndef SPECIALATTACK_H
#define SPECIALATTACK_H

#include "Attack.h"

class SpecialAttack : public Attack {
public:
	SpecialAttack() : Attack("../assets/images/fireball.png", 20.0f, 10) {}
	
	// Implementaci�n de la funci�n virtual pura
	virtual void PerformAttack(Player& attacker, Player& opponent) override;
};

#endif

