#include <fstream>
#include <vector>

#include "Instructions.h"
#include "Match.h"
#include "Menu.h"

#include <cstring>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace sf;
using namespace std;

Instructions::Instructions() {
	
	// Cargamos fondo, textos, fuentes, posicionamos
	m_f1.loadFromFile("assets/fonts/arcade.ttf");
	
	button1.setSize(Vector2f(340,50));
	button1.setFillColor(Color(212,43,43)); 
	button1.setPosition(50,535);
	
	m_t1.setFont(m_f1);
	m_t1.setFillColor(Color(255,255,255));
	m_t1.setString("How to play");
	m_t1.setCharacterSize(40);
	m_t1.setPosition(650, 100);
	
	m_t2.setFont(m_f1);
	m_t2.setFillColor(Color(255,255,255));
	m_t2.setString("Movements");
	m_t2.setCharacterSize(30);
	m_t2.setPosition(720, 170);	
	
	m_t3.setFont(m_f1);
	m_t3.setFillColor(Color(255,255,255));
	m_t3.setString("Player 1 ¦ Player 2");
	m_t3.setCharacterSize(20);
	m_t3.setPosition(670, 260);	
	
	m_t4.setFont(m_f1);
	m_t4.setFillColor(Color(255,255,255));
	m_t4.setString("MOVE: WASD ¦ Arrows");
	m_t4.setCharacterSize(20);
	m_t4.setPosition(670, 320);	
	
	m_t5.setFont(m_f1);
	m_t5.setFillColor(Color(255,255,255));
	m_t5.setString("KICK: F ¦ K");
	m_t5.setCharacterSize(20);
	m_t5.setPosition(670, 380);	
	
	m_t6.setFont(m_f1);
	m_t6.setFillColor(Color(255,255,255));
	m_t6.setString("Go back to menu");
	m_t6.setCharacterSize(20);
	m_t6.setPosition(70, 550);
	
	m_t7.setFont(m_f1);
	m_t7.setFillColor(Color(255,255,255));
	m_t7.setString("HADUKEN: Space ¦ I");
	m_t7.setCharacterSize(20);
	m_t7.setPosition(670, 440);	
	
	m_t8.setFont(m_f1);
	m_t8.setFillColor(Color(255,255,255));
	m_t8.setString("Special Attacks have a 3 second cooldown!");
	m_t8.setCharacterSize(15);
	m_t8.setPosition(550, 550);	
	
	m_t9.setFont(m_f1);
	m_t9.setFillColor(Color(255,255,255));
	m_t9.setString("The best out of 3 rounds wins the match!");
	m_t9.setCharacterSize(15);
	m_t9.setPosition(550, 600);
	
	m_t10.setFont(m_f1);
	m_t10.setFillColor(Color(255,255,255));
	m_t10.setString("How to select players (mouse)");
	m_t10.setCharacterSize(15);
	m_t10.setPosition(70, 400);
	
	m_t11.setFont(m_f1);
	m_t11.setFillColor(Color(255,255,255));
	m_t11.setString("Left Click ¦ Right Click");
	m_t11.setCharacterSize(15);
	m_t11.setPosition(70, 450);
	
	m_tex_background.loadFromFile("assets/images/portada3.png");
	m_spr_background.setTexture(m_tex_background);
	m_spr_background.setScale(1.1, 1.03);
	
}

Instructions::~Instructions() {
	
}

void Instructions::ProcessEvents(Game &game, Event &event) { 
	if(event.type == sf::Event::MouseButtonPressed){ // Volver al menu
		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(game.GetWindow())); 
		sf::FloatRect button1Bounds = button1.getGlobalBounds();
		
		if (button1Bounds.contains(mousePos)) {
			game.SetScene(new Menu());
		}
	}
}

void Instructions::Update(Game &game) {
	
}
void Instructions::Draw(RenderWindow &window) { // Mostramos los fondos y textos
	window.clear({0,0,0});
	window.draw(m_spr_background);
	window.draw(button1);
	window.draw(m_t1);
	window.draw(m_t2);
	window.draw(m_t3);
	window.draw(m_t4);
	window.draw(m_t5);
	window.draw(m_t6);
	window.draw(m_t7);
	window.draw(m_t8);
	window.draw(m_t9);
	window.draw(m_t10);
	window.draw(m_t11);
	window.display();
}


