// PickPlayer.cpp

#include "PickPlayer.h"
#include "Match.h"
#include "Menu.h"
#include <iostream>  // Include the iostream library


using namespace sf;

PickPlayer::PickPlayer() {
	// Constructor implementation
	m_tex_background.loadFromFile("assets/images/playerpicker.png");
	m_ryu.loadFromFile("assets/images/ryu-picker.jpeg");
	m_ken.loadFromFile("assets/images/ken-picker.jpeg");
	m_retsu.loadFromFile("assets/images/retsu-picker.jpeg");
	m_michael.loadFromFile("assets/images/michael-picker.jpeg");
	
	m_f1.loadFromFile("assets/fonts/arcade.ttf");
	
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


void PickPlayer::ProcessEvents(Game &game, Event &event) {
	if (event.type == Event::MouseButtonPressed) {
		Vector2f mousePos = Vector2f(Mouse::getPosition(game.GetWindow()));
		
		// botones de inicio
		FloatRect button1Bounds = button1.getGlobalBounds();
		FloatRect button2Bounds = button2.getGlobalBounds();
		
		// Verificar si el mouse está sobre las texturas y no sobre los botones
		FloatRect ryuBounds = ryu_sprite.getGlobalBounds();
		FloatRect kenBounds = ken_sprite.getGlobalBounds();
		FloatRect retsuBounds = retsu_sprite.getGlobalBounds();
		FloatRect michaelBounds = michael_sprite.getGlobalBounds();
		
		
		// Reset opacity 
		ryu_sprite.setColor(sf::Color(255, 255, 255, 255));
		ken_sprite.setColor(sf::Color(255, 255, 255, 255));
		retsu_sprite.setColor(sf::Color(255, 255, 255, 255));
		michael_sprite.setColor(sf::Color(255, 255, 255, 255));
		
		Color red(255, 0, 0, 200);
		Color blue(3, 74, 252, 200);	
		
		
		
		/* Cuando se presiona Click Izquierdo sobre la imagen de un personaje,
		este se seleccion para el Jugador 1 */
		
		// ***********************************
		if (ryuBounds.contains(mousePos) && Event::MouseButtonPressed) {
			if(event.mouseButton.button == Mouse::Left){
				player_one = "Ryu";
				selectedP1 = &ryu_sprite; 
			}else if(event.mouseButton.button == Mouse::Right) {
				player_two = "Ryu";
				selectedP2 = &ryu_sprite;
			}
			
		} else if (kenBounds.contains(mousePos)) {
			if(event.mouseButton.button == Mouse::Left){
				player_one = "Ken";
				selectedP1 = &ken_sprite;
			}else if(event.mouseButton.button == Mouse::Right) {
				player_two = "Ken";
				selectedP2 = &ken_sprite;
			}
			
		}else if (retsuBounds.contains(mousePos)) {
			if(event.mouseButton.button == Mouse::Left){
				player_one = "Retsu";
				selectedP1 = &retsu_sprite;
			}else if(event.mouseButton.button == Mouse::Right) {
				player_two = "Retsu";
				selectedP2 = &retsu_sprite;
			}
			
		}else if (michaelBounds.contains(mousePos)) {
			if(event.mouseButton.button == Mouse::Left){
				player_one = "Michael";
				selectedP1 = &michael_sprite;
			}else if(event.mouseButton.button == Mouse::Right) {
				player_two = "Michael";
				selectedP2 = &michael_sprite;
			}
			
		}
		// ***********************************
		
		/* Resalta con rojo al personaje seleccionado por el jugador 1
		y con azul al seleccionado por el jugador 2 */
		if (selectedP1 != nullptr)
			selectedP1->setColor(red);
		
		if (selectedP2 != nullptr)
			selectedP2->setColor(blue);
		
		
		if (button1Bounds.contains(mousePos)) {
			if(player_one != "" && player_two != ""){
				game.SetScene(new Match(player_one, player_two));
			}
		} else if (button2Bounds.contains(mousePos)) {
			game.SetScene(new Menu());
		}
	}
}

void PickPlayer::Update(Game &game) {
	// ...
}

void PickPlayer::Draw(sf::RenderWindow &window) {
	window.clear({0, 0, 0});
	window.draw(m_spr_background);
	
	// Dibuja los sprites y demas cosas
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
