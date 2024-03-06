#pragma once

#include "Object.h"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class Player;  // declaración anticipada

class HealthBar {
public:
	HealthBar(bool player1);
	void Draw(RenderWindow &window);
	void SetLifeTo(float lifesPercent); // metodo principal de la barra de salud
private:
	Texture bg_tex, frame_tex, lifes_tex; // texturas fondo, marco, salud
	Sprite bg_spr, frame_spr, lifes_spr; // sprites necesarios
	bool player_one; // bandera de jugador 1
	
};

