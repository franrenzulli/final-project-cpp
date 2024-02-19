#include "Leaderboard.h"
#include "Match.h"
#include "Menu.h"
#include <iostream>

Leaderboard::Leaderboard() {
	
	// Cargamos fondo, textos, fuentes, posicionamos
	m_f1.loadFromFile("../assets/fonts/arcade.ttf");
	
	m_t1.setFont(m_f1);
	m_t1.setFillColor(Color(255,255,255));
	m_t1.setString("Leaderboard");
	m_t1.setCharacterSize(40);
	m_t1.setPosition(600, 100);
	
	m_tex_background.loadFromFile("../assets/images/portada3.png");
	m_spr_background.setTexture(m_tex_background);
	m_spr_background.setScale(1.1, 1.03);
	
}

Leaderboard::~Leaderboard() {}

void Leaderboard::ProcessEvents(Game &game, Event &event) { // Volver al menu
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {		
		game.SetScene(new Menu());
	}
}

void Leaderboard::Update(Game &game) {}

void Leaderboard::Draw(RenderWindow &window) { // Mostramos los fondos y textos
	window.clear({0,0,0});
	window.draw(m_spr_background);
	window.draw(m_t1);
	window.display();
}


