#include "HealthBar.h"
#include <iostream>

HealthBar::HealthBar(bool player1) : player_one(player1) {
	bg_tex.loadFromFile("../assets/images/no_health.png");
	bg_spr.setTexture(bg_tex);
	
	frame_tex.loadFromFile("../assets/images/empty_health_bar.png");
	frame_spr.setTexture(frame_tex);
	
	lifes_tex.loadFromFile("../assets/images/life.png");
	lifes_spr.setTexture(lifes_tex);
	
	Vector2f bar_position = {30,40};
	Vector2f bar_origin = {0,0};

	bg_spr.setScale(2, 2.25);
	frame_spr.setScale(2, 2.25);
	lifes_spr.setScale(2, 2.25);

	if (!player_one) {
		bar_origin = {128, 0}; // set origin in top right corner
		bar_position = {1250,40};
		
		lifes_spr.setOrigin(32, 0);
	}
	
	bg_spr.setOrigin(bar_origin);
	bg_spr.setPosition(bar_position);
	
	frame_spr.setOrigin(bar_origin);
	frame_spr.setPosition(bar_position);
	
	lifes_spr.setPosition(bar_position);
}


void HealthBar::Draw(RenderWindow &window) {
	window.draw(bg_spr);
	window.draw(frame_spr);
	window.draw(lifes_spr);
}


void HealthBar::SetLifeTo(int lifesNumber) {
	if (lifesNumber < 0) {
		return;
	}
	Vector2f currentScale = lifes_spr.getScale();
	currentScale.x = 2; 
	
	Vector2f newScale = { currentScale.x * lifesNumber, currentScale.y };

	lifes_spr.setScale(newScale);
}
