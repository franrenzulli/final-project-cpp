#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
#include "Scene.h"

using namespace std;

class Instructions : public Scene { // Creamos la escena Instructions
public:
	Instructions();
	~Instructions();
	
	void ProcessEvents(Game &game, Event &event) override;
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
	
private:
	Font m_f1;
	Text m_t1;
	Text m_t2; // Texto donde se escribira el nombre 
	Text m_t3;
	Text m_t4;
	Text m_t5; // Texto donde se escribiran los puntos
	Text m_t6;
	Text m_t7;
	Text m_t8;
	Text m_t9;
	RectangleShape button1;
	Texture m_tex_background;
	Sprite m_spr_background;	
};

