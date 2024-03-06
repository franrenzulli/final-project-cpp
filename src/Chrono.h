#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

using namespace sf;

class Chrono {
public:
	Chrono();
	Chrono(int timeMinutes);
	void Update();
	void Draw(RenderWindow &window);
	void Start();
	int SecondsLeft();
	
private:
	Clock clock;
	Font font;
	Text chronoText;
	int minutes;
	/*La variable minutes almacena los minutos de juego -1 
	para que el cronometro empiece en xx:59.
	ej: 5 minutos de juego --> cronometro inicia en 04:59*/
};
