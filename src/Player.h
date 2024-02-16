#ifndef PLAYER_H
#define PLAYER_H
#include "Object.h"
#include <SFML/Window/Keyboard.hpp>

class Player : public Object{
public:
	Player(bool player_one);
	void Update();
private:
	bool player_one; // Indica si es el jugador 1 o el 2 
	sf::Keyboard::Key m_up, m_right, m_down, m_left; // Teclas
	bool m_isJumping;
	float m_jumpSpeed;
};

#endif

