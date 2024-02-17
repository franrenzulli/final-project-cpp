#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include "Object.h"

class Player;  // declaración anticipada

class HealthBar {
public:
	HealthBar(bool player1);
	void Draw(RenderWindow &window);
	void SetLifeTo(float lifesPercent);
private:
	Texture bg_tex, frame_tex, lifes_tex;
	Sprite bg_spr, frame_spr, lifes_spr;
	bool player_one;
};

#endif

/* 
La "declaración anticipada" es cuando declaras una entidad antes de proporcionar su definición completa.
Lo hicde para referenciar la clase, antes de que se defina completamente en el código. Es decir, era 
necesario para evitar problemas de dependencias circulares. Es decir que las entidades no dependan mutuamente una de la otra
*/
