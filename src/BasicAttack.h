#ifndef BASICATTACK_H
#define BASICATTACK_H
#include "Attack.h"
#include "Player.h"

class BasicAttack : public Attack {
public:
	BasicAttack();
	void PerformAttack(Player& attacker, Player& opponent) override;
private:
};

#endif

