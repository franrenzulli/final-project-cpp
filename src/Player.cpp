#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

using namespace sf;

Player::Player(bool player_one) : Object(player_one?"../assets/images/ken.png":"../assets/images/ryu.png") {
	if(player_one){
		m_sprite.setPosition(400,300); // Posicion inicial de player 1
		m_up = Keyboard::Key::W;
		m_right = Keyboard::Key::D;
		m_down = Keyboard::Key::S;
		m_left = Keyboard::Key::A;
		m_sprite.setScale(-1,1);
	
	}else{
		m_sprite.setPosition(1000,300); // Posicion inicial de player 2
		m_up = Keyboard::Key::Up;
 		m_right = Keyboard::Key::Right;
		m_down = Keyboard::Key::Down;
		m_left = Keyboard::Key::Left;
		
	}

	// Pone el centro del sprite como el origen, para que el cambio de escalas no afecte la visibilidad
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, 0);
	
	// variables para el salto
	m_isJumping = false;
	m_jumpSpeed = 0.0f;
	
}

void Player::Update(){ // Input de teclas para movimientos 
	// Movimiento izq
	if(Keyboard::isKeyPressed(m_left)){
		m_sprite.setScale(1,1);
		m_sprite.move(-5,0);		
	}
	
	
	// Movimiento derecha
	if(Keyboard::isKeyPressed(m_right)){
		m_sprite.move(+5,0);
		m_sprite.setScale(-1,1);
	}
	
	// salto
	if (Keyboard::isKeyPressed(m_up) && !m_isJumping) {
		m_isJumping = true;
		m_jumpSpeed = -20.0f;
	}
	
	// movimiento vertical
	if(m_isJumping){
		// Aplicar movimiento vertical para el salto
		m_sprite.move(0, m_jumpSpeed);
		
		// Incrementar la velocidad vertical (simulando la gravedad)
		m_jumpSpeed += 0.7f;
		
		// Comprobar si el jugador aterrizo
		if(m_sprite.getPosition().y >= 300){
			m_sprite.setPosition(m_sprite.getPosition().x, 300);
			m_isJumping = false;
		}
	}
}
