#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player(bool player_one) : Object(player_one?"../assets/images/ken.png":"../assets/images/ryu.png") {
	if(player_one){
		m_sprite.setPosition(400,300); // Posicion inicial de player 1
		m_up = sf::Keyboard::Key::W;
		m_right = sf::Keyboard::Key::D;
		m_down = sf::Keyboard::Key::S;
		m_left = sf::Keyboard::Key::A;
		m_sprite.setScale(-1,1);
		
	}else{
		m_sprite.setPosition(1000,300); // Posicion inicial de player 2
		m_up = sf::Keyboard::Key::Up;
 		m_right = sf::Keyboard::Key::Right;
		m_down = sf::Keyboard::Key::Down;
		m_left = sf::Keyboard::Key::Left;
	}
	
	// Pone el centro del sprite como el origen, para que el cambio de escalas no afecte la visibilidad
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, 0);
}

void Player::Update(){ // Input de teclas para movimientos
	if(sf::Keyboard::isKeyPressed(m_left)){
		m_sprite.setScale(1,1);
		m_sprite.move(-5,0);		
	}
	
	if(sf::Keyboard::isKeyPressed(m_right)){
		m_sprite.move(+5,0);
		m_sprite.setScale(-1,1);
	}
}

int Player::GetLifes() {
	return left_lifes;
}
