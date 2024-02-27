#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "HealthBar.h"
#include "Chrono.h"
#include <vector>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

class Match : public Scene { // Creamos escena Match
public:
	Match();
	~Match();
	
	void ProcessEvents(Game &game, Event &event) override;
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
	bool GetMatchStatus(){
		return this->gameEnded;
	};
	void StartNextRound();
	
private:
	bool gameEnded;
	
	RectangleShape blackoutRect;
	RectangleShape leaderboardRect;
	RectangleShape menuRect;
	Font m_f1;
	Text m_t1;
	Text m_t2;
	Text m_roundWinnerText;
	Text m_scoresP1, m_scoresP2;
	Texture m_tex_background;
	Texture m_tex_ground;
	Sprite m_spr_background;
	Sprite m_spr_ground;
	Player p1, p2;
	HealthBar hb_p1, hb_p2;
	SoundBuffer m_gameStartSoundBuff;
	Sound m_gameStartSound;
	
	int m_roundTime = 2;
	int m_totalRounds = 3;
	int m_currentRound = 1;
	
	// indica el ganador definitivo
	int winner = 0;
	int winnerPoints;
	
	sf::Clock m_clock;
	bool wasClockAlreadyRestarted = false;
	
	Chrono chrono = Chrono("../assets/fonts/Kanit.ttf", m_roundTime);
};
