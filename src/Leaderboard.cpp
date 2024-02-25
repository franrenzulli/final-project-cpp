#include <iostream>
#include <fstream>
#include <vector>

#include "Leaderboard.h"
#include "Match.h"
#include "Menu.h"


using namespace sf;
using namespace std;

Leaderboard::Leaderboard(int winnerPoints) {
	
	// Cargamos fondo, textos, fuentes, posicionamos
	m_f1.loadFromFile("../assets/fonts/arcade.ttf");
	
	m_t1.setFont(m_f1);
	m_t1.setFillColor(Color(255,255,255));
	m_t1.setString("Leaderboard");
	m_t1.setCharacterSize(40);
	m_t1.setPosition(650, 100);
	
	m_t2.setFont(m_f1);
	m_t2.setFillColor(Color(255,255,255));
	m_t2.setCharacterSize(40);
	m_t2.setPosition(50, 350);	
	
	m_t3.setFont(m_f1);
	m_t3.setFillColor(Color(255,255,255));
	m_t3.setString("Escriba el nombre del ganador");
	m_t3.setCharacterSize(15);
	m_t3.setPosition(50, 300);
	
	m_t4.setFont(m_f1);
	m_t4.setFillColor(Color(255,255,255,0));
	m_t4.setString("Presiona ENTER para guardar");
	m_t4.setCharacterSize(15);
	m_t4.setPosition(50, 425);
	
	m_t5.setFont(m_f1);
	m_t5.setFillColor(Color(255,255,255));
	m_t5.setString(to_string(winnerPoints) + " points");
	m_t5.setCharacterSize(15);
	m_t5.setPosition(50, 475);
	
	m_tex_background.loadFromFile("../assets/images/portada3.png");
	m_spr_background.setTexture(m_tex_background);
	m_spr_background.setScale(1.1, 1.03);
	
}

Leaderboard::~Leaderboard() {}

void Leaderboard::ProcessEvents(Game &game, Event &event) { // Volver al menu
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {		
		game.SetScene(new Menu());
	}else if (event.type == Event::TextEntered) { // Escribir tu nombre en la pantalla
		if (event.text.unicode < 128) {
			if (event.text.unicode == 8 && !currentInput.empty()) {
				// Retroceso: eliminar el último carácter
				currentInput.pop_back();
			} else if (event.text.unicode != 8 && currentInput.length() < 8) {
				
				// Agregar el carácter ingresado si no es el ENTER
				if(event.text.unicode != 13){
					currentInput += static_cast<char>(event.text.unicode);
				}
			}
			m_t2.setString(currentInput);
			
			// Agregar manejo para la tecla Enter
			if (event.text.unicode == 13 && currentInput.length() > 0) {
				// Guardar nombre y puntaje en las variables de la clase
				
				// Guardar en un archivo binario
				SaveDataToFile("leaderboard.bin", m_t2.getString().toAnsiString(), stoi(m_t5.getString().toAnsiString()));
				
			}
			
		}
		// Hacer aparecer o desaparecer el texto de guardar
		if(currentInput.length() > 0){
			m_t4.setFillColor(Color(255,255,255,100));
		}else{
			m_t4.setFillColor(Color(255,255,255,0));
		}
	}
}

void Leaderboard::Update(Game &game) {}

void Leaderboard::Draw(RenderWindow &window) { // Mostramos los fondos y textos
	window.clear({0,0,0});
	window.draw(m_spr_background);
	window.draw(m_t1);
	window.draw(m_t2);
	window.draw(m_t3);
	window.draw(m_t4);
	window.draw(m_t5);
	window.display();
}


void Leaderboard::SaveDataToFile(const string &filename, const string &name, int points) {
	ofstream file(filename, ios::binary | ios::app);
	
	if (file.is_open()) {
		// Guardar longitud del nombre
		size_t nameSize = name.size() + 1; // +1 para incluir el null-terminator
		file.write(reinterpret_cast<const char*>(&nameSize), sizeof(size_t));
		
		// Guardar nombre con null-terminator
		file.write(name.c_str(), nameSize);
		
		// Guardar puntos
		file.write(reinterpret_cast<const char*>(&points), sizeof(int));
		
		file.close();
	} else {
		cerr << "Error al abrir el archivo: " << filename << endl;
	}
}

