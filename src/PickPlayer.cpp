// PickPlayer.cpp

#include "PickPlayer.h"
#include "Match.h"
#include "Menu.h"

PickPlayer::PickPlayer() {
	// Constructor implementation
	m_tex_background.loadFromFile("../assets/images/playerpicker.png");
	m_f1.loadFromFile("../assets/fonts/arcade.ttf");
	
	m_spr_background.setTexture(m_tex_background);
	m_spr_background.setScale(1.4, 1.4);

	m_t1.setFont(m_f1);
	m_t1.setFillColor(Color(255,255,255));
	m_t1.setString("Start");
	m_t1.setCharacterSize(30);
	m_t1.setPosition(90, 300);
	
	
	m_t2.setFont(m_f1);
	m_t2.setFillColor(Color(255,255,255));
	m_t2.setString("Go back");
	m_t2.setCharacterSize(30);
	m_t2.setPosition(90, 400);
	
	button1.setSize(Vector2f(450,50));
	button1.setFillColor(Color(212,43,43)); 
	button1.setPosition(60,290);
	
	button2.setSize(Vector2f(450,50));
	button2.setFillColor(Color(212,43,43)); 
	button2.setPosition(60,390);
}

void PickPlayer::ProcessEvents(Game &game, sf::Event &event) {
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
		game.Exit();
	} else if (event.type == sf::Event::MouseButtonPressed) {
		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(game.GetWindow()));
		sf::FloatRect button1Bounds = button1.getGlobalBounds();
		sf::FloatRect button2Bounds = button2.getGlobalBounds();
		
		if (button1Bounds.contains(mousePos)) {
			game.SetScene(new Match());
		} else if (button2Bounds.contains(mousePos)) {
			game.SetScene(new Menu());
		}
	}
}

void PickPlayer::Update(Game &game) {
	// Update implementation (if needed)
}

void PickPlayer::Draw(sf::RenderWindow &window) {
	window.clear({0, 0, 0});
	window.draw(m_spr_background);
	window.draw(button1);
	window.draw(button2);
	window.draw(m_t1);
	window.draw(m_t2);
	window.display();
}
