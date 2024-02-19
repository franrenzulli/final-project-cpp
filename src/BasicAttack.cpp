#include "BasicAttack.h"
#include <iostream>

BasicAttack::BasicAttack() : Attack("../assets/images/ken.png", 10.0f, 100) {}

void BasicAttack::PerformAttack (Player& attacker, Player & opponent) {
	attacker.ChangeTexture(m_texFilename);
	if(attacker.CheckCollision(opponent)){
		// le restamos vida al player 2
		opponent.SetLife(opponent.GetLife() - m_damage);
		std::cout << "¡Ataque efectivo! Causa " << m_damage << " de daño. " << "+" << m_scoresIfSuccessful << "points." << std::endl;
	}
	std::cout << "El ataque no fue efectivo." << std::endl;
	
}

