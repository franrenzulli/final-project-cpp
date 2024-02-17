#include <iostream>
#include "Player.h"
#include "HealthBar.h"
#include <SFML/Window/Keyboard.hpp>

using namespace sf;

Player::Player(bool player_one) : Object(player_one ? "../assets/images/ken.png" : "../assets/images/ryu.png") {
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
	m_wasAttackPressed = false;
	
}

void Player::Update(bool player_one, Player& opponent, HealthBar& opponentHealthBar){ // Input de teclas para movimientos
	if (life_percent > 0){ // chequea que el jugador este vivo
		if(Keyboard::isKeyPressed(m_left)){
			m_sprite.setScale(1,1);
			m_sprite.move(-5,0);		
		}
		
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
			
			// La textura cambia segun que jugador es
			if(!player_one){
				ChangeTexture("../assets/images/ryujumping.png");
			}else{
				ChangeTexture("../assets/images/kenjumping.png");
			}
			
			// Incrementar la velocidad vertical (simulando la gravedad)
			m_jumpSpeed += 0.7f;
			
			// Comprobar si el jugador aterrizo
			if(m_sprite.getPosition().y >= 300){
				m_sprite.setPosition(m_sprite.getPosition().x, 300);
				m_isJumping = false;
				
				// La textura cambia segun que jugador es
				if(!player_one){
					ChangeTexture("../assets/images/ryu.png");
				}else{
					ChangeTexture("../assets/images/ken.png");
				}
			}
		}
		
		// solo funciona para P1
		bool isAttackPressed = player_one ? Keyboard::isKeyPressed(Keyboard::J) : Keyboard::isKeyPressed(Keyboard::K);
		
		if (player_one && isAttackPressed && !m_wasAttackPressed) {
			Attack(opponent, player_one);
		}else if(!player_one && isAttackPressed && !m_wasAttackPressed){
			Attack(opponent, !player_one);
		}
		
		/*
		realiza el ataque solo cuando la tecla pasa de no estar presionada a estar presionada. 
		Con esto nos evitamos múltiples ejecuciones de Attack() ya que antes cuando apretábamos la letra J
		El ataque se realizaba muchas veces en simultáneo
		*/
		m_wasAttackPressed = isAttackPressed;
	}
	
	
}

bool Player::CheckCollision(const Player& other) const {
	return Object::CheckCollision(other);
}

void Player::Attack( Player& opponent, bool attackerIsPlayerOne){
	
	float damage = 2.0f;
	
	if(CheckCollision(opponent) && attackerIsPlayerOne){
		
		// restamos vida al oponente
		opponent.SetLife(opponent.GetLife() - damage);
		
	}else if( opponent.CheckCollision(*this) && !attackerIsPlayerOne ){
		SetLife(GetLife() - damage);
	}
	
	std::cout<<"¡Ataque realizado! Causa " << damage << " de daño." << std::endl;
}

void Player::SetLife(float perc) {
	life_percent = perc;
}

float Player::GetLife() {
	return life_percent;
}
