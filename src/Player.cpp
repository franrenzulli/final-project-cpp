#include <iostream>
#include "Player.h"
#include "HealthBar.h"
#include <SFML/Window/Keyboard.hpp>

using namespace sf;
using namespace std;

Player::Player(bool player_one) : Object(player_one ? "../assets/images/ken.png" : "../assets/images/ryu.png") {
	this->player_one = player_one;
	if(player_one){
		m_sprite.setPosition(400,300); // Posicion inicial de player 1
		m_up = Keyboard::Key::W;
		m_right = Keyboard::Key::D;
		m_down = Keyboard::Key::S;
		m_left = Keyboard::Key::A;
		m_attackBasic = Keyboard::Key::J;
		m_sprite.setScale(-1,1);
		
	}else{
		m_sprite.setPosition(1000,300); // Posicion inicial de player 2
		m_up = Keyboard::Key::Up;
		m_right = Keyboard::Key::Right;
		m_down = Keyboard::Key::Down;
		m_left = Keyboard::Key::Left;
		m_attackBasic = Keyboard::Key::K;
	}
	
	// Pone el centro del sprite como el origen, para que el cambio de escalas no afecte la visibilidad
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, 0);
	
	// variables para el salto
	m_isJumping = false;
	m_jumpSpeed = 0.0f;
	m_wasAttackPressed = false;
	
}

void Player::Update(Player& opponent){ // Input de teclas para movimientos
	if (life_percent > 0){ // chequea que el jugador este vivo
		ValidateScreenLimits();
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
			
			if (player_one) {
				ChangeTexture("../assets/images/kenjumping.png");
			} else {
				ChangeTexture("../assets/images/ryujumping.png");
			}
			
			// Incrementar la velocidad vertical (simulando la gravedad)
			m_jumpSpeed += 0.7f;
			
			// Comprobar si el jugador aterrizo
			if(m_sprite.getPosition().y >= 300){
				m_sprite.setPosition(m_sprite.getPosition().x, 300);
				m_isJumping = false;
				
				// La textura cambia segun que jugador es
				if (player_one) {
					ChangeTexture("../assets/images/ken.png");
				} else {
					ChangeTexture("../assets/images/ryu.png");
				}
			}
		}
	}

	// ahora funciona un lujo
	bool isAttackPressed = Keyboard::isKeyPressed(m_attackBasic);
	
	if (isAttackPressed && !m_wasAttackPressed) {
		Attack(opponent);
	}
	
	/*
	realiza el ataque solo cuando la tecla pasa de no estar presionada a estar presionada. 
	Con esto nos evitamos múltiples ejecuciones de Attack() ya que antes cuando apretábamos la letra J
	El ataque se realizaba muchas veces en simultáneo
	*/
	m_wasAttackPressed = isAttackPressed;
	
	// --- SPECIAL ATTACK ---
	
	// movimiento -> sf::seconds()
	m_deltaTime = seconds(0.0166667f);
	
	// Actualizar las bolas de fuego
	for (auto& fireball : fireballs) {
		fireball.Update(m_deltaTime.asSeconds());
	}
	
	// Eliminar las bolas de fuego que salieron de la pantalla
	fireballs.erase(remove_if(fireballs.begin(), fireballs.end(),
								   [](const Fireball& fireball) {
									   return fireball.GetBounds().left > 1280;  // Cambia el valor según el ancho de la ventana
								   }), fireballs.end());
	
	// Ataque especial
	bool isSpecialAttackPressed = player_one ? Keyboard::isKeyPressed(Keyboard::Space) : Keyboard::isKeyPressed(Keyboard::I);
	if (isSpecialAttackPressed && !m_wasSpecialAttackPressed) {
		SpecialAttack(opponent);
	}
	
	m_wasSpecialAttackPressed = isSpecialAttackPressed;
	
}

bool Player::CheckCollision(const Player& other) const {
	return Object::CheckCollision(other);
}

void Player::Attack( Player& opponent ){
	float damage = 10.0f;
	
	if(CheckCollision(opponent)){
		// le restamos vida al player 2
		opponent.SetLife(opponent.GetLife() - damage);
	} else if(opponent.CheckCollision(*this)){
		//le restamos vida al player 1
		SetLife(GetLife() - damage);
	}
	std::cout<<"¡Ataque realizado! Causa " << damage << " de daño." << std::endl;
}

void Player::SpecialAttack(Player& opponent) {
	if (life_percent > 0) { // Solo puede realizar el ataque especial si el jugador está vivo
		Fireball newFireball(m_sprite.getPosition().x, m_sprite.getPosition().y, 500.0f);  // 500.0f es la velocidad
		fireballs.push_back(newFireball);
	}
}

void Player::SetDeltaTime(sf::Time deltaTime) {
	m_deltaTime = deltaTime;
}

void Player::SetLife(float perc) {
	life_percent = perc;
}

float Player::GetLife() {
	return life_percent;
}


void Player::ValidateScreenLimits() {
	auto pos = m_sprite.getPosition();
	if (pos.x > 1280)
		m_sprite.setPosition(1280, pos.y);
	
	if (pos.x < 0)
		m_sprite.setPosition(0, pos.y);
}
