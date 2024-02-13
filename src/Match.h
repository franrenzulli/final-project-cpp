#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Scene.h"

class Match : public Scene {
public:
	Match();
	~Match();
	
	void ProcessEvents(Game &game, Event &event) override;
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
private:
	Font m_f1;
	Text m_t1;
	Texture m_tex_background;
	Texture m_tex_ground;
	Sprite m_spr_background;
	Sprite m_spr_ground;
};