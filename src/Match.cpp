#include "Match.h"
#include "Menu.h"
#include "Leaderboard.h"
#include <sstream>
#include <SFML/Window/Keyboard.hpp>
#include "Player.h"

using namespace std;


Match::Match() : hb_p1(true), hb_p2(false) {
	// Cargamos fondo, textos, fuentes, suelo y posicionamos
	m_playerOneTex.loadFromFile("../assets/images/ken.png");
	m_playerTwoTex.loadFromFile("../assets/images/ryu.png");
	
	p1 = Player(true, m_playerOneTex);
	p2 = Player(false, m_playerTwoTex);
	
	m_f1.loadFromFile("../assets/fonts/arcade.ttf");
	m_t1.setFont(m_f1);
	m_t1.setFillColor(Color(204, 0, 0));
	m_t1.setString("Fight!");
	m_t1.setCharacterSize(20);
	m_t1.setPosition((1280 - m_t1.getLocalBounds().width)/2, 40);
	
	m_t2.setFont(m_f1);
	m_t2.setFillColor(Color(255, 255, 255));
	m_t2.setString("Press ESCAPE to go back to the menu");
	m_t2.setCharacterSize(13);
	m_t2.setPosition(10,690);
	
	m_tex_background.loadFromFile("../assets/images/fondomatch.png");
	m_tex_ground.loadFromFile("../assets/images/cobblestoneground.png");
	
	m_spr_background.setTexture(m_tex_background);
	m_spr_ground.setTexture(m_tex_ground);
	m_spr_background.setScale(2.5, 2);
	m_spr_ground.setScale(1, 1);
	
	m_spr_ground.setPosition(0,625);
	
	gameEnded = false;
	winner = 0; 
	
	m_scoresP1.setFont(m_f1);
	m_scoresP1.setCharacterSize(40);
	m_scoresP1.setFillColor(Color(120, 120, 120));
	m_scoresP1.setPosition(400,70);
	
	m_scoresP2.setFont(m_f1);
	m_scoresP2.setCharacterSize(40);
	m_scoresP2.setFillColor(Color(120, 120, 120));
	m_scoresP2.setPosition(720, 70);
	
	
	blackoutRect.setSize(Vector2f(1280, 720));  // Ajusta el tamaño según la resolución de tu ventana
	blackoutRect.setFillColor(Color(0, 0, 0, 0)); // Empieza con el rectángulo transparente
	leaderboardRect.setSize(Vector2f(430, 60)); 
	leaderboardRect.setFillColor(Color(0, 0, 0, 0)); 
	menuRect.setSize(Vector2f(480,50));
	menuRect.setFillColor(Color(212,43,43)); 
	menuRect.setPosition(0,670);
	
	m_gameStartSoundBuff.loadFromFile("../assets/sounds/game_start.wav");
	
	chrono.Start(); // Empieza el cronometro
	m_soundEffect.setBuffer(m_gameStartSoundBuff);
	m_soundEffect.play();
}


Match::~Match() {}

void Match::ProcessEvents(Game &game, Event &event) { // Habilitamos el cierre del juego con el boton ESCAPE
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {		
		game.SetScene(new Menu());
	}else if(event.type == Event::KeyPressed && event.key.code == Keyboard::Return && gameEnded){
		game.SetScene(new Leaderboard("../leaderboard.dat", winnerPoints)); // Seteamos la escena del leaderboard
		
	}
}
void Match::Update(Game &game) {
	// setea los contadores de puntos
	m_scoresP1.setString(p1.GetScoreStr());
	m_scoresP2.setString(p2.GetScoreStr());
	
	// Termina el juego cuando no quedan mas rounds
	if (m_currentRound > m_totalRounds) {
		gameEnded = true;
	}
	
	/* 
	En caso de terminarse el tiempo, la partida termina
	solo si no quedan rounds por pelear
	*/
	if (chrono.SecondsLeft() == 0 && m_currentRound > m_totalRounds) {
		gameEnded = true;
		winner = (p1.GetScore() < p2.GetScore()) ? 2 : 1;
			
		// Cambiar la opacidad del rectángulo
		blackoutRect.setFillColor(Color(0, 0, 0, 128));  // *****ESTO HACE ALGO???******
		
		return;
	}
	
	/* Si muere algun jugador o se termina el tiempo del cronometro, 
	y todavia quedan rounds por pelear*/
	if ((p1.GetLife() <= 0 || p2.GetLife() <= 0 || chrono.SecondsLeft() == 0) && m_currentRound <= m_totalRounds) {
		if (!wasClockAlreadyRestarted) {
			m_clock.restart();	
			wasClockAlreadyRestarted = true;
		}
		
		// guarda al ganador del round
		int roundWinner;
		
		if (p1.GetLife() > p2.GetLife()) {
			p1.WonARound();
			roundWinner = 1;
		} else if (p2.GetLife() > p1.GetLife()){
			p2.WonARound();
			roundWinner = 2;
		} else {
			roundWinner = 0;
		}
		
		if (m_clock.getElapsedTime().asSeconds() < 7) {
			// elimina todas las bolas de fuego que pueda haber
			p1.GetFireballs().clear();
			p2.GetFireballs().clear();
			// Cambiar la opacidad del rectángulo
			blackoutRect.setFillColor(Color(0, 0, 0, 128)); 
			//stringstream roundWinnerMsg;
			
			if (roundWinner != 0){
				// TODO: IMPROVE
				//roundWinnerMsg<<"Player "<<roundWinner<<"Won the round #"<<m_currentRound<<"!";
				
				if(Keyboard::isKeyPressed(Keyboard::Return)){
					StartNextRound();
					m_roundWinnerText.setString("");
				}
			} else
				//roundWinnerMsg<<"It was a tie!";
			m_roundWinnerText.setCharacterSize(50);
			//m_roundWinnerText.setString(roundWinnerMsg.str());
			m_roundWinnerText.setFont(m_f1);
			m_roundWinnerText.setFillColor(Color(204, 0, 0));
			m_roundWinnerText.setPosition((1280 - m_roundWinnerText.getLocalBounds().width) / 2, 300);
		} else {
			StartNextRound();
			wasClockAlreadyRestarted = false;
			m_roundWinnerText.setString("");
			blackoutRect.setFillColor(Color(0, 0, 0, 0)); 
		}
	}
	
	
	if (gameEnded) {
		// Elimina las bolas de fuego al terminar el juego
		p1.GetFireballs().clear();
		p2.GetFireballs().clear();
		return;
	}

	if (chrono.SecondsLeft() > 0) {
		chrono.Update(); // Actualiza el cronometro
		
		p1.Update(p2);  // El Jugador 1 se actualiza con el Jugador 2 como oponente
		p2.Update(p1);  // El Jugador 2 se actualiza con el Jugador 1 como oponente
		
		hb_p1.SetLifeTo(p1.GetLife());  // Actualiza la barra de salud del Jugador 1 según su vida
		hb_p2.SetLifeTo(p2.GetLife());  // Actualiza la barra de salud del Jugador 2 según su vidas
	}
}

