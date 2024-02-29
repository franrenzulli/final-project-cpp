#ifndef PLAYER_H
#define PLAYER_H
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
	Player(bool player_one, Texture &tex);
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
private:
	bool player_one; // Indica si es el jugador 1 o el 2 
	Keyboard::Key m_up, m_right, m_down, m_left, m_attackBasic;// Teclas
	
	// texturas del jugador
	Texture m_normalTex, m_jumpTex, m_basicAtkTex;
	
	// texturas miscelaneas
	Texture m_fireballTex;
	
	bool m_isJumping;
	bool m_wasAttackPressed;
	bool m_wasSpecialAttackPressed;
	float m_jumpSpeed;
	float life_percent = 100.0;
	int m_score = 0;
	int m_roundsWon = 0;
	sf::Clock m_clock; // para cambiar las texturas despues de cierto tiempo
	vector<Fireball> fireballs;
	sf::Time m_deltaTime;
	bool m_texWasChangedOnBasicAttack = false;
	
	SoundBuffer m_kickSoundBuff, m_jumpSoundBuff, m_fireballSoundBuff;
	Sound m_jumpSound, m_kickSound, m_fireballSound;
};

#endif

