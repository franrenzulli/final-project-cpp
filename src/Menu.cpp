#include "Menu.h"
#include "Match.h"


Menu::Menu() {
	
	// Cargamos fondo, textos, fuentes, posicionamos
	m_f1.loadFromFile("../assets/fonts/arcade.ttf");
	
	m_t1.setFont(m_f1);
	m_t1.setFillColor(Color(255,255,255));
	m_t1.setString("Press ENTER to start playing");
	m_t1.setCharacterSize(20);
	m_t1.setPosition(90, 300);
	
	m_tex_background.loadFromFile("../assets/images/portada2.png");
	m_spr_background.setTexture(m_tex_background);
	m_spr_background.setScale(1, 1);
	
}

Menu::~Menu() {}

void Menu::ProcessEvents(Game &game, Event &event) { // Teclas para salir del programa o comenzar la pelea 
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {		
		game.Exit();
	}else if(event.type == Event::KeyPressed && event.key.code == Keyboard::Return){
		
		game.SetScene(new Match()); // Seteamos la escena de la pelea
		
	}
}

void Menu::Update(Game &game) {}

void Menu::Draw(RenderWindow &window) { // Mostramos los fondos y textos
    window.clear({0,0,0});
	window.draw(m_spr_background);
	window.draw(m_t1);
    window.display();
}
