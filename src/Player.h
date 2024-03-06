#pragma once

#include "Object.h"
#include "Fireball.h"
#include <SFML/Window/Keyboard.hpp>
#include<vector>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Texture.hpp>

using namespace sf;
using namespace std;

class HealthBar;  // Declaración anticipada
class Attack;

class Player : public Object{
public:
	Player(bool player_one, string name, Texture &tex);
	void Update(Player& opponent);
	void SetLife(float perc);
	float GetLife();
	void restart(bool player_one);
	
	// Ataques
	void BasicAttack(Player& opponent);
	void SpecialAttack(Player& opponent);
	
	vector<Fireball>& GetFireballs();
	
	bool CheckCollision(const Player& other) const;
	void SetDeltaTime(sf::Time deltaTime);
	void ValidateScreenLimits();
	void Crouch();
	void StandUp();
	void WonARound() {
		m_roundsWon++;
	}
	int GetRoundsWon() const {
		return m_roundsWon;
	}
	string GetScoreStr();
	int GetScore() {
		return m_score;
	}
	bool CanUseSpecialAttack() const {
		return m_canUseSpecialAttack;
	}
private:
	bool player_one; // Indica si es el jugador 1 o el 2
	string m_name;
	Keyboard::Key m_up, m_right, m_down, m_left, m_attackBasic;// Teclas
	
	// texturas del jugador
	Texture m_normalTex, m_jumpTex, m_basicAtkTex, m_crouchTex;
	
	// texturas miscelaneas
	Texture m_fireballTex;
	
	SoundBuffer m_kickSoundBuff, m_jumpSoundBuff, m_fireballSoundBuff;
	Sound m_soundEffect;
	
	bool m_isJumping;
	bool m_isCrouching;
	bool m_isStanding;
	bool m_wasAttackPressed;
	int m_basicAttackDeployed; // segundos del momento en que se desplego el ataque
	
	bool m_wasSpecialAttackPressed;
	bool m_canUseSpecialAttack = false;
	int m_recoveryTime; // para el SpecialAttack
	int m_specialAttackDeployed = 0; // segundos del momento en que se desplego el ataque
	float m_jumpSpeed;
	float life_percent = 100.0;
	int m_score = 0;
	int m_roundsWon = 0;
	Clock m_clock; 
	vector<Fireball> fireballs;
	Time m_deltaTime;
	bool m_texWasChangedOnBasicAttack = false;
};

