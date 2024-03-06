#include "Chrono.h"
#include <sstream>
#include <SFML/System/Time.hpp>
#include <cmath>
#include <iostream>

// Constructor: recibe ruta de la fuente y el tiempo que descontara el cronometro en minutos
Chrono::Chrono(std::string fontPath, int timeMinutes) : minutes(timeMinutes-1) {
	/* ACLARACION: La variable minutes almacena los minutos de juego -1 
	para que el cronometro empiece en xx:59.
	ej: 5 minutos de juego --> cronometro inicia en 04:59 */
	
	
	// cargamos la fuente y ubicamos el texto
	font.loadFromFile(fontPath);
	
	// setea la fuente
	chronoText.setFont(font);
	chronoText.setString("00:00");
	chronoText.setFillColor(Color{204, 0, 0});
	chronoText.setCharacterSize(70);
	
	// posiciona el texto
	chronoText.setPosition((1280 - chronoText.getLocalBounds().width) /2, 620);
}


int Chrono::SecondsLeft() {
	/* convierte los minutos a segundos y los retorna como un entero
	minutes+1 por lo aclarado en el constructor. */
	return (minutes+1)*60 - std::round(clock.getElapsedTime().asSeconds());
}

void Chrono::Update() {
	std::stringstream timeString; // stream para ubicar y darle formato al texto del cronometro
	int elapsedTime = std::round(clock.getElapsedTime().asSeconds()); // segundos transcurridos
	int chronoMinutes = minutes - std::round(elapsedTime/60); // minutos que se escibiran en el cronometro
	int chronoSeconds = 59 - elapsedTime%60; // segundos que se escribiran en el cronometro
	
	
	// Logica para dar formato al tiempo restante ("mm:ss")
	if (chronoMinutes < 10) {
		timeString << "0" << chronoMinutes;
	} else {
		timeString << chronoMinutes;
	}
	timeString << ":";
	if (chronoSeconds < 10) {
		timeString << "0" << chronoSeconds;
	} else {
		timeString << chronoSeconds;
	}
	
	// setea el string formateado en chronoText
	chronoText.setString(timeString.str());
}

void Chrono::Draw(RenderWindow &window) {
	window.draw(chronoText);
}

void Chrono::Start() {
	clock.restart();
}