void Match::Draw(RenderWindow &window) { // Muestra en la nueva escena el fondo, textos y los jugadores
	
	window.clear({0,0,0});
	window.draw(m_spr_background);
	window.draw(m_spr_ground);
	window.draw(menuRect);
	window.draw(m_t1);
	window.draw(m_t2);
	p1.Draw(window);
	p2.Draw(window);
	hb_p1.Draw(window);
	hb_p2.Draw(window);
	chrono.Draw(window);
	window.draw(m_scoresP1);
	window.draw(m_scoresP2);
	
	
	// Dibujar las bolas de fuego del jugador 1
	for (const auto& fireball : p1.GetFireballs()) {
		fireball.Draw(window);
	}
	
	// Dibujar las bolas de fuego del jugador 2
	for (const auto& fireball : p2.GetFireballs()) {
		fireball.Draw(window);
	}
	
	// Centrar el mensaje en la pantalla de que el juego termino
	if (gameEnded) {
		blackoutRect.setFillColor(Color(0, 0, 0, 128));
		Text winnerText;
		winnerText.setFont(m_f1);
		winnerText.setFillColor(Color(255, 255, 255));
		winnerText.setCharacterSize(40);
		
		
		// LOGICA PARA GUARDAR EL GANADOR.
		if (winner != 0) {
			winnerText.setString("Player " + to_string(winner) + " has won the match!");
		} else {
			// Determinar el jugador que gano mas rounds
			if (p1.GetRoundsWon() > p2.GetRoundsWon()) {
				winner = 1;
				winnerPoints = p1.GetScore();
			} else if (p2.GetRoundsWon() > p1.GetRoundsWon()) {
				winner = 2;
				winnerPoints = p2.GetScore();
			}
			
			if (winner != 0) {
				winnerText.setString("Player " + to_string(winner) + " has won the match!");
			} else {
				winnerText.setString("It's a tie!");
			}
		}
		
		winnerText.setPosition((1280 - winnerText.getLocalBounds().width) / 2, 300);
		
		
		leaderboardRect.setFillColor(Color(212,43,43));
		leaderboardRect.setPosition((1280 - leaderboardRect.getLocalBounds().width) / 2, 390);
		
		sf::Text buttonText;
		buttonText.setFont(m_f1);
		buttonText.setFillColor(Color(255, 255, 255));
		buttonText.setCharacterSize(15);
		buttonText.setString("Press ENTER to save score");
		buttonText.setPosition((1280 - buttonText.getLocalBounds().width) / 2, 410);
		
		window.draw(blackoutRect);
		window.draw(winnerText);
		window.draw(leaderboardRect);
		window.draw(buttonText);
	}
	window.draw(blackoutRect);
	window.draw(m_roundWinnerText);
	window.display();
}

void Match::StartNextRound() { // Al comenzar nuevo round	
	m_currentRound++; // Pasamos al siguiente round
	chrono.Start(); // Empieza el cronometro
	p1.SetLife(100.0f); // Actualizamos vida 
	p2.SetLife(100.0f);
	p1.restart(true); // Ponemos a los jugadores en su posicion inicial
	p2.restart(false);
	
	// Borrar el mensaje 
	m_roundWinnerText.setString("");
	blackoutRect.setFillColor(Color(0, 0, 0, 0));
	
	// Permitir que los jugadores se muevan

}
