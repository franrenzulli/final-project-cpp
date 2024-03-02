// PickPlayer.cpp

#include "PickPlayer.h"
#include "Match.h"
#include "Menu.h"

using namespace sf;

PickPlayer::PickPlayer() {
	// Constructor implementation
	m_tex_background.loadFromFile("../assets/images/playerpicker.png");
	m_ryu.loadFromFile("../assets/images/ryu-picker.jpeg");
	m_ken.loadFromFile("../assets/images/ken-picker.jpeg");
	m_retsu.loadFromFile("../assets/images/retsu-picker.jpeg");
	m_michael.loadFromFile("../assets/images/michael-picker.jpeg");
	
	m_f1.loadFromFile("../assets/fonts/arcade.ttf");
	
	m_spr_background.setTexture(m_tex_background);
	m_spr_background.setScale(1.4, 1.4);
	
	m_t1.setFont(m_f1);
	m_t1.setFillColor(Color(255, 255, 255));
	m_t1.setString("Start");
	m_t1.setCharacterSize(30);
	m_t1.setPosition(90, 300);
	
	m_t2.setFont(m_f1);
	m_t2.setFillColor(Color(255, 255, 255));
	m_t2.setString("Go back");
	m_t2.setCharacterSize(30);
	m_t2.setPosition(90, 400);
	
	button1.setSize(Vector2f(450, 50));
	button1.setFillColor(Color(212, 43, 43));
	button1.setPosition(60, 290);
	
	button2.setSize(Vector2f(450, 50));
	button2.setFillColor(Color(212, 43, 43));
	button2.setPosition(60, 390);
	
	// Create a sprite using the ryu texture
	ryu_sprite.setTexture(m_ryu);
	ryu_sprite.setPosition(600, 200);
	ryu_sprite.setScale(0.9, 0.9);

	// Create a sprite using the ken texture
	ken_sprite.setTexture(m_ken);
	ken_sprite.setPosition(850, 200);
	ken_sprite.setScale(0.9, 0.9);
	
	// Create a sprite using the retsu texture
	retsu_sprite.setTexture(m_retsu);
	retsu_sprite.setPosition(600, 450);
	retsu_sprite.setScale(0.9, 0.9);
	
	// Create a sprite using the michael texture
	michael_sprite.setTexture(m_michael);
	michael_sprite.setPosition(850, 450);
	michael_sprite.setScale(0.9, 0.9);
	
}


void PickPlayer::ProcessEvents(Game &game, sf::Event &event) {
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
		game.Exit();
	} else if (event.type == sf::Event::MouseButtonPressed) {
		Vector2f mousePos = Vector2f(Mouse::getPosition(game.GetWindow()));
		
		// botones de inicio
		FloatRect button1Bounds = button1.getGlobalBounds();
		FloatRect button2Bounds = button2.getGlobalBounds();
		
		// Verificar si el mouse está sobre las texturas y no sobre los botones
		FloatRect ryuBounds = ryu_sprite.getGlobalBounds();
		FloatRect kenBounds = ken_sprite.getGlobalBounds();
		FloatRect retsuBounds = retsu_sprite.getGlobalBounds();
		FloatRect michaelBounds = michael_sprite.getGlobalBounds();
		
		
		if (ryuBounds.contains(mousePos)) {
			ryu_sprite.setColor(sf::Color(255, 255, 255, 128));
		} else if (kenBounds.contains(mousePos)) {
			ken_sprite.setColor(sf::Color(255, 255, 255, 128));
		}else if (retsuBounds.contains(mousePos)) {
			retsu_sprite.setColor(sf::Color(255, 255, 255, 128));
		}else if (michaelBounds.contains(mousePos)) {
			michael_sprite.setColor(sf::Color(255, 255, 255, 128));
		}
		
		
		
		if (button1Bounds.contains(mousePos)) {
			ryu_sprite.setColor(sf::Color(255, 255, 255, 128));
			//game.SetScene(new Match());
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
	
	// Draw the ryu sprite
	window.draw(ryu_sprite);
	window.draw(ken_sprite);
	window.draw(retsu_sprite);
	window.draw(michael_sprite);
	
	window.draw(button1);
	window.draw(button2);
	window.draw(m_t1);
	window.draw(m_t2);
	window.display();
}
