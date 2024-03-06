#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <sstream>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <iostream>
using namespace sf;
using namespace std;


Player::Player(bool player_one, string name, Texture &tex) : Object(tex), m_name(name) {
	this->player_one = player_one;	
	
	// carga las texturas
	if (m_name == "Ryu") {
		// cargar texturas de ryu
		m_normalTex.loadFromFile("../assets/images/ryu/ryu.png");
		m_jumpTex.loadFromFile("../assets/images/ryu/ryu_saltando.png");
		m_basicAtkTex.loadFromFile("../assets/images/ryu/ryu_patada.png");
		m_crouchTex.loadFromFile("../assets/images/ryu/ryu_agachado.png");
	} 
	if (m_name == "Ken") {
		// cargar texturas de ken
		m_normalTex.loadFromFile("../assets/images/ken/ken.png");
		m_jumpTex.loadFromFile("../assets/images/ken/ken_saltando.png");
		m_basicAtkTex.loadFromFile("../assets/images/ken/ken_patada.png");
		m_crouchTex.loadFromFile("../assets/images/ken/ken_agachado.png");
	}
	if (m_name == "Retsu") {
		// cargar texturas de retsu
		m_normalTex.loadFromFile("../assets/images/retsu/retsu.png");
		m_jumpTex.loadFromFile("../assets/images/retsu/retsu_saltando.png");
		m_basicAtkTex.loadFromFile("../assets/images/retsu/retsu_pina.png");
		m_crouchTex.loadFromFile("../assets/images/retsu/retsu_agachado.png");
	}
	if (m_name == "Michael") {
		// cargar texturas de michael
		m_normalTex.loadFromFile("../assets/images/mike/mike.png");
		m_jumpTex.loadFromFile("../assets/images/mike/mike_saltando.png");
		m_basicAtkTex.loadFromFile("../assets/images/mike/mike_pina.png");
		m_crouchTex.loadFromFile("../assets/images/mike/mike_agachado.png");
	}
	
	m_fireballTex.loadFromFile("../assets/images/fireball.png");
	
	if(player_one){
		m_sprite.setPosition(400,300); // Posicion inicial de player 1
		m_sprite.setScale(-4, 4);
		if (m_name == "Michael") {
			m_sprite.setScale(-3.5, 3.5);	
		}
		m_up = Keyboard::Key::W;
		m_right = Keyboard::Key::D;
		m_down = Keyboard::Key::S;
		m_left = Keyboard::Key::A;
		m_attackBasic = Keyboard::Key::J;
		
	}else{
		m_sprite.setPosition(1000,300); // Posicion inicial de player 2
		m_sprite.setScale(4,4);
		if (m_name == "Michael") {
			m_sprite.setScale(-3.5, 3.5);	
		}
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
	m_isCrouching = false;
	m_isStanding = false;
	
	m_wasAttackPressed = false;
	
	m_kickSoundBuff.loadFromFile("../assets/sounds/kick.wav");
	m_jumpSoundBuff.loadFromFile("../assets/sounds/jump.wav");
	m_fireballSoundBuff.loadFromFile("../assets/sounds/fireball.wav");
}

void Player::Update(Player& opponent){
	if (GetLife() > 0 && opponent.GetLife() > 0){ // chequea que el jugador este vivo
		// Input de teclas para movimientos
		ValidateScreenLimits();
		if (Keyboard::isKeyPressed(m_left)){
			if (m_name == "Michael") {
				m_sprite.setScale(3.5, 3.5);	
			} else {
				m_sprite.setScale(4, 4);
			}
			m_sprite.move(-5,0);		
		}
		
		if (Keyboard::isKeyPressed(m_right)){
			if (m_name == "Michael") {
				m_sprite.setScale(-3.5, 3.5);	
			} else {
				m_sprite.setScale(-4, 4);
			}
			m_sprite.move(+5,0);
		}
		
		if (Keyboard::isKeyPressed(m_down) && !m_isJumping) {
			Crouch();
		} else if (!m_isJumping && !m_isStanding) {
			StandUp();
		}		
		
		// salto
		if (Keyboard::isKeyPressed(m_up) && !m_isJumping) {
			m_soundEffect.setBuffer(m_jumpSoundBuff);
			
			m_isJumping = true;
			m_jumpSpeed = -20.0f;
			
			m_soundEffect.play();
		}
		
		// movimiento vertical
		if(m_isJumping){
			// Aplicar movimiento vertical para el salto
			m_sprite.move(0, m_jumpSpeed);
			
			// La textura cambia
			ChangeTexture(m_jumpTex);
			
			// Incrementar la velocidad vertical (simulando la gravedad)
			m_jumpSpeed += 0.7f;
			
			// Comprobar si el jugador aterrizo
			if(m_sprite.getPosition().y >= 300){
				m_sprite.setPosition(m_sprite.getPosition().x, 300);
				m_isJumping = false;
				
				// La textura cambia segun que jugador es
				ChangeTexture(m_normalTex);
			}
		}

		bool isAttackPressed = Keyboard::isKeyPressed(m_attackBasic);
		if (isAttackPressed && !m_wasAttackPressed && !m_texWasChangedOnBasicAttack) {
			m_soundEffect.setBuffer(m_kickSoundBuff);
			BasicAttack(opponent);
			m_soundEffect.play();
		}
		if (m_clock.getElapsedTime().asSeconds()> 0.75f && m_texWasChangedOnBasicAttack) {
			ChangeTexture(m_normalTex);
			m_texWasChangedOnBasicAttack =  false;
		}	
		
		
		// realiza el ataque solo cuando la tecla pasa de no estar presionada a estar presionada. 
		m_wasAttackPressed = isAttackPressed;
		
		// --- SPECIAL ATTACK ---
		
		// movimiento -> sf::seconds()
		m_deltaTime = seconds(0.0166667f);

		// Actualizar las bolas de fuego
		for (auto& fireball : fireballs) {
			fireball.Update(m_deltaTime.asSeconds());
			
			float fireballDamage = 30.0f;
			// Verificar colisión con el oponente
			if (fireball.CheckCollision(opponent)) {
				// Restar vida al oponente
				opponent.SetLife(opponent.GetLife() - fireballDamage);
				m_score += 500;
				// Eliminar la bola de fuego
				fireball = fireballs.back();  // Copiamos la última bola de fuego al lugar de la actual
				fireballs.pop_back();         // Eliminamos la última bola de fuego (que ahora está duplicada)
			}
		}
		
		// Eliminar las bolas de fuego que salieron de la pantalla
		fireballs.erase(remove_if(fireballs.begin(), fireballs.end(),
								  [](const Fireball& fireball) {
									  return fireball.GetBounds().left > 1280;  // Cambia el valor según el ancho de la ventana
								  }), fireballs.end());
		
		
		// Ataque especial
		bool isSpecialAttackPressed = player_one ? Keyboard::isKeyPressed(Keyboard::Space) : Keyboard::isKeyPressed(Keyboard::I);
		if (isSpecialAttackPressed && !m_wasSpecialAttackPressed) {
			m_soundEffect.setBuffer(m_fireballSoundBuff);
			SpecialAttack(opponent);
			m_soundEffect.play();
		}
		
		m_wasSpecialAttackPressed = isSpecialAttackPressed;
	}
}

bool Player::CheckCollision(const Player& other) const {
	return Object::CheckCollision(other);
}


void Player::BasicAttack(Player& opponent) {
	float damage = 10.0f;
	int scores = 100;
	m_clock.restart();
	ChangeTexture(m_basicAtkTex);
	
	m_texWasChangedOnBasicAttack = true;
	
	if(CheckCollision(opponent)){
		// le restamos vida al oponente
		opponent.SetLife(opponent.GetLife() - damage);
		m_score += scores;
	}
}

void Player::SpecialAttack(Player& opponent) {
	// se chequea que el jugador esta vivo en Player::Update()
	float speed;
	speed = 500.0f; // velocidad y direccion del disparo
	
	// Hacemos que las bolas de fuego cambien de direccion segun adonde mira el personaje
	Vector2f scale = m_sprite.getScale();
	if(scale.x < 0){
		Fireball newFireball(m_fireballTex, m_sprite.getPosition().x, m_sprite.getPosition().y, speed); 
		fireballs.push_back(newFireball);
		std::cout<<"New fireball created"<<std::endl;
	}else if(scale.x > 0){
		Fireball newFireball(m_fireballTex, m_sprite.getPosition().x, m_sprite.getPosition().y, -speed);  
		fireballs.push_back(newFireball);
		std::cout<<"New fireball created"<<std::endl;
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
vector<Fireball>& Player::GetFireballs() {
	return fireballs;
}

std::string Player::GetScoreStr() {
	std::stringstream scoreStr;
	scoreStr<<m_score;
	return scoreStr.str();
}

void Player::restart(bool player_one){
	if(player_one){
		if (m_name == "Michael") {
			m_sprite.setScale(-3.5, 3.5);	
		} else {
			m_sprite.setScale(-4, 4);
		}
		m_sprite.setPosition(400,300);
	}else{
		if (m_name == "Michael") {
			m_sprite.setScale(3.5, 3.5);	
		} else {
			m_sprite.setScale(4, 4);
		}
		m_sprite.setPosition(1000,300);
	}
	
}

void Player::Crouch() {
	if (!m_isCrouching) {
		m_isCrouching = true;
		m_isStanding = false;
		ChangeTexture(m_crouchTex);
		// Move the sprite 100 pixels downward when crouching
		m_sprite.setPosition(m_sprite.getPosition().x, m_sprite.getPosition().y + 100);
		
	}
}
void Player::StandUp() {
	if (!m_isStanding) {
		m_isStanding = true;
		m_isCrouching = false;
		ChangeTexture(m_normalTex);
		// Move the sprite 300 pixels downward when standing
		m_sprite.setPosition(m_sprite.getPosition().x, 300);
	}
}
