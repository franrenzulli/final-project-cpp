#ifndef ATTACK_H
#define ATTACK_H
#include <string>

// declaracion anticipada
class Player;

// -- Clase para modularizar los ataques y reducir la repeticion de codigo

class Attack {
public:
	Attack(std::string texFilename, float damage, int scores);
	virtual void PerformAttack(Player& attacker, Player& opponent) =0;
protected:
	float m_damage;
	float m_scoresIfSuccessful;
	std::string m_texFilename;
};

#endif

