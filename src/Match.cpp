#include "Match.h"
#include "Menu.h"
#include <iostream>

Match::Match() : p1(true), p2(false), hb_p1(true), hb_p2(false) {
	
	// Cargamos fondo, textos, fuentes, suelo y posicionamos
	m_f1.loadFromFile("../assets/fonts/Kanit.ttf");
	
	m_t1.setFont(m_f1);
	m_t1.setFillColor(Color(204, 0, 0));
	m_t1.setString("Fight!");
	m_t1.setCharacterSize(50);
	m_t1.setPosition((1280 - m_t1.getLocalBounds().width)/2, 10);
	
	m_t2.setFont(m_f1);
	m_t2.setFillColor(Color(255, 255, 255));
	m_t2.setString("Press ESCAPE to go back to the menu");
	m_t2.setCharacterSize(25);
	m_t2.setPosition(10,680);
	
	m_tex_background.loadFromFile("../assets/images/fondomatch.png");
	m_tex_ground.loadFromFile("../assets/images/cobblestoneground.png");
	
	m_spr_background.setTexture(m_tex_background);
	m_spr_ground.setTexture(m_tex_ground);
	m_spr_background.setScale(2.5, 2);
	m_spr_ground.setScale(1, 1);
	
	m_spr_ground.setPosition(0,625);
	
}

Match::~Match() {}

void Match::ProcessEvents(Game &game, Event &event) { // Habilitamos el cierre del juego con el boton ESCAPE
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {		
		game.SetScene(new Menu());
	}
}
void Match::Update(Game &game) { // Habilitamos que los jugadores puedan moverse y atacar
	p1.Update(true);
	p2.Update(false);
	hb_p1.SetLifeTo(p1.GetLifes()); // La barra de salud se actualiza con el valor de player.GetLifes()
	hb_p2.SetLifeTo(p2.GetLifes());
}

void Match::Draw(RenderWindow &window) { // Muestra en la nueva escena el fondo, textos y los jugadores
	window.clear({0,0,0});
	window.draw(m_spr_background);
	window.draw(m_spr_ground);
	window.draw(m_t1);
	window.draw(m_t2);
	
	p1.Draw(window);
	p2.Draw(window);
	hb_p1.Draw(window);
	hb_p2.Draw(window);
	
	window.display();
}
