#ifndef CHRONO_H
#define CHRONO_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

using namespace sf;

class Chrono {
public:
	Chrono(std::string fontPath, int timeMinutes);
	void Update();
	void Draw(RenderWindow &window);
	void Start();
	int SecondsLeft();
	
private:
	Clock clock;
	Font font;
	Text chronoText;
	int minutes;
};

#endif

