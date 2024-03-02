#include <fstream>
#include <vector>

#include "Leaderboard.h"
#include "Match.h"
#include "Menu.h"


#include <cstring>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace sf;
using namespace std;

Leaderboard::Leaderboard(string fname, int winnerPoints, bool allowSaving) : m_filename(fname), m_winnerPoints(winnerPoints), allowSaving(allowSaving) {
	
	// Cargamos fondo, textos, fuentes, posicionamos
	m_f1.loadFromFile("../assets/fonts/arcade.ttf");
	
	button1.setSize(Vector2f(340,50));
	button1.setFillColor(Color(212,43,43)); 
	button1.setPosition(50,535);
	
	m_t1.setFont(m_f1);
	m_t1.setFillColor(Color(255,255,255));
	m_t1.setString("Leaderboard");
	m_t1.setCharacterSize(40);
	m_t1.setPosition(650, 100);
	
	m_t2.setFont(m_f1);
	m_t2.setFillColor(Color(255,255,255));
	m_t2.setCharacterSize(40);
	m_t2.setPosition(50, 350);	
	
	if(allowSaving){
		m_t3.setFont(m_f1);
		m_t3.setFillColor(Color(255,255,255));
		m_t3.setString("Write winner's name");
		m_t3.setCharacterSize(15);
		m_t3.setPosition(50, 300);
		
		m_t4.setFont(m_f1);
		m_t4.setFillColor(Color(255,255,255,0));
		m_t4.setString("Press ENTER to Save");
		m_t4.setCharacterSize(15);
		m_t4.setPosition(50, 425);
		
		m_t5.setFont(m_f1);
		m_t5.setFillColor(Color(255,255,255));
		m_t5.setString(to_string(winnerPoints) + " points");
		m_t5.setCharacterSize(15);
		m_t5.setPosition(50, 475);
	}
	
	m_t6.setFont(m_f1);
	m_t6.setFillColor(Color(255,255,255));
	m_t6.setString("Go back to menu");
	m_t6.setCharacterSize(20);
	m_t6.setPosition(70, 550);
	
	m_name.setFont(m_f1);
	m_name.setFillColor(Color(255,255,255));
	m_name.setCharacterSize(20);
	m_name.setPosition(650, 200);
	m_name.setString("name");
	
	m_points.setFont(m_f1);
	m_points.setFillColor(Color(255,255,255));
	m_points.setCharacterSize(20);
	m_points.setPosition(850, 200);
	m_points.setString("points");
	
	m_totalWins.setFont(m_f1);
	m_totalWins.setFillColor(Color(255,255,255));
	m_totalWins.setCharacterSize(20);
	m_totalWins.setPosition(1000, 200);
	m_totalWins.setString("total wins");
	
	
	
	m_tex_background.loadFromFile("../assets/images/portada3.png");
	m_spr_background.setTexture(m_tex_background);
	m_spr_background.setScale(1.1, 1.03);
	
	
	LoadDataFromFile(m_filename);
	m_scoreSaved = false;
}

Leaderboard::~Leaderboard() {
	SaveDataToFile(m_filename);
}

void Leaderboard::ProcessEvents(Game &game, Event &event) { 
	if ((event.type == Event::TextEntered) && allowSaving) { // Escribir tu nombre en la pantalla
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
			string input = currentInput;
			// Agregar manejo para la tecla Enter
			if (event.text.unicode == 13 && currentInput.length() > 0 && !m_scoreSaved) {
				auto it = find_if(m_leaders.begin(), m_leaders.end(), [input] (const PlayerData& p){
					return string(p.name) == input;
				});
				
				if (it == m_leaders.end()) {
					cout<<input<<": no encontrado"<<endl;
					// si no existe, agrega un nuevo jugador al leaderboard
					PlayerData newPlayer;
					strcpy(newPlayer.name, currentInput.c_str());
					newPlayer.score = m_winnerPoints;
					newPlayer.totalWins = 1;
					m_leaders.push_back(newPlayer);
					m_scoreSaved = true;
				} else {
					// sino, actualizar datos
					it->score += m_winnerPoints;
					it->totalWins++;
					m_scoreSaved = true;
				}
			}
		}
		// Hacer aparecer o desaparecer el texto de guardar
		if(currentInput.length() > 0){
			m_t4.setFillColor(Color(255,255,255,100));
		}else{
			m_t4.setFillColor(Color(255,255,255,0));
		}
	}else if(event.type == sf::Event::MouseButtonPressed){ // Volver al menu
		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(game.GetWindow())); 
		sf::FloatRect button1Bounds = button1.getGlobalBounds();
		
		if (button1Bounds.contains(mousePos)) {
			SaveDataToFile(m_filename);
			game.SetScene(new Menu());
		}
	}
}

void Leaderboard::Update(Game &game) {
	stringstream names, points, wins;
	names<<"NAMES"<<endl;
	points<<"POINTS"<<endl;
	wins<<"WINS"<<endl;
	
	for (auto& p : m_leaders) {
		names<<string(p.name)<<endl;
		points<<p.score<<endl;
		wins<<p.totalWins<<endl;
	}
	m_name.setString(names.str());
	m_points.setString(points.str());
	m_totalWins.setString(wins.str());
}
void Leaderboard::Draw(RenderWindow &window) { // Mostramos los fondos y textos
	window.clear({0,0,0});
	window.draw(m_spr_background);
	window.draw(button1);
	window.draw(m_t1);
	window.draw(m_t2);
	window.draw(m_t3);
	window.draw(m_t4);
	window.draw(m_t5);
	window.draw(m_t6);
	window.draw(m_name);
	window.draw(m_points);
	window.draw(m_totalWins);
	window.display();
}

void Leaderboard::SaveDataToFile(const string& filename) {
	ofstream file(filename, ios::binary);
	if (file.is_open()) {
		for (auto& p : m_leaders) {
			file.write(reinterpret_cast<char*>(&p), sizeof(p));
		}
		file.close();
	} else {
		cerr << "Error al abrir el archivo: " << filename << endl;
	}
}

void Leaderboard::LoadDataFromFile(const string& filename) {
	ifstream file(filename, ios::binary);
	PlayerData p;
	while (file.read(reinterpret_cast<char*>(&p), sizeof(p))) {
		m_leaders.push_back(p);
	}
}
