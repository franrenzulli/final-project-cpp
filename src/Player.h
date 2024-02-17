#ifndef PLAYER_H
#define PLAYER_H
#include "Object.h"
#include <SFML/Window/Keyboard.hpp>

class HealthBar;  // declaración anticipada

class Player : public Object{
public:
	Player(bool player_one);
	void Update(bool player_one, Player& opponent, HealthBar& opponentHealthBar);
	void SetLife(float perc);
	float GetLife();
	void Attack(Player& opponent);
	bool CheckCollision(const Player& other) const;
private:
	bool player_one; // Indica si es el jugador 1 o el 2 
	sf::Keyboard::Key m_up, m_right, m_down, m_left; // Teclas
	bool m_isJumping;
	bool m_wasAttackPressed;
	float m_jumpSpeed;
	float life_percent = 100.0;
};

#endif

