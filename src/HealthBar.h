#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include "Object.h"

class HealthBar {
public:
	HealthBar(bool player1);
	void Draw(RenderWindow &window);
	void SetLifeTo(int lifesNumber);
private:
	Texture bg_tex, frame_tex, lifes_tex;
	Sprite bg_spr, frame_spr, lifes_spr;
	bool player_one;
};

#endif

