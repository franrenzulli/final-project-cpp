#include "Chrono.h"
#include <sstream>
#include <SFML/System/Time.hpp>
#include <cmath>

Chrono::Chrono(std::string fontPath, int timeMinutes) : minutes(timeMinutes-1) {
	// cargamos la fuente y ubicamos el texto
	
	font.loadFromFile(fontPath);
	
	chronoText.setFont(font);
	chronoText.setString("00:00");
	chronoText.setFillColor(Color{204, 0, 0});
	chronoText.setCharacterSize(70);
	chronoText.setPosition((1280 - chronoText.getLocalBounds().width) /2, 620);
	
}


int Chrono::SecondsLeft() {
	return (minutes+1)*60 - std::round(clock.getElapsedTime().asSeconds());
}

void Chrono::Update() {
	std::stringstream timeString;
	int elapsedTime = std::round(clock.getElapsedTime().asSeconds());
	int chronoMinutes = minutes - std::round(elapsedTime/60);
	int chronoSeconds = 59 - elapsedTime%60;
	
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
	
	chronoText.setString(timeString.str());
}

void Chrono::Draw(RenderWindow &window) {
	window.draw(chronoText);
}

void Chrono::Start() {
	clock.restart();
}
