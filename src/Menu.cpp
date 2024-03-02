#include "Menu.h"
#include "Match.h"
#include "Leaderboard.h"
#include "PickPlayer.h"
#include <iostream>


Menu::Menu() {
	
	// Cargamos fondo, textos, fuentes, posicionamos
	m_f1.loadFromFile("../assets/fonts/arcade.ttf");
	
	m_t1.setFont(m_f1);
	m_t1.setFillColor(Color(255,255,255));
	m_t1.setString("Start playing");
	m_t1.setCharacterSize(30);
	m_t1.setPosition(90, 300);

	
	m_t2.setFont(m_f1);
	m_t2.setFillColor(Color(255,255,255));
	m_t2.setString("See Leaderboard");
	m_t2.setCharacterSize(30);
	m_t2.setPosition(90, 400);
	
	m_tex_background.loadFromFile("../assets/images/portada2.png");
	m_spr_background.setTexture(m_tex_background);
	m_spr_background.setScale(1, 1);

	button1.setSize(Vector2f(450,50));
	button1.setFillColor(Color(212,43,43)); 
	button1.setPosition(60,290);
	
	button2.setSize(Vector2f(500,50));
	button2.setFillColor(Color(212,43,43)); 
	button2.setPosition(60,390);
	
}

Menu::~Menu() {}

void Menu::ProcessEvents(Game &game, Event &event) { // Teclas para salir del programa o comenzar la pelea 
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {		
		game.Exit();
	}else if(event.type == sf::Event::MouseButtonPressed){
		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(game.GetWindow())); 
		sf::FloatRect button1Bounds = button1.getGlobalBounds();
		sf::FloatRect button2Bounds = button2.getGlobalBounds();
		
		if (button1Bounds.contains(mousePos)) {
			//game.SetScene(new Match()); // Seteamos la escena de la pelea
			game.SetScene(new PickPlayer());
		}else if(button2Bounds.contains(mousePos)){
			game.SetScene(new Leaderboard("../leaderboard.dat", 6000, false));
		}
	
		
	}
}

void Menu::Update(Game &game) {}

void Menu::Draw(RenderWindow &window) { // Mostramos los fondos y textos
    window.clear({0,0,0});
	window.draw(m_spr_background);
	window.draw(button1);
	window.draw(button2);
	window.draw(m_t1);
	window.draw(m_t2);
    window.display();
}
