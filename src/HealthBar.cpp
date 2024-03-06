#include "HealthBar.h"
#include "Player.h"

// Constructor
HealthBar::HealthBar(bool player1) : player_one(player1) {
	// Carga las texturas
	bg_tex.loadFromFile("assets/images/no_health.png");
	frame_tex.loadFromFile("assets/images/empty_health_bar.png");
	lifes_tex.loadFromFile("assets/images/health.png");
	
	// Setea las texturas en el sprite correspondiente
	bg_spr.setTexture(bg_tex);
	frame_spr.setTexture(frame_tex);
	lifes_spr.setTexture(lifes_tex);
	
	// Logica para escalar y ubicar los sprites
	Vector2f bar_position = {30, 30};
	Vector2f bar_origin = {0,0};

	bg_spr.setScale(4.25, 2.25);
	frame_spr.setScale(4.25, 2.25);
	lifes_spr.setScale(4.25, 2.25);

	
	/* origen arriba a la derecha,
	calculado segun el tamaño de la textura */
	
	if (!player_one) {
		bar_origin = {128, 0};     
		bar_position = {1250, 30}; 
	}
	
	
	// Setea el origen y ubica los sprites
	bg_spr.setOrigin(bar_origin);
	bg_spr.setPosition(bar_position);
	
	frame_spr.setOrigin(bar_origin);
	frame_spr.setPosition(bar_position);
	
	lifes_spr.setPosition(bar_position);
	lifes_spr.setOrigin(bar_origin);
}


void HealthBar::Draw(RenderWindow &window) {
	window.draw(bg_spr);
	window.draw(frame_spr);
	window.draw(lifes_spr);
}


void HealthBar::SetLifeTo(float lifesPercent) {
	// Corrige el porcentaje de salud
	if (lifesPercent < 0) {
		lifesPercent = 0;
	}
	if (lifesPercent > 100.0) {
		lifesPercent = 100.0;
	}
	
	Vector2f currentScale = lifes_spr.getScale();
	currentScale.x = 4.25;
	
	/* Modifica la escala (horizontal) del sprite de la salud del jugador
	(barra roja) en funcion del porcentaje de vida */
	
	Vector2f newScale = { currentScale.x * lifesPercent/100, currentScale.y };
	lifes_spr.setScale(newScale);
}
