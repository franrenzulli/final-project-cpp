#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "HealthBar.h"
#include "Chrono.h"

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
	
private:
	bool gameEnded;
	int winner;
	RectangleShape blackoutRect;
	
	Font m_f1;
	Text m_t1;
	Text m_t2;
	Texture m_tex_background;
	Texture m_tex_ground;
	Sprite m_spr_background;
	Sprite m_spr_ground;
	Player p1, p2;
	HealthBar hb_p1, hb_p2;
	
	int roundTime = 2;
	Chrono chrono = Chrono("../assets/fonts/Kanit.ttf", roundTime);
};
