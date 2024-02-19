#ifndef PLAYER_H
#define PLAYER_H
#include "Object.h"
#include "Fireball.h"
#include <SFML/Window/Keyboard.hpp>
#include<vector>
#include "Attack.h"
#include <map>

using namespace sf;
using namespace std;

class HealthBar;  // declaración anticipada
class Attack;

class Player : public Object{
public:
	Player(bool player_one);
	void Update(Player& opponent);
	void SetLife(float perc);
	float GetLife();
	
	// ataques
	bool basicAttack(Player& opponent);
	void SpecialAttack(Player& opponent);
	vector<Fireball>& GetFireballs();
	
	bool CheckCollision(const Player& other) const;
	void SetDeltaTime(sf::Time deltaTime);
	void ValidateScreenLimits();
private:
	bool player_one; // Indica si es el jugador 1 o el 2 
	Keyboard::Key m_up, m_right, m_down, m_left, m_attackBasic;// Teclas
	bool m_isJumping;
	bool m_wasAttackPressed;
	bool m_wasSpecialAttackPressed;
	float m_jumpSpeed;
	float life_percent = 100.0;
	
	vector<Fireball> fireballs;
	sf::Time m_deltaTime;
};

#endif

