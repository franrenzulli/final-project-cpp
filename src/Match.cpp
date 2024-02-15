#include "Match.h"
#include <iostream>


Match::Match() : p1(true), p2(false){
	
	// Cargamos fondo, textos, fuentes, posicionamos
	m_f1.loadFromFile("../assets/fonts/Kanit.ttf");
	
	m_t1.setFont(m_f1);
	m_t1.setFillColor(Color(204, 0, 0));
	
	m_t1.setString("Fight!");
	m_t1.setCharacterSize(50);
	
	m_t1.setPosition((1280 - m_t1.getLocalBounds().width)/2, 10);
	
	m_tex_background.loadFromFile("../assets/images/fondomatch.png");
	m_tex_ground.loadFromFile("../assets/images/cobblestoneground.png");
	
	m_spr_background.setTexture(m_tex_background);
	m_spr_ground.setTexture(m_tex_ground);
	m_spr_background.setScale(2.5, 2);
	m_spr_ground.setScale(1, 1);
	
	m_spr_ground.setPosition(0,625);
	
	// Players
	
	
}

Match::~Match() {}


void Match::ProcessEvents(Game &game, Event &event) {
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {		
		game.Exit();
	}else if(event.type == Event::KeyPressed && event.key.code == Keyboard::Return){
		// 
		game.Exit();
	}
}
void Match::Update(Game &game) {
	p1.Update();
	p2.Update();
}

void Match::Draw(RenderWindow &window) {
	window.clear({0,0,0});
	window.draw(m_spr_background);
	window.draw(m_spr_ground);
	window.draw(m_t1);
	p1.Draw(window);
	p2.Draw(window);	
	window.display();
}
