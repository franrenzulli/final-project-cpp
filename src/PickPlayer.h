// PickPlayer.h

#ifndef PICKPLAYER_H
#define PICKPLAYER_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Scene.h"
#include "Menu.h"

using namespace sf;

class PickPlayer : public Scene {
public:
	PickPlayer();
	~PickPlayer();
	void ProcessEvents(Game &game, sf::Event &event) override;
	void Update(Game &game) override;
	void Draw(sf::RenderWindow &window) override;
private:
	Texture m_tex_background;
	Texture m_tex_ground;
	Sprite m_spr_background;
	RectangleShape button1;
	RectangleShape button2;
	Text m_t1;
	Text m_t2;
	Font m_f1;
	
};

#endif
