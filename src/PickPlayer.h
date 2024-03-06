// PickPlayer.h

#ifndef PICKPLAYER_H
#define PICKPLAYER_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Scene.h"
#include "Menu.h"

using namespace sf;
using namespace std;

class PickPlayer : public Scene {
public:
	PickPlayer();
	~PickPlayer();
	void ProcessEvents(Game &game, sf::Event &event) override;
	void Update(Game &game) override;
	void Draw(sf::RenderWindow &window) override;
private:
	
	string player_one, player_two; // nombre del personaje de cada jugador
	
	Texture m_tex_background;
	Texture m_ryu;
	Texture m_ken;
	Texture m_retsu;
	Texture m_michael;
	
	Sprite m_spr_background;
	Sprite ryu_sprite;
	Sprite ken_sprite;
	Sprite retsu_sprite;
	Sprite michael_sprite;
	
	RectangleShape button1;
	RectangleShape button2;
	RectangleShape p1_selection;
	RectangleShape p2_selection;
	
	Text m_t1;
	Text m_t2;
	Font m_f1;
	
	// punteros a los sprites de los personajes seleccionados
	sf::Sprite *selectedP1 = nullptr; 
	sf::Sprite *selectedP2 = nullptr;
};

#endif
